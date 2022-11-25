# Program name
NAME	= loser_sed

# Compiler
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Files
SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

# Build rule
all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Program build rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

# Clean rules

reset:
	rm -rf $(wildcard ./test/*.replace)

clean: reset
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

# Remake
re: fclean all

.PHONY: all re clean fclean