NAME	= test-GBU

CC		= g++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC		= Account.cpp tests.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -I .

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean