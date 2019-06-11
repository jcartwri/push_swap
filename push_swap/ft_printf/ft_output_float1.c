/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_float1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:55:41 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/06 17:56:35 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_my_little_horror(t_plist *list, t_strlist *slist)
{
	if (list->flag && !ft_strchr(list->flag, '-'))
		ft_str_istina(list, slist->str);
	if (list->flag && (ft_strchr(list->flag, '+') || ft_strchr(list->flag, ' '))
	&& slist->a != -1)
	{
		if (slist->str == NULL || (slist->str && !ft_strchr(slist->str, '-') &&
		!ft_strchr(slist->str, '+')))
			ft_out_plus_spac(list, slist->str);
	}
	if (slist->str == NULL || (slist->str && !ft_strchr(slist->str, '-')))
		ft_put_minus(list, slist->a);
	ft_putstr(slist->s);
	ft_putstr(slist->cor);
	if (list->flag && ft_strchr(list->flag, '-'))
		ft_str_istina(list, slist->str);
	list->col = list->col + (int)ft_strlen(slist->s) +
			(int)ft_strlen(slist->cor);
}

static void	ft_my_big_horror(t_plist *list, t_strlist *slist)
{
	int i;

	if (slist->a == -1 && slist->str && !ft_strchr(slist->str, '-'))
	{
		i = 0;
		while (slist->str[i] && slist->str[i] == ' ')
			i++;
		slist->str[i - 1] = '-';
	}
	if (list->flag && ft_strchr(list->flag, ' ') && slist->str &&
	ft_strchr(slist->str, '0') && !ft_strchr(list->flag, '+') && slist->a != -1)
		slist->str[0] = ' ';
	ft_putstr(slist->str);
	if ((list->flag && (ft_strchr(list->flag, '+') ||
	(ft_strchr(list->flag, ' ') && (slist->str == NULL)))) || slist->a == -1)
		ft_out_2_func(list, slist);
	ft_putstr(slist->s);
	ft_putstr(slist->cor);
	list->col = list->col + (int)ft_strlen(slist->s) +
			(int)ft_strlen(slist->cor) + (int)ft_strlen(slist->str);
}

static void	ft_my_middle_horror(t_plist *list, t_strlist *slist)
{
	if ((list->flag && (ft_strchr(list->flag, '+') ||
	ft_strchr(list->flag, ' '))) && slist->a != -1)
	{
		if (ft_out_plus_spac(list, slist->str) == 0)
		{
			if (list->flag && ft_strchr(list->flag, ' ') &&
			ft_strchr(list->flag, '-'))
			{
				list->col++;
				ft_putchar(' ');
			}
		}
	}
	if (slist->str == NULL || (slist->str && !ft_strchr(slist->str, '-')))
		ft_put_minus(list, slist->a);
	ft_putstr(slist->s);
	ft_putstr(slist->cor);
	ft_putstr(slist->str);
	list->col = list->col + (int)ft_strlen(slist->s) +
			(int)ft_strlen(slist->cor) + (int)ft_strlen(slist->str);
}

void		ft_horror(t_plist *list, t_strlist *slist, long double num)
{
	slist->cor = ft_tail(list, num);
	if ((unsigned long)list->width <= (ft_strlen(slist->s) +
	ft_strlen(slist->cor) + 1))
	{
		ft_my_little_horror(list, slist);
		return ;
	}
	else
	{
		if (list->flag && ft_strchr(list->flag, '-'))
		{
			ft_my_middle_horror(list, slist);
			return ;
		}
		ft_my_big_horror(list, slist);
	}
}

long double	ft_round_correct(t_plist *list, long double num)
{
	long double	fl;
	long double	flo;
	int			i;
	int			n;

	fl = num - (unsigned long long int)num;
	i = 0;
	flo = 0.5;
	n = list->correct;
	while (i < n)
	{
		flo = flo / 10;
		i++;
	}
	fl = fl + flo + (unsigned long long int)num;
	return (fl);
}
