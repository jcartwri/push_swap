/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:59:56 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/12 15:59:58 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_meridian(int l, int *mas)
{
	int i;
	int lmn;
	int lmax;
	int	j;
	int m;

	if (l <= 2)
		return (mas[0]);
	(INITI);
	while (++i < l)
	{
		(INITIAL);
		while (++j < l)
		{
			if ((i == l - 1) && (j == l - 1))
				break ;
			else if (i == j)
				j++;
			if (j < l)
				MAX(mas[j], m, lmn, lmax);
		}
		if (((lmn == lmax) && l % 2 == 1) || ((lmn - lmax == 1) && l % 2 == 0))
			return (m);
	}
	return (m);
}

void	ft_turn_up_begin_a(t_ablist *list, int l, int size, int begin)
{
	if (l == 0)
		return ;
	while (list->a[0] != begin)
	{
		ft_rra(list, 0);
	}
}

void	ft_turn_up_begin_b(t_ablist *list, int l, int size, int begin)
{
	if (l == 0)
		return ;
	while (list->b[0] != begin)
	{
		ft_rrb(list, 0);
	}
}

int		ft_get_begin_a(int *mas, int size, int m)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (mas[i] >= m)
			return (mas[i]);
		i++;
	}
	return (0);
}

int		ft_get_begin_b(int *mas, int size, int m)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (mas[i] <= m)
			return (mas[i]);
		i++;
	}
	return (0);
}
