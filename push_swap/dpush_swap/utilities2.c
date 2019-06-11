/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:27:22 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/12 16:27:24 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_break_array_half_a(t_ablist *list, int m, int begin, int size)
{
	int i;
	int	l;

	l = size;
	i = 0;
	while (l > 0)
	{
		if (list->a[0] < m)
		{
			ft_pb(list);
			size--;
		}
		else
		{
			ft_ra(list, 0);
			i++;
		}
		l--;
	}
	if (list->lena != size)
		ft_turn_up_begin_a(list, i, size, begin);
	return (size);
}

int	ft_break_array_half_b(t_ablist *list, int m, int begin, int size)
{
	int	i;
	int	l;

	l = size;
	i = 0;
	while (l > 0)
	{
		if (list->b[0] > m)
		{
			ft_pa(list);
			size--;
		}
		else
		{
			ft_rb(list, 0);
			i++;
		}
		l--;
	}
	if (list->lenb != size && size != 0)
		ft_turn_up_begin_b(list, i, size, begin);
	return (size);
}

int	ft_body_sort_a(t_ablist *list, int size)
{
	if (list->a[0] == find_max_in_size(list->a, size))
	{
		ft_sab(list);
		ft_ra(list, 0);
		ft_sab(list);
		ft_rra(list, 0);
		size--;
	}
	if (list->a[1] == find_max_in_size(list->a, size))
	{
		ft_ra(list, 0);
		ft_sab(list);
		ft_rra(list, 0);
		size--;
	}
	if (list->a[2] == find_max_in_size(list->a, size))
		size--;
	return (size);
}

int	ft_check_on_correct(char **argv, int i, int m)
{
	if (argv[i][m] == '+' || argv[i][m] == '-')
		m++;
	if (!(argv[i][m] >= '0' && argv[i][m] <= '9') && argv[i][m] != '\0')
		return (-1);
	return (1);
}
