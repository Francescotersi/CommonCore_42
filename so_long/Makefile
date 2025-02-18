NAME = so_long

MLX = minilibx-linux/libmlx-Linux.a
MLX_DIR = minilibx-linux/

GOKU = Ssj_libft/libft.a
GOKU_DIR = Ssj_libft/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
FCK_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -LSsj_libft

SRC = so_long.c input_handler.c map_handler.c error_checks.c \
	path_finding.c so_long_utils.c graphic.c movement.c \
	rng.c movement_2.c graphic_2.c

OBJ = 

all: $(NAME)

$(GOKU):
	@$(MAKE) -C $(GOKU_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(GOKU)
	@$(CC) $(SRC) $(FCK_FLAGS) $(GOKU) -g -o $(NAME)
#	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  -s ./$(NAME)
#	./$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re
.SILENT:

