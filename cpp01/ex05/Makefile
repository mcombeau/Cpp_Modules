# Program name
NAME	= harl

# Compiler
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Files
SRCS	= main.cpp Harl.cpp
OBJS	= $(SRCS:.cpp=.o)
INC		= -I ./

# Build rule
all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Program build rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

# Clean rules

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

# Remake
re: fclean all

.PHONY: all re clean fclean