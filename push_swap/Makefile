NAME = push_swap

SOURCES = input_checker.c push_swap.c utils.c input_checker_2.c \
		utils_2.c operations_1.c operations_2.c operations_3.c \
		special_cases.c utils_3.c sort_utils.c sort_init.c sort.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -g -IPush_libft -LPush_libft

all : $(NAME)

$(NAME): $(OBJ) $(SOURCES)
	make bonus -C Push_libft
	$(CC) $(SOURCES) Push_libft/libft.a $(FLAGS) -o $(NAME)

clean:
	@echo Cleaning...
	make clean -C Push_libft

fclean: clean
	@echo I SAID I AM CLEANING OK!!
	make fclean -C Push_libft
	rm -f $(NAME)

re : fclean all

libft:
	@echo Compiling Push_Libft...
	make bonus -C Push_libft

.PHONY: all clean fclean re printf libft

.SILENT: