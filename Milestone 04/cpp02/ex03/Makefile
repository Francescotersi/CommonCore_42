NAME = bsp
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ = $(FILES:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@echo HENRY
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@echo SIR RODZIG
	rm -f $(OBJ)

fclean: clean
	@echo HANS CAPON
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

.SILENT: