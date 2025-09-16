NAME = Mommy_when_I_grow_up_I_want_to_be_a_bureaucrat!

SRC = main.cpp Bureaucrat.cpp

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
