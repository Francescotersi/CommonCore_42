NAME = philo

SOURCES = init.c main.c utils.c actions.c utils_2.c mutex_returns.c utils_3.c

OBJ = $(SOURCES:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -pthread -g

all : $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

clean:
	@echo Cleaning...
	rm -f *.o

fclean: clean
	@echo I SAID I AM CLEANING OK!!
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

# .SILENT: