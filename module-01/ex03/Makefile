# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 11:38:24 by mgodawat          #+#    #+#              #
#    Updated: 2025/08/28 17:25:59 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unnecessary_violence

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

SRCS =	main.cpp \
		humanA.cpp \
		humanB.cpp \
		Weapon.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re⏎
