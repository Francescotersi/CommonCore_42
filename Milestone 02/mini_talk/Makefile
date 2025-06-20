NAME = mini_talk

SOURCES = client.c server.c

SOURCES_BONUS = client_bonus.c server_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

CC = cc

CLIENT = client

SERVER = server

FLAGS = -Wall -Wextra -Werror -g -ISsj_libft -LSsj_libft

all: $(SERVER) $(CLIENT) 

$(CLIENT): $(OBJ) $(SOURCES)
	make bonus -C Ssj_libft
	$(CC) client.c Ssj_libft/libft.a $(FLAGS) -o client

$(SERVER): $(OBJ) $(SOURCES)
	make bonus -C Ssj_libft
	$(CC) server.c Ssj_libft/libft.a $(FLAGS) -o server

bonus: $(OBJ_BONUS) $(SOURCES_BONUS)
	make bonus -C Ssj_libft
	$(CC) client_bonus.c Ssj_libft/libft.a $(FLAGS) -o client_bonus
	$(CC) server_bonus.c Ssj_libft/libft.a $(FLAGS) -o server_bonus

clean:
	@echo Cleaning...
	make clean -C Ssj_libft
	rm -rf *.o

fclean: clean
	@echo I SAID I AM CLEANING OK!!
	make fclean -C Ssj_libft
	rm -f client server client_bonus server_bonus

re : fclean all

re_bonus: fclean bonus

libft:
	@echo Compiling Ssj_Libft...
	make bonus -C Ssj_libft

.PHONY: all clean fclean re printf libft

.SILENT: