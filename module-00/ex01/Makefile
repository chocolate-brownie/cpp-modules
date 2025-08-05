
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 19:06:47 by mgodawat          #+#    #+#              #
#    Updated: 2025/07/23 19:09:44 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude/
NAME = phonebook
SRC_DIR = src
OBJ_DIR = build

SRCS =	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/contact.cpp \
		$(SRC_DIR)/phonebook.cpp \


OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo "🔗 Linking object files..."
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "🚀 Executable '$(NAME)' is ready to launch!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "⚙️  Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Build directory cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "💥 Executable '$(NAME)' cleaned."

re: fclean all

.PHONY: all clean fclean re
