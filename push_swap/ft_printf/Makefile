# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 16:07:04 by jcartwri          #+#    #+#              #
#    Updated: 2019/02/20 16:10:39 by jcartwri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LNAME = libft

SRCS = *.c

OBJ = *.o

OBJ2 = libft/ft_*.o

FLAGS = -Wall -Wextra -Werror

INC = ft_printf.h

all: $(NAME)

$(NAME):
	@make -C libft fclean && make -C libft
	@gcc $(FLAGS) -c $(SRCS) -I$(INC)
	@ar rc $(NAME) $(OBJ) $(OBJ2)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJ2)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a

re: fclean all
