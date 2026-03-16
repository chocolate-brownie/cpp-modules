#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/select.h>

#define MAX_MSG_SIZE 100000
#define MAX_CLIENTS 2048

typedef struct s_client
{
	int 	id;
	char 	msg[MAX_MSG_SIZE];
}	t_client;

t_client clients[MAX_CLIENTS];

int	current_id = 0;
int	max_fd = 0;

fd_set	read_set;
fd_set	write_set;
fd_set	current_set;

char	send_buffer[MAX_MSG_SIZE + 50];
char	recv_buffer[MAX_MSG_SIZE];

void	ft_putstr(int fd, char *msg)
{
	for (int i = 0; msg[i]; i++)
		write(fd, &msg[i], 1);
}

void	err(char* msg)
{
	if (!msg)
		ft_putstr(2, "Fatal error\n");
	else
		ft_putstr(2, msg);
	exit(1);
}

void	broadcast(int sender)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && sender != fd)
			if (send(fd, &send_buffer, strlen(send_buffer), 0) == -1)
				err(NULL);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		err("Wrong number of arguments\n");

	int	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		err(NULL);
	struct sockaddr_in	servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 

	FD_ZERO(&current_set);
	FD_SET(sockfd, &current_set);
	max_fd = sockfd;

	if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) != 0)
		err(NULL);
	if (listen(sockfd, 10) != 0)
		err(NULL);

	while (1)
	{
		read_set = write_set = current_set;
		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) == -1)
			err(NULL);
		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == sockfd)
				{
					struct sockaddr_in	cli;
					bzero(&cli, sizeof(cli));
					socklen_t	len = sizeof(cli);
					int	newfd = accept(sockfd, (struct sockaddr*)&cli, &len);
					if (newfd < 0)
						err(NULL);
					if (newfd > max_fd)
						max_fd = newfd;
					clients[newfd].id = current_id++;
					FD_SET(newfd, &current_set);
					sprintf(send_buffer, "server: client %d just joined\n", clients[newfd].id);
					broadcast(newfd);
				}
				else
				{
					int	rec = recv(fd, &recv_buffer, sizeof(recv_buffer) -1, 0);
					if (rec <= 0)
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						broadcast(fd);
						FD_CLR(fd, &current_set);
						close(fd);
					}
					else
					{
						recv_buffer[rec] = '\0';
						strcat(clients[fd].msg, recv_buffer);

						char	*msg_ptr = clients[fd].msg;
						char	*newline_ptr = NULL;

						while ((newline_ptr = strstr(msg_ptr, "\n")))
						{
							*newline_ptr = '\0';
							sprintf(send_buffer, "client %d: %s\n", clients[fd].id, msg_ptr);
							broadcast(fd);
							msg_ptr = newline_ptr + 1;
						}
						strcpy(clients[fd].msg, msg_ptr);
					}
				}
			}
		}
	}
}
