NAME = phonebook
CPP = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98

FILES = main.cpp otacon.cpp Contact.cpp PhoneBook.cpp

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