/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:37:59 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/12 14:38:01 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_ablist *list)
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
	ft_putendl("pa");
	if (list->v == 1)
		ft_out_put_steak(list);
}

void	ft_pb(t_ablist *list)
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
	ft_putendl("pb");
	if (list->v == 1)
		ft_out_put_steak(list);
}

void	ft_rr(t_ablist *list)
{
	ft_ra(list, 1);
	ft_rb(list, 1);
	ft_putendl("rr");
	if (list->v == 1)
		ft_out_put_steak(list);
}
