/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psflag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 23:38:24 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/11 23:38:27 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa1(t_ablist *list, int i)
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
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_sb1(t_ablist *list, int i)
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
		if (list->v == 1)
			ft_out_put_steak(list);
	}
}

void	ft_ss1(t_ablist *list)
{
	ft_sa(list, 1);
	ft_sb(list, 1);
	if (list->v == 1)
		ft_out_put_steak(list);
}

void	ft_pa1(t_ablist *list)
{
	int	m1;
	int	m2;
	int	i;

	if (list->lenb != 0)
	{
		m1 = list->a[0];
		list->a[0] = list->b[0];
		list->lena++;
		i = 0;
		while (++i < list->lena)
		{
			m2 = list->a[i];
			list->a[i] = m1;
			m1 = m2;
		}
		i = -1;
		while (++i < list->lenb - 1)
			list->b[i] = list->b[i + 1];
		list->lenb--;
	}
	if (list->v == 1)
		ft_out_put_steak(list);
}

void	ft_pb1(t_ablist *list)
{
	int	m1;
	int	m2;
	int	i;

	if (list->lena != 0)
	{
		m1 = list->b[0];
		list->b[0] = list->a[0];
		list->lenb++;
		i = 0;
		while (++i < list->lenb)
		{
			m2 = list->b[i];
			list->b[i] = m1;
			m1 = m2;
		}
		i = -1;
		while (++i < list->lena - 1)
			list->a[i] = list->a[i + 1];
		list->lena--;
	}
	if (list->v == 1)
		ft_out_put_steak(list);
}
