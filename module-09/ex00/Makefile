NAME		= BitcoinExchange
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC_DIR		= src
OBJ_DIR		= build
INC_DIR		= include

SRCS		= main.cpp \

OBJS		= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(addprefix $(SRC_DIR)/, $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking object files to create $(NAME)..."
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(NAME) created successfully! ✨"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

debug: CXXFLAGS += -DDEBUG
debug: all
	@echo "Debug mode enabled with -DDEBUG flag! 🔍"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
