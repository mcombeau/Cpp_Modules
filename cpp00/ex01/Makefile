# Program file name
NAME	= FMN-PhoneBook

# Compiler and compilation flags
CC		= g++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Build files and directories
SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
SRC		= 	main.cpp \
			Contact.class.cpp \
			PhoneBook.class.cpp 
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I $(INC_PATH)

# Main rule
all: $(OBJ_PATH) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

# Clean up build files rule
clean:
	rm -rf $(OBJ_PATH)

# Remove program executable
fclean: clean
	rm -f $(NAME)

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean