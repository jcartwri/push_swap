/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:00:02 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/04 15:00:05 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pars_i1(t_plist *list, const char *fmt, int i)
{
	int a;

	if ((fmt[i] == '-') || (fmt[i] == '+') || (fmt[i] == ' ') || (fmt[i] == '#')
	|| (fmt[i] == '0'))
	{
		a = i;
		while ((fmt[i] == '-') || (fmt[i] == '+') || (fmt[i] == ' ')
		|| (fmt[i] == '#') || (fmt[i] == '0'))
			i++;
		list->flag = ft_strsub(fmt, a, i - a);
	}
	if (fmt[i] >= '0' && fmt[i] <= '9')
		list->width = ft_atoi(fmt + i++);
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	if (fmt[i] == '.')
	{
		list->correct = ft_atoi(fmt + ++i);
		list->a = 1;
		if (fmt[i] == '0' || !(fmt[i] > '0' && fmt[i] < '9'))
			list->corr0 = 0;
	}
	while (fmt[i] >= '0' && fmt[i] <= '9')
		i++;
	return (i);
}

static int	ft_pars_i2_pars(t_plist *list, const char *fmt, int *i, int *a)
{
	if (fmt[*i] == '%' && fmt[*i + 1] == '%')
	{
		ft_parspars1(list, fmt, i, a);
		*i = *i + 2;
		*a = *i;
	}
	if (fmt[*i] == '\0')
	{
		ft_pars_free(list, fmt, i, a);
		return (-1);
	}
	return (1);
}

static int	ft_pars_i2(t_plist *list, const char *fmt, int i, int *a)
{
	char	*s;

	if (fmt[i] == '%' && fmt[i + 1] == '%')
	{
		if (list->str)
		{
			s = list->str;
			list->str = ft_strjoin(list->str, "%");
			ft_strdel(&s);
		}
		else
			list->str = ft_strdup("%");
		i = i + 2;
	}
	*a = i;
	while (fmt[i] != '%' && fmt[i])
	{
		i++;
		if (ft_pars_i2_pars(list, fmt, &i, a) == -1)
			break ;
	}
	return (i);
}

static int	ft_cheak_on_null(t_plist *list, const char *fmt, int *i)
{
	if (fmt[(*i)++] == '\0')
	{
		list->col = (int)ft_strlen(list->str);
		ft_putstr(list->str);
		return (-1);
	}
	return (1);
}

int			ft_parsing(t_plist *list, const char *fmt, int i)
{
	int	a;

	if ((fmt[i] || fmt[i] != '%'))
	{
		while (fmt[i])
		{
			i = ft_pars_i2(list, fmt, i, &a);
			if (fmt[i] == '\0')
				break ;
			if (a != i)
			{
				if (list->str != NULL)
					list->str = ft_strjoin(list->str, ft_strsub(fmt, a, i - a));
				else
					list->str = ft_strsub(fmt, a, i - a);
			}
			if (fmt[i] == '%' && fmt[i + 1] != '%')
				break ;
		}
		if (ft_cheak_on_null(list, fmt, &i) == -1)
			return (-1);
	}
	i = ft_pars_i1(list, fmt, i);
	return (i);
}
