NAME = libft.a
FLAG = -Wall -Werror -Wextra
SRC =	*.c
OBJ =	*.o
HEADER = libft.h

all: $(NAME)

$(NAME):
		gcc $(FLAG) -c $(SRC) -I $(HEADER)
		ar rc $(NAME) $(OBJ)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
