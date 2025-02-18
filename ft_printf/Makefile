# Creo la variabile che mi rappresenta un nome, posso usarla per dare il nome ad un qualsiasi 
# output di mia scelta
NAME = libftprintf.a

LIBFT = Libft/libft.a
LIBFT_DIR = Libft/
CP = cp
# La lista dei file sorgente che utilizzo per creare i miei file oggetto
SRC = ft_printf.c ft_hexprint_lower.c ft_hexprint_upper.c ft_printer.c \
	ft_putaddress.c ft_retputnbr_fd.c ft_unsigned_putnbr_fd.c\
	ft_utils.c

# Specifico le flags con la variabile CFLAGS
CFLAGS = -Wall -Werror -Wextra -g 

# Specifico il compilatore che voglio utilizzare con la variabile CC
CC = gcc

# Regola per convertire i  .c in .o
OBJ = $(SRC:.c=.o)

all: $(NAME)                 

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)
	$(CP) $(LIBFT) $(NAME)

$(NAME):  $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ)

# Regola generale per compilare i file .c in file oggetto
%.o: %.
	$(CC) $(CFLAGS) -c $< -o $@ 

# Rimuove i file oggetto generati durante la compilazione (-f) indica la rimozione forzata senza chiedere conferma
clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

# Elimina anche la libreria oltre che ai file oggetto, questa regola dipende da clean, 
# quindi prima esegue clean rimuovendo i file oggetto e poi esegue il comando che rimuove 
# forzatamente (ossia senza bisogno di conferma) ($NAME)
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Questo comando pulisce ogni cosa e poi riesegue il comando ($NAME) ricreando la libreria
re: fclean $(NAME)

# .PHONY: Dichiara che all, clean, fclean, e re sono target "fittizi" (non sono file reali bensi comandi). 
# Questo impedisce che make li confonda con file esistenti con lo stesso nome, e garantisce 
# che vengano sempre eseguiti come comandi, anche se esistono file con questi nomi.
.PHONY: all clean fclean re
