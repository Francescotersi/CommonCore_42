NAME = harl_2.0
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = Harl.cpp \
		main.cpp \

OBJ = $(FILES:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@echo SOLID SNAKE
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@echo MERYL
	rm -f $(OBJ)

fclean: clean
	@echo COLONEL
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

.SILENT:
