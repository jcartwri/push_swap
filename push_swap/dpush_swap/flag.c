/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:33:18 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/18 12:33:21 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_ablist *list, int k)
{
	int	m;
	int i;

	if (list->lena != 0)
	{
		i = 0;
		m = list->a[0];
		while (++i < list->lena)
			list->a[i - 1] = list->a[i];
		list->a[list->lena - 1] = m;
	}
	if (k != 1)
	{
		ft_putendl("ra");
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_rb(t_ablist *list, int k)
{
	int	m;
	int i;

	if (list->lenb != 0)
	{
		i = 0;
		m = list->b[0];
		while (++i < list->lenb)
			list->b[i - 1] = list->b[i];
		list->b[list->lenb - 1] = m;
	}
	if (k != 1)
	{
		ft_putendl("rb");
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_rra(t_ablist *list, int k)
{
	int m;
	int i;

	if (list->lena != 0)
	{
		m = list->a[list->lena - 1];
		i = list->lena;
		while (--i > 0)
			list->a[i] = list->a[i - 1];
		list->a[0] = m;
	}
	if (k != 1)
	{
		ft_putendl("rra");
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_rrb(t_ablist *list, int k)
{
	int m;
	int i;

	if (list->lenb != 0)
	{
		m = list->b[list->lenb - 1];
		i = list->lenb;
		while (--i > 0)
			list->b[i] = list->b[i - 1];
		list->b[0] = m;
	}
	if (k != 1)
	{
		ft_putendl("rrb");
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_rrr(t_ablist *list)
{
	ft_rra(list, 1);
	ft_rrb(list, 1);
	ft_putendl("rrr");
	if (list->v == 1)
		ft_out_put_steak(list);
}
