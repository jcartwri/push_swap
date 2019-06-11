/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_float2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:55:52 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/06 17:56:30 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags(t_plist *list, t_strlist *slist)
{
	slist->b = list->width - (int)(ft_strlen(slist->s) + list->correct + 1);
	if (slist->a == -1)
		(slist->b)--;
	if (list->flag && (ft_strchr(list->flag, ' ') ||
	ft_strchr(list->flag, '+')))
	{
		if (ft_strchr(list->flag, '-') && slist->a != -1)
			(slist->b)--;
	}
	if (list->correct == 0 && list->a == 1)
	{
		slist->b += 1;
		if (list->flag && ft_strchr(list->flag, '#') &&
		!ft_strchr(list->flag, '-'))
			(slist->b)--;
	}
	if ((list->flag && ft_strchr(list->flag, '+')) || slist->a == -1)
	{
		if (!ft_strchr(list->flag, '-'))
		{
			if (slist->a == -1)
				(slist->b)++;
		}
	}
}

static void	ft_usage_flag(t_plist *list, t_strlist *slist)
{
	int i;

	i = -1;
	while (++i < (slist->b))
		slist->str[i] = '0';
	if (ft_strchr(list->flag, '+'))
		slist->str[0] = '+';
	if (slist->a == -1)
		slist->str[0] = '-';
}

void		ft_big_width(t_plist *list, t_strlist *slist)
{
	int	i;

	if ((unsigned long)list->width > (ft_strlen(slist->s) + list->correct + 1))
	{
		(FLAG);
		while (++i < (slist->b))
			slist->str[i] = ' ';
		if (list->flag && ft_strchr(list->flag, '0') &&
		!ft_strchr(list->flag, '-'))
			ft_usage_flag(list, slist);
		else
			ft_float_sokrashenie(list, slist);
		if (list->flag && ft_strchr(list->flag, '#') &&
		ft_strchr(list->flag, '-') && list->correct == 0)
			slist->str[0] = '.';
	}
}

static void	ft_body_coorect0_1(t_plist *list, t_strlist *slist)
{
	if (ft_strchr(list->flag, '+') || ft_strchr(list->flag, ' '))
	{
		if (ft_strchr(list->flag, '+') && slist->a == -1)
		{
			if (slist->str == NULL || (slist->str &&
			!ft_strchr(slist->str, '-')))
				slist->b = (ft_put_minus(list, slist->a) == 1) ? -100
						: slist->b;
		}
		else
			ft_out_plus_spac(list, slist->str);
	}
	if (ft_strchr(list->flag, ' ') && slist->str && ft_strchr(slist->str, '.')
	&& slist->a != -1)
		(SPACE);
	else
	{
		if (ft_strchr(list->flag, ' ') && ft_strchr(list->flag, '-') &&
		(list->correct == 0 && list->a == 1) && slist->a != -1)
			(SPACE);
	}
	if (slist->b != -100 && (slist->str == NULL || (slist->str &&
	!ft_strchr(slist->str, '-'))))
		ft_put_minus(list, slist->a);
}

void		ft_body_coorect0(t_plist *list, t_strlist *slist)
{
	if (list->flag && ft_strchr(list->flag, '-'))
	{
		ft_body_coorect0_1(list, slist);
		ft_putstr(slist->s);
		ft_str_istina(list, slist->str);
		list->col = list->col + (int)ft_strlen(slist->s);
	}
	else
	{
		ft_str_istina(list, slist->str);
		if (list->flag && (ft_strchr(list->flag, ' ') ||
		ft_strchr(list->flag, '+')) && slist->a != -1)
			ft_out_plus_spac(list, slist->str);
		if (slist->str == NULL || (slist->str && !ft_strchr(slist->str, '-')))
			ft_put_minus(list, slist->a);
		ft_putstr(slist->s);
		if (list->flag && ft_strchr(list->flag, '#'))
		{
			ft_putchar('.');
			list->col++;
		}
		list->col = list->col + (int)ft_strlen(slist->s);
	}
}
