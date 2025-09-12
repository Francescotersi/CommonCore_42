NAME = I_don’t_want_to_set_the_world_on_fire

SRC = main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp

RM = rm -rf
CPP = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(SRC)
	$(CPP) $(FLAGS) $^ -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
