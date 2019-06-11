# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:35:30 by jcartwri          #+#    #+#              #
#    Updated: 2019/04/06 13:02:50 by jcartwri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
SRC1 = ./dpush_swap/flag.c ./dpush_swap/ft_atolli.c \
    ./dpush_swap/ft_out_put_steak.c ./dpush_swap/free_file.c \
     ./dpush_swap/push_flag.c ./dpush_swap/swap_flag.c \
     ./dpush_swap/utilities.c ./dpush_swap/checker.c ./dpush_swap/utilities1.c \
     ./dpush_swap/utilities2.c

SRC2 = ./dchecker/flag1.c ./dchecker/psflag.c ./dchecker/rrflag.c
OBJ1 = flag.o ft_atolli.o ft_out_put_steak.o main.o free_file.o push_flag.o swap_flag.o utilities.o checker.o utilities1.o utilities2.o
OBJ2 = flag1.o psflag.o rrflag.o
FLAGS = -Wall -Wextra -Werror
# HEAD1 = ./dpush_swap/push_swap.h
# HEAD2 = ./dchecker/checker
LIBRF = ./ft_printf/libftprintf.a
LIBRL = ./ft_printf/libft/libft.a

all: $(NAME1) $(NAME2)

$(NAME1):
		@make re -C ft_printf/
		@gcc -c $(SRC1) ./dpush_swap/main.c
		@gcc $(LIBRF) $(LIBRL) $(FLAGS) $(OBJ1) -o $(NAME1)

$(NAME2):
		@gcc -c $(SRC2) ./dchecker/main.c
		@gcc $(LIBRF) $(LIBRL) $(FLAGS) $(OBJ1) $(OBJ2) -o $(NAME2)

clean:
		make clean -C ft_printf
		@rm -f $(OBJ1)
		@rm -f $(OBJ2)

fclean: clean
		make fclean -C ft_printf
		@rm -f push_swap
		@rm -f checker

re: fclean all
