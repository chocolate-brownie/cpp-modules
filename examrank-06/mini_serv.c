#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

void fatal()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int setup_server(struct sockaddr_in *servaddr, int port)
{
	int master_socket = 0;
	if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		fatal();

	bzero(servaddr, sizeof(*servaddr)); 

	// assign IP, PORT 
	servaddr->sin_family = AF_INET; 
	servaddr->sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr->sin_port = htons(port);  

	if ((bind(master_socket, (const struct sockaddr *)servaddr, sizeof(*servaddr))) != 0)
		fatal();

	if (listen(master_socket, SOMAXCONN) != 0)
		fatal();

	return master_socket; 
}

void open_connection()
{
	int maxfd = 0;
	maxfd = master_socket;

	while (1)
	{
		// Check for incoming connection
		int activity;
		readfds = activefds;
		if ((activity = select(maxfd + 1, &readfds, NULL, NULL, NULL)) < 0)
			fatal();

		/* Loop through all the availble fds */
		for (int fd = 0; fd <= maxfd; ++fd)
		{
			if (!FD_ISSET(fd, &readfds))
				continue;

			if (fd == master_socket)
			{
				/* If the connection is coming through the master socket
				its a new client */
				create_new_client(master_socket);
			}
			else 
			{
				/* If its an already existing client trying to communicate
				they are trying to send a message */
				handle_message(fd);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	struct sockaddr_in servaddr;
	int port = atoi(argv[1]);

	fd_set readfds, activefds;

	FD_ZERO(&activefds); // clear the fd_set
	int master_socket = setup_server(&servaddr, port);
	printf("DEBUG: (%d) Server is listening on port:%d\n", master_socket, port);
	FD_SET(master_socket, &activefds); // adding the master_socket to the active list
	

	return 0;
}


