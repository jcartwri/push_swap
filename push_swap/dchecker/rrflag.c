/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrflag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 23:38:57 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/11 23:39:00 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra1(t_ablist *list, int k)
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
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_rb1(t_ablist *list, int k)
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
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_rr1(t_ablist *list)
{
	ft_ra(list, 1);
	ft_rb(list, 1);
	if (list->v == 1)
		ft_out_put_steak(list);
}

void	ft_rra1(t_ablist *list, int k)
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
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_rrb1(t_ablist *list, int k)
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
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}
