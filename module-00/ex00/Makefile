# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 13:18:11 by mgodawat          #+#    #+#              #
#    Updated: 2025/08/05 16:04:18 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude/
NAME = megaphone
SRC_DIR = src
OBJ_DIR = build

SRCS = 	$(SRC_DIR)/megaphone.cpp \

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

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