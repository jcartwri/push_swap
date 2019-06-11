/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 23:43:03 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/11 23:43:09 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_CHECKER_H
# define CHECKER_CHECKER_H
# define EXIT {ft_putstr("Error\n"); exit(0);}

# include <stdlib.h>
# include "../dpush_swap/push_swap.h"
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ft_printf.h"

int		main(int argc, char **argv);
void	ft_sa1(t_ablist	*list, int i);
void	ft_sb1(t_ablist	*list, int i);
void	ft_ss1(t_ablist	*list);
void	ft_pa1(t_ablist *list);
void	ft_pb1(t_ablist *list);
void	ft_ra1(t_ablist *list, int k);
void	ft_rb1(t_ablist *list, int k);
void	ft_rr1(t_ablist *list);
void	ft_rra1(t_ablist *list, int k);
void	ft_rrb1(t_ablist *list, int k);
void	ft_rrr1(t_ablist *list);

#endif
