# Program name
NAME	= brainzz

# Compiler
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Build files
INC_PATH	= ./includes/
INC			= -I $(INC_PATH)

SRC_PATH	= ./sources/
SRC			=	Zombie.cpp \
				newZombie.cpp \
				randomChump.cpp	\
				main.cpp			
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= ./objects/
OBJ			= $(SRC:.cpp=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Build rule
all: $(OBJ_PATH) $(NAME)

# Object-building rules
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Program-building rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

# Cleaning rules
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

# Remake
re: fclean all

.PHONY: all re clean fclean