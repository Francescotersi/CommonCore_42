NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = Ssj_libft/libft.a
LIBFT_DIR = Ssj_libft/

MLX = minilibx-linux/libmlx_Linux.a
MLX_DIR = minilibx-linux/
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -LSsj_libft -O3

SRC =	main.c \
		rendering/handle.c \
		rendering/rendering.c \
		rendering/render_utils.c \
		rendering/inputs.c \
		rendering/textures.c \
		parsing/rgb_parsing.c \
		parsing/parsing.c \
		parsing/map_check.c \
		parsing/pars_utils.c \
		parsing/map_pars.c \
		utils.c \
		utils2.c

OBJ_DIR = obj
OBJS    = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME) 

mlx: $(MLX)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

vall: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  -s ./$(NAME)

clean:
	@rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	
re: fclean all

.PHONY: all clean fclean re mlx vall

# .SILENT:

