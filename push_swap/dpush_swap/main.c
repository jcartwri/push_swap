/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:59:53 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/16 10:59:55 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(t_ablist *list, int size, char steck)
{
	int	meredian;
	int	begin;

	if (steck == 'a')
	{
		if (ft_cheak_stop_a(list, size) != -1)
			return (size);
		meredian = ft_find_meridian(size, list->a);
		begin = ft_get_begin_a(list->a, size, meredian);
		return (ft_break_array_half_a(list, meredian, begin, size));
	}
	if (steck == 'b')
	{
		meredian = ft_find_meridian(size, list->b);
		begin = ft_get_begin_b(list->b, size, meredian);
		return (ft_break_array_half_b(list, meredian, begin, size));
	}
	return (0);
}

static void	ft_sorted_elem_a(t_ablist *list, int size)
{
	while (size > 0)
	{
		if (size == 1)
			return ;
		if (list->a[0] > list->a[1])
			ft_sab(list);
		if (size == 2)
			return ;
		else if (size == 3)
		{
			size = ft_body_sort_a(list, size);
		}
	}
}

void		ft_sorted_elem_b(t_ablist *list, int size)
{
	while (size > 0)
	{
		if (size == 1)
		{
			ft_pa(list);
			return ;
		}
		if (list->b[0] < list->b[1])
			ft_sba(list);
		if (size == 2)
		{
			ft_pa(list);
			ft_pa(list);
			return ;
		}
		else if (size == 3)
		{
			size = ft_commands(list, size);
		}
	}
}

void		sorted(t_ablist *list, int size, char steck)
{
	int pindx;

	if (size <= 3)
	{
		if (steck == 'a')
			ft_sorted_elem_a(list, size);
		else
			ft_sorted_elem_b(list, size);
	}
	else
	{
		if (steck == 'a')
		{
			pindx = partition(list, size, 'a');
			if (pindx != size)
				(SORT);
		}
		else
		{
			pindx = partition(list, size, 'b');
			sorted(list, size - pindx, 'a');
			sorted(list, pindx, 'b');
		}
	}
}

int			main(int argc, char **argv)
{
	t_ablist	*list;
	int			l;
	char		*str;

	if (ft_strcmp(argv[argc - 1], "-v") == 0)
		argc--;
	if ((l = ft_checker(argc, argv)) == -1)
		(ERROR);
	if (l == 0)
		(NOELEMENT);
	list = ft_creat_ablist(l);
	if (argv[argc] && ft_strcmp(argv[argc], "-v") == 0)
		list->v = 1;
	if (ft_fill_array(list, argc, argv) == -1)
	{
		ft_ablist_int_del(list);
		(ERROR);
	}
	if (ft_cheak_sorted_a(list->a, list->lena) == 1)
		return (0);
	if (ft_cheak_sorted_b(list->a, list->lena) == 1)
		return (ft_revers_a(list));
	sorted(list, l, 'a');
	ft_ablist_int_del(list);
	return (0);
}
