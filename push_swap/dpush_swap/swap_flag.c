/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:34:35 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/12 14:34:37 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_ablist *list, int i)
{
	int m;

	if (list->lena >= 2)
	{
		m = list->a[0];
		list->a[0] = list->a[1];
		list->a[1] = m;
	}
	if (i != 1)
	{
		ft_putendl("sa");
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_sb(t_ablist *list, int i)
{
	int m;

	if (list->lenb >= 2)
	{
		m = list->b[0];
		list->b[0] = list->b[1];
		list->b[1] = m;
	}
	if (i != 1)
	{
		ft_putendl("sb");
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_ss(t_ablist *list)
{
	ft_sa(list, 1);
	ft_sb(list, 1);
	ft_putendl("ss");
	if (list->v == 1)
		ft_out_put_steak(list);
}
