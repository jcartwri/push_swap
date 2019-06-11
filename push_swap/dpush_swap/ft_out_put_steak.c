/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_put_steak.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:32:48 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/28 19:33:14 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_print_a(t_ablist *list, int k)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < k)
	{
		ft_printf("%i\n", list->a[i]);
		i++;
	}
	while (j < list->lenb)
	{
		ft_printf("%-11i\t%i\n", list->a[i], list->b[j]);
		i++;
		j++;
	}
	return (1);
}

static int	ft_print_b(t_ablist *list, int k)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	k = k * (-1);
	while (i < k)
	{
		ft_printf("\t        %i\n", list->b[i]);
		i++;
	}
	while (j < list->lena)
	{
		ft_printf("%-11i\t%i\n", list->a[j], list->b[i]);
		i++;
		j++;
	}
	return (1);
}

void		ft_out_put_steak(t_ablist *list)
{
	int	k;

	k = list->lena - list->lenb;
	ft_printf("-----------\t-----------\n");
	ft_printf("***********\t***********\n");
	if (k >= 0)
	{
		ft_print_a(list, k);
	}
	else
	{
		ft_print_b(list, k);
	}
	ft_printf("***********\t***********\n");
	ft_printf("%c         \t%c\n", 'a', 'b');
	ft_printf("-----------\t-----------\n");
}
