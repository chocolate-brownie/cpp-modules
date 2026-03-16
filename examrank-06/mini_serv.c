#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

typedef struct s_client {
    int id;
    char msg[100000];
} t_client;

typedef struct s_server {
    int sockfd;
    int max_fd;
    int current_id;
    fd_set current_set;
    fd_set write_set;
    fd_set ready_set;
    struct sockaddr_in servaddr;
    t_client clients[FD_SETSIZE];
} t_server;

t_server server;

void err() {
    write(2, "Fatal error\n", 12);
    exit(1);
}

int setup_server(int port) {
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.sockfd == -1)
        err();

    bzero(&server.servaddr, sizeof(server.servaddr));
    // assign IP, PORT
    server.servaddr.sin_family = AF_INET;
    server.servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    server.servaddr.sin_port = htons(port);

    // Binding newly created socket to given IP and verification
    if ((bind(server.sockfd, (const struct sockaddr *)&server.servaddr,
              sizeof(server.servaddr))) != 0)
        err();
    if (listen(server.sockfd, 10) != 0)
        err();
    return 0;
}

void broadcast_message(int sender_fd, char *msg) {
    for (int fd = 0; fd <= server.max_fd; ++fd) {
        if (FD_ISSET(fd, &server.write_set) && fd != sender_fd &&
            fd != server.sockfd)
            send(fd, msg, strlen(msg), 0);
    }
}

void add_new_client() {
    struct sockaddr_in cli;
    socklen_t len = sizeof(cli);
    int connfd = accept(server.sockfd, (struct sockaddr *)&cli, &len);
    if (connfd < 0)
        err();

    if (connfd > server.max_fd)
        server.max_fd = connfd;

    server.clients[connfd].id = server.current_id++;
    FD_SET(connfd, &server.current_set);

    char msg[128];
    sprintf(msg, "server: client %d just arrived\n", server.clients[connfd].id);
    broadcast_message(connfd, msg);
}

void handle_existing_client() {
    return;
}

void event_loop() {
    /* maxfd will be 3 at initialization telling select() that there will be 4
     * sockets in total for you to check [0(STDIN), 1(STDOUT), 2(STDERR),
     * 3(Server Socket)]*/
    server.max_fd = server.sockfd;

    // 0 out all the fd_set for safety
    FD_ZERO(&server.current_set);
    FD_ZERO(&server.ready_set);
    FD_ZERO(&server.write_set);

    // add the server socket to the the current fd_se
    FD_SET(server.sockfd, &server.current_set);

    while (1) {
        /* since select() has a desctructive behaviour.. when we pass ready_set
         * and write_set it deletes them so we have to update its value on each
         * iteration to make sure we dont pass an empty set */
        server.ready_set = server.current_set;
        server.write_set = server.current_set;
        if (select(server.max_fd + 1, &server.ready_set, &server.write_set,
                   NULL, NULL) == -1)
            err();

        /* upon success select() flips the bit of the active fds ready for any
         * sort of actions so we have to iterate through the available fds
         * inside the ready/write set and check are there any fds that has its
         * bits turned on by select() this can be checked using FD_ISSET() */
        for (int fd = 0; fd <= server.max_fd; ++fd) {
            if (FD_ISSET(fd, &server.ready_set) != 0) {
                /* once we find a fd with 1 (turned on) we check whether its
                 * the server socket. If it is its new incoming connection else
                 * its an already exisiting client trying to send a message */
                if (fd == server.sockfd)
                    add_new_client();
                else
                    handle_existing_client();
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    // setup server with socket creation and verification
    setup_server(atoi(argv[1]));
    printf("Setup creation OK\n");
    // main event loop
    printf("Starting event loop\n");
    event_loop();

    return 0;
}
