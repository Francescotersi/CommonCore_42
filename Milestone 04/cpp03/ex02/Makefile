NAME = repetitive_work

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

RM = rm -rf
CC = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $^ -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
