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
	$(CC) $(CFLAGS) -c $< -o $@

# Program build rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Clean rules

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

# Remake
re: fclean all

.PHONY: all re clean fclean