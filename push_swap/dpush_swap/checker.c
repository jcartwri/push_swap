/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:50:06 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/12 15:50:08 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_cheak_sorted_a(int *mas, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (mas[i] > mas[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int		ft_cheak_sorted_b(int *mas, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (mas[i] < mas[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int		ft_cheak_stop_a(t_ablist *list, int size)
{
	if (ft_cheak_sorted_a(list->a, size) == 1)
	{
		return (size);
	}
	return (-1);
}

int		ft_revers_a(t_ablist *list)
{
	int	i;

	i = 0;
	while (i < list->lena - 1)
	{
		ft_rra(list, 0);
		i++;
	}
	return (1);
}

void	ft_sab(t_ablist *list)
{
	if (list->lenb >= 2)
	{
		if (list->b[0] < list->b[1])
		{
			ft_ss(list);
			return ;
		}
	}
	ft_sa(list, 0);
}
