#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client {
    int   id;
    char* msg_buf;  // Buffer for partial messages (for receiving)
} t_client;

int      max_fd  = 0;
int      next_id = 0;
t_client clients[1024];
char     send_buf[200000];  // Buffer for messages to broadcast

void fatal_error(void)
{
    write(2, "Fatal error\n", 12);
    exit(1);
}

void send_to_all_except(int except_fd, char* msg)
{
    for (int fd = 0; fd <= max_fd; fd++)
    {
        if (fd != except_fd && clients[fd].id != -1)
        {
            send(fd, msg, strlen(msg), 0);
        }
    }
}

void broadcast_message(int sender_fd, char* str)
{
    int len   = strlen(str);
    int start = 0;

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == '\n' || str[i] == '\0')
        {
            // Prepare message with "client X: " prefix
            sprintf(send_buf, "client %d: ", clients[sender_fd].id);
            int prefix_len = strlen(send_buf);

            // Copy the line
            int line_len = i - start;
            strncpy(send_buf + prefix_len, str + start, line_len);
            send_buf[prefix_len + line_len]     = '\n';
            send_buf[prefix_len + line_len + 1] = '\0';

            // Send to all other clients
            send_to_all_except(sender_fd, send_buf);

            start = i + 1;

            if (str[i] == '\0')
                break;
        }
    }
}

void client_disconnect(int fd)
{
    sprintf(send_buf, "server: client %d just left\n", clients[fd].id);
    send_to_all_except(fd, send_buf);

    if (clients[fd].msg_buf)
        free(clients[fd].msg_buf);
    clients[fd].msg_buf = NULL;
    clients[fd].id      = -1;
    close(fd);
}

void accept_new_client(int sockfd)
{
    struct sockaddr_in cli_addr;
    socklen_t          addr_len = sizeof(cli_addr);

    int client_fd = accept(sockfd, (struct sockaddr*) &cli_addr, &addr_len);
    if (client_fd < 0)
        fatal_error();

    if (client_fd > max_fd)
        max_fd = client_fd;

    clients[client_fd].id      = next_id;
    clients[client_fd].msg_buf = NULL;

    sprintf(send_buf, "server: client %d just arrived\n", next_id);
    send_to_all_except(client_fd, send_buf);

    next_id++;

    printf("Client %d connected!\n", next_id);  // Add this line
    sprintf(send_buf, "server: client %d just arrived\n", next_id);
}

void handle_client_message(int fd)
{
    char buf[1024];
    int  bytes = recv(fd, buf, sizeof(buf), 0);

    if (bytes <= 0)
    {
        client_disconnect(fd);
        return;
    }

    buf[bytes] = '\0';

    // Append to existing buffer
    char* old_buf = clients[fd].msg_buf;
    if (old_buf == NULL)
    {
        clients[fd].msg_buf = strdup(buf);
        if (!clients[fd].msg_buf)
            fatal_error();
    }
    else
    {
        int old_len         = strlen(old_buf);
        clients[fd].msg_buf = realloc(old_buf, old_len + bytes + 1);
        if (!clients[fd].msg_buf)
            fatal_error();
        strcpy(clients[fd].msg_buf + old_len, buf);
    }

    // Process complete messages (ending with \n)
    char* msg = clients[fd].msg_buf;
    char* newline;

    while ((newline = strchr(msg, '\n')) != NULL)
    {
        *newline = '\0';

        // Broadcast this line
        char temp[100000];
        sprintf(temp, "%s\n", msg);
        broadcast_message(fd, temp);

        msg = newline + 1;
    }

    // Keep remaining incomplete message
    if (strlen(msg) > 0)
    {
        char* remaining = strdup(msg);
        if (!remaining)
            fatal_error();
        free(clients[fd].msg_buf);
        clients[fd].msg_buf = remaining;
    }
    else
    {
        free(clients[fd].msg_buf);
        clients[fd].msg_buf = NULL;
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    int port = atoi(argv[1]);

    // Initialize client array
    for (int i = 0; i < 1024; i++)
        clients[i].id = -1;

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        fatal_error();

    max_fd = sockfd;

    // Setup address
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family      = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  // 127.0.0.1
    serv_addr.sin_port        = htons(port);

    // Bind
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        fatal_error();

    // Listen
    if (listen(sockfd, 100) < 0)
        fatal_error();

    // Main event loop
    while (1)
    {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (clients[fd].id != -1)
                FD_SET(fd, &read_fds);
        }

        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0)
            fatal_error();

        // Check for new connection
        if (FD_ISSET(sockfd, &read_fds))
            accept_new_client(sockfd);

        // Check each client for data
        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (fd != sockfd && clients[fd].id != -1 && FD_ISSET(fd, &read_fds))
                handle_client_message(fd);
        }
    }

    return 0;
}
