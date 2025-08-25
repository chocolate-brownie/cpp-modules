# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 19:06:47 by mgodawat          #+#    #+#              #
#    Updated: 2025/08/25 19:18:35 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = account
SRC_DIR = src
OBJ_DIR = build

# List the final object files that are needed
OBJS = $(OBJ_DIR)/Account.o $(OBJ_DIR)/tests.o

# Add the include path for Account.hpp
CPPFLAGS = -I.

# Add debug flags if DEBUG is set
ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo "🔗 Linking object files..."
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "🚀 Executable '$(NAME)' is ready to launch!"

# Generic rule for compiling .cpp files from the src/ directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "⚙️  Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Specific rule for compiling tests.cpp from the src directory
$(OBJ_DIR)/tests.o: $(SRC_DIR)/tests.cpp | $(OBJ_DIR)
	@echo "⚙️  Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Rule to create the build directory if it doesn't exist
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
