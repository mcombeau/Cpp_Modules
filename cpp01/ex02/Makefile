# Program name
NAME = brain

# Compiler
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Files
SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)

# Build rule
all: $(NAME)

# Object build rule
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Program build rule
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Cleaning rules
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean