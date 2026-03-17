#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

char recvbuff[100000];
char sendbuff[100050];

fd_set watchfds;
fd_set readfds;
fd_set writefds;

typedef struct s_client {
    int id;
    char msg[100000];
} t_client;

typedef struct s_server {
    int fd_socket;
    int maxfd;
    int connection_id;
    t_client client[FD_SETSIZE];
} t_server;

t_server server;

void err() {
    write(2, "Fatal error\n", 12);
    exit(1);
}

void setup_server(int port) {
    struct sockaddr_in servaddr;

    // socket create and verification
    server.fd_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server.fd_socket == -1)
        err();

    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(port);

    // Binding newly created socket to given IP and verification
    if ((bind(server.fd_socket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        err();

    if (listen(server.fd_socket, 10) != 0)
        err();
}

void broadcast(int senderfd, char *msg) {
    for (int fd = 0; fd <= server.maxfd; ++fd) {
        if (FD_ISSET(fd, &writefds) && fd != senderfd && fd != server.fd_socket)
            send(fd, msg, strlen(msg), 0);
    }
}

void accept_new_client() {
    struct sockaddr_in cli;
    bzero(&cli, sizeof(cli));

    socklen_t len = sizeof(cli);
    int connfd = accept(server.fd_socket, (struct sockaddr *)&cli, &len);
    if (connfd < 0)
        err();

    if (connfd > server.maxfd)
        server.maxfd = connfd;

    server.client[connfd].id = server.connection_id++;
    FD_SET(connfd, &watchfds);

    char msg[128];
    sprintf(msg, "server: client %d just arrived\n", server.client[connfd].id);
    broadcast(connfd, msg);
}

void handle_existing_client(int fd) {
    int rec = recv(fd, recvbuff, sizeof(recvbuff)-1, 0);
    if (rec <= 0) {
        char msg[128];
        sprintf(msg, "server: client %d just left\n", server.client[fd].id);
        broadcast(fd, msg);
        FD_CLR(fd, &watchfds);
        close(fd);
    } else {
        recvbuff[rec] = '\0';
        strcat(server.client[fd].msg, recvbuff);

        char *msg_ptr = server.client[fd].msg;
        char *newline_ptr = NULL;
        while ((newline_ptr = strstr(msg_ptr, "\n"))) {
            *newline_ptr = '\0';
            sprintf(sendbuff, "client %d: %s\n", server.client[fd].id, msg_ptr);
            broadcast(fd, sendbuff);
            msg_ptr = newline_ptr + 1;
        }

        strcpy(server.client[fd].msg, msg_ptr);
    }
}

void run_server() {
    FD_ZERO(&watchfds);
    FD_ZERO(&writefds);
    FD_ZERO(&readfds);
    
    server.maxfd = server.fd_socket;
    FD_SET(server.fd_socket, &watchfds);

    while (1) {
        writefds = watchfds;
        readfds = watchfds;

        if (select(server.maxfd + 1, &readfds, &writefds, NULL, NULL) == -1)
            err();

        for (int fd = 0; fd <= server.maxfd; ++fd) {
            if (FD_ISSET(fd, &readfds)) {
                if (fd == server.fd_socket)
                    accept_new_client();
                else
                    handle_existing_client(fd);
            }
        }
    }

}

int main(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    setup_server(atoi(argv[1]));
    run_server();
    return 0;
}