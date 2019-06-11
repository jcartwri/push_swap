/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:49 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/12 14:54:52 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		equal_test(t_ablist *list)
{
	int	i;
	int j;

	i = -1;
	while (++i < list->lena)
	{
		j = 0;
		while (j < i)
		{
			if (list->a[j++] == list->a[i])
				return (-1);
		}
	}
	return (1);
}

int		ft_get_count(char **argv, int i, int j)
{
	if (argv[i][j] == '+' || argv[i][j] == '-')
		j++;
	while (argv[i][j] && argv[i][j] >= '0' && argv[i][j] <= '9')
		j++;
	return (j);
}

int		find_max_in_size(int *mas, int size)
{
	int i;
	int	m;

	i = 0;
	m = 0;
	if (size > 0)
	{
		m = mas[0];
		while (i < size)
		{
			if (mas[i] > m)
				m = mas[i];
			i++;
		}
	}
	return (m);
}

int		ft_commands(t_ablist *list, int size)
{
	if (list->b[0] == find_max_in_size(list->b, size))
	{
		ft_pa(list);
		size--;
	}
	if (list->b[1] == find_max_in_size(list->b, size))
	{
		ft_sba(list);
		ft_pa(list);
		size--;
	}
	if (list->b[2] == find_max_in_size(list->b, size))
	{
		ft_rb(list, 0);
		ft_sba(list);
		ft_pa(list);
		ft_rrb(list, 0);
		size--;
	}
	return (size);
}

void	ft_sba(t_ablist *list)
{
	if (list->lena >= 2)
	{
		if (list->a[0] > list->a[1])
		{
			ft_ss(list);
			return ;
		}
	}
	ft_sb(list, 0);
}
