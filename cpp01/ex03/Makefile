# Program name
NAME	= unecessary_violence

# Compiler
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Files
INC_PATH	= ./includes/
INC			= -I $(INC_PATH)

SRC_PATH	= ./sources/
SRC			= 	main.cpp \
				HumanA.cpp \
				HumanB.cpp \
				Weapon.cpp
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= ./objects/
OBJS		= $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

# Build rule
all: $(OBJ_PATH) $(NAME)

# Object build rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Program build rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

# Clean rules
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

# Remake
re: fclean all

.PHONY: all re clean fclean