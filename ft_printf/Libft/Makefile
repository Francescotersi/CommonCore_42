# Creo la variabile che mi rappresenta un nome, posso usarla per dare il nome ad un qualsiasi 
# output di mia scelta
NAME = libft.a

# La lista dei file sorgente che utilizzo per creare i miei file oggetto
SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		ft_memmove.c ft_memset.c ft_putendl_fd.c ft_putchar_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Specifico le flags con la variabile CFLAGS
CFLAGS = -Wall -Werror -Wextra -Iincludes

# Specifico il compilatore che voglio utilizzare con la variabile CC
CC = gcc

# Uso patsubst per convertire i  .c in .o
OBJ = $(SRC:.c=.o)

# Regola compilazione bonus
BONUSOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOBJ)
	ar rcs $(NAME) $(OBJ) $(BONUSOBJ)

# Regola generale per compilare i file .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rimuove i file oggetto generati durante la compilazione (-f) indica la rimozione forzata senza chiedere conferma
clean:
	rm -f $(OBJ) $(BONUSOBJ)

# Elimina anche la libreria oltre che ai file oggetto, questa regola dipende da clean, 
# quindi prima esegue clean rimuovendo i file oggetto e poi esegue il comando che rimuove 
# forzatamente (ossia senza bisogno di conferma) ($NAME)
fclean: clean
	rm -f $(NAME)

# Questo comando pulisce ogni cosa e poi riesegue il comando ($NAME) ricreando la libreria
re: fclean $(NAME)

# .PHONY: Dichiara che all, clean, fclean, e re sono target "fittizi" (non sono file reali). 
# Questo impedisce che make li confonda con file esistenti con lo stesso nome, e garantisce 
# che vengano sempre eseguiti come comandi, anche se esistono file con questi nomi.
.PHONY: all clean fclean re bonus

