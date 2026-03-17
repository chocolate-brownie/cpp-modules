#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* ------------------ Structs ------------------- */
typedef struct s_client {
    int id;
    char msg[100000];
} t_client;

typedef struct s_server {
    int sockfd;
    int max_fd;
    int current_id;

    fd_set readfds;
    fd_set writefds;
    fd_set currentfds;

    t_client clients[FD_SETSIZE];
} t_server;
/* ------------------ Globals ------------------- */
char recv_buffer[100000]; // stack might overflow if we define this locally 
char send_buffer[100050]; // stack might overflow if we define this locally 
t_server server;
/* ---------------------------------------------- */

void err() {
    write(2, "Fatal error\n", 12);
    exit(1);
}

void setup_server(int port) {
    struct sockaddr_in servaddr;

    // socket create and verification
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.sockfd == -1)
        err();

    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(port);

    // Binding newly created socket to given IP and verification
    if ((bind(server.sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        err();

    // listen to incoming connections
    if (listen(server.sockfd, 10) != 0)
        err();
}

void broadcast(int sender_fd, char *msg) {
    for (int fd = 0; fd <= server.max_fd; ++fd) {
        if (FD_ISSET(fd, &server.writefds) && fd != sender_fd && fd != server.sockfd)
            send(fd, msg, strlen(msg), 0);
    }
}

void add_new_client() {
    struct sockaddr_in cli;
    bzero(&cli, sizeof(cli));
    socklen_t len;
    int connfd;

    len = sizeof(cli);
    connfd = accept(server.sockfd, (struct sockaddr *)&cli, &len); // accept the connection
    if (connfd < 0)
        err();
    // update the maxfd
    if (connfd > server.max_fd) 
        server.max_fd = connfd;
    // assign an id for the client
    server.clients[connfd].id = server.current_id++;
    // add the new added connection fd to the watchlist
    FD_SET(connfd, &server.currentfds);
    // broadcast the message
    char msg[128];
    sprintf(msg, "server: client %d just arrived\n", server.clients[connfd].id);
    broadcast(connfd, msg);
}

void handle_existing_client(int fd) {
    int rec = recv(fd, recv_buffer, sizeof(recv_buffer)-1, 0);
    if (rec <= 0) {
        // handle disconnections
        char msg[128];
        sprintf(msg, "server: client %d just left\n", server.clients[fd].id);
        broadcast(fd, msg);
        FD_CLR(fd, &server.currentfds);
        close(fd);
    } else {
        // handle the msg
        recv_buffer[rec] = '\0';
        strcat(server.clients[fd].msg, recv_buffer);

        char *msg_ptr = server.clients[fd].msg;
        char *newline_ptr = NULL;
        while ((newline_ptr = strstr(msg_ptr, "\n"))) {
            *newline_ptr = '\0';
            sprintf(send_buffer, "client %d: %s\n", server.clients[fd].id, msg_ptr);
            broadcast(fd, send_buffer);
            msg_ptr = newline_ptr + 1;
        }

        strcpy(server.clients[fd].msg, msg_ptr);
    }
}

void event_loop() {
    server.max_fd = server.sockfd;
    FD_ZERO(&server.currentfds);
    FD_ZERO(&server.readfds);
    FD_ZERO(&server.writefds);

    FD_SET(server.sockfd, &server.currentfds);

    while (1) {
        server.readfds = server.currentfds;
        server.writefds = server.currentfds;

        if (select(server.max_fd + 1, &server.readfds, &server.writefds, NULL, NULL) == -1)
            err();

        for (int fd = 0; fd <= server.max_fd; ++fd) {
            if (FD_ISSET(fd, &server.readfds) != 0) {
                if (fd == server.sockfd)
                    add_new_client();
                else
                    handle_existing_client(fd);
            }
        }
    }

    return;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    setup_server(atoi(argv[1]));
    event_loop();

    return 0;
}