/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:37:38 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/09 12:37:40 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parspars1(t_plist *list, const char *fmt, int *i, int *a)
{
	char *s;

	if (list->str)
	{
		s = list->str;
		list->str = ft_strjoin(list->str, ft_strsub(fmt, *a, *i - *a + 1));
		ft_strdel(&s);
	}
	else
		list->str = ft_strsub(fmt, *a, *i - *a + 1);
}

void	ft_out_2_func(t_plist *list, t_strlist *slist)
{
	if ((slist->str == NULL || (slist->str && !ft_strchr(slist->str, '-')
								&& !ft_strchr(slist->str, '+'))))
	{
		if (list->flag && (ft_strchr(list->flag, '+')
		|| ft_strchr(list->flag, ' ')) && slist->a != -1)
			ft_out_plus_spac(list, slist->str);
		else
			ft_put_minus(list, -1);
	}
}

void	ft_float_sokrashenie(t_plist *list, t_strlist *slist)
{
	if (list->flag && (ft_strchr(list->flag, '+') || slist->a == -1)
		&& !(ft_strchr(list->flag, '-')))
	{
		if (slist->a == -1)
			slist->str[slist->b - 1] = '-';
		else
			slist->str[slist->b - 1] = '+';
	}
}

void	ft_pars_free(t_plist *list, const char *fmt, int *i, int *a)
{
	char	*s;
	char	*ptr;

	if (list->str)
	{
		s = list->str;
		ptr = ft_strsub(fmt, *a, *i - *a);
		list->str = ft_strjoin(list->str, ptr);
		ft_strdel(&s);
		ft_strdel(&ptr);
	}
	else
	{
		s = list->str;
		list->str = ft_strsub(fmt, *a, *i - *a);
		ft_strdel(&s);
	}
}
