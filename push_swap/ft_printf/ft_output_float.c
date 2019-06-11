/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:25:03 by jcartwri          #+#    #+#             */
/*   Updated: 2019/02/14 21:25:06 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strnewhead(t_plist *list, long double *num, t_strlist *slist)
{
	float	fl;

	ft_output_liststr(list);
	slist->a = ft_sign_null((double)*num);
	if (ft_define_nan_inf(list, *num) == 1)
		return (-1);
	if (*num < 0)
		(NEGATIVE);
	fl = *num;
	if (list->a == 1)
	{
		if (list->correct == 0)
			fl = ft_round(*num);
		else
			fl = ft_round_correct(list, *num);
	}
	if (fl > (unsigned long)-1)
		ft_get_head(*num, slist);
	else
		ft_get_head(fl, slist);
	if (slist->s[0] == '\0')
		(DEL);
	return (1);
}

static void	ft_corect_nety_minus(t_plist *list, t_strlist *slist, char *str)
{
	int		b;
	int		i;
	char	*s;

	b = list->width - (int)(ft_strlen(slist->s) + ft_strlen(slist->cor));
	if (ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+')
	|| slist->a == -1)
	{
		b = list->width - (int)(ft_strlen(slist->s) +
				ft_strlen(slist->cor) + 1);
		ft_put_minus(list, slist->a);
		if (slist->a != -1)
			ft_out_plus_spac(list, str);
	}
	s = ft_strnew(b);
	i = -1;
	while (++i < b)
		s[i] = ' ';
	ft_putstr(slist->s);
	ft_putstr(slist->cor);
	ft_putstr(s);
	list->col = list->col + (int)ft_strlen(slist->s) +
			(int)ft_strlen(slist->cor) + (int)ft_strlen(s);
	ft_strdel(&s);
}

static void	ft_corect_nety_plus(t_plist *list, t_strlist *slist)
{
	char	*str;
	int		b;
	int		i;

	b = list->width - (int)(ft_strlen(slist->s) + ft_strlen(slist->cor));
	str = ft_strnew(b);
	i = -1;
	while (++i < b)
		str[i] = ' ';
	if (list->flag && ft_strchr(list->flag, '0'))
	{
		i = -1;
		while (++i < b)
			str[i] = '0';
		str[0] = (ft_strchr(list->flag, ' ')) ? ' ' : str[0];
	}
	if (list->flag && (ft_strchr(list->flag, '+') || slist->a == -1))
	{
		b = (ft_strchr(list->flag, '0')) ? 1 : b;
		if (slist->a == -1)
			str[b - 1] = '-';
		else
			str[b - 1] = '+';
	}
	(SF);
}

static void	ft_corect_nety(t_plist *list, char *str, t_strlist *slist)
{
	if ((unsigned long)list->width <= (ft_strlen(slist->s) +
	ft_strlen(slist->cor)))
	{
		if (list->flag && (ft_strchr(list->flag, ' ') ||
		ft_strchr(list->flag, '+')) && slist->a != -1)
			ft_out_plus_spac(list, str);
		ft_put_minus(list, slist->a);
		ft_putstr(slist->s);
		ft_putstr(slist->cor);
		list->col = list->col + (int)ft_strlen(slist->s);
		list->col = list->col + (int)ft_strlen(slist->cor);
	}
	else
	{
		if (list->flag && ft_strchr(list->flag, '-'))
			ft_corect_nety_minus(list, slist, str);
		else
		{
			ft_corect_nety_plus(list, slist);
			ft_putstr(slist->s);
			ft_putstr(slist->cor);
			list->col = list->col + (int)ft_strlen(slist->s) +
					(int)ft_strlen(slist->cor);
		}
	}
}

void		ft_output_float(t_plist *list, long double num)
{
	t_strlist	*slist;

	slist = NULL;
	slist = ft_create_strlist(slist);
	if (ft_strnewhead(list, &num, slist) == -1)
		(OFF);
	if (list->correct == 0 && list->a == 0)
	{
		slist->cor = ft_tail(list, num);
		ft_corect_nety(list, slist->str, slist);
		freeslist(slist);
		return ;
	}
	else
	{
		ft_big_width(list, slist);
		if (list->correct == 0)
			(OFFF);
		else
			ft_horror(list, slist, num);
	}
	freeslist(slist);
}
