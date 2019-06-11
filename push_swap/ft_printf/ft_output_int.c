/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 19:14:49 by jcartwri          #+#    #+#             */
/*   Updated: 2019/02/07 19:14:52 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_str_more_width_flag(t_plist *list, long long int num)
{
	if (list->flag)
	{
		if ((ft_strchr(list->flag, '+') && ft_strchr(list->flag, ' ')) ||
		(ft_strchr(list->flag, '+') && (!(ft_strchr(list->flag, '-')))))
		{
			if (num >= 0)
			{
				list->col = list->col + 1;
				ft_putchar('+');
			}
		}
		else
		{
			if (list->flag && ft_strchr(list->flag, ' ') && num >= 0)
			{
				ft_putchar(' ');
				list->col = list->col + 1;
			}
		}
	}
}

static void	ft_str_more_width(t_plist *list, long long int num, char *str,
		char *s)
{
	if (list->width == '\0' || (ft_strlen(str) >= (unsigned long)list->width))
	{
		ft_str_more_width_flag(list, num);
		if (list->correct > 0 && (unsigned long)list->correct > ft_strlen(str))
		{
			if (str[0] == '-')
			{
				ft_putchar('-');
				list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str);
				ft_putstr(s);
				ft_putstr(str + 1);
				return ;
			}
			ft_putstr(s);
			list->col = list->col + (int)ft_strlen(s);
		}
		list->col = list->col + (int)ft_strlen(str);
		ft_putstr(str);
	}
}

static char	*ft_less_pl_correct(t_plist *list, char *str)
{
	int		i;
	int		a;
	char	*s;

	s = ft_strnew(list->width - ft_strlen(str));
	a = list->width - (int)ft_strlen(str);
	i = -1;
	while (++i < a)
		s[i] = ' ';
	return (s);
}

static void	ft_cause_func(t_plist *list, long long int num, char *str, char *s)
{
	char	*a;

	a = NULL;
	if (list->flag && ft_strchr(list->flag, '+'))
	{
		if (!(list->correct > 0 && (unsigned long)list->correct >
		ft_strlen(str)))
		{
			s = ft_less_pl_correct(list, str);
			a = s;
		}
		if (list->flag && ft_strchr(list->flag, '-'))
			ft_less_pl_min_int(list, str, s, num);
		else
			ft_less_pl_antimin_int(list, str, s, num);
	}
	else
	{
		if (!(list->correct > 0 && (unsigned long)list->correct >
		ft_strlen(str)))
			(CAUSE);
		ft_sokrashenie_int(list, str, s);
	}
	ft_strdel(&a);
}

void		ft_output_int(t_plist *list, long long int num)
{
	char	*str;
	char	*s;

	str = ft_lltoa(num);
	s = ft_correct_int(list, str);
	str = ft_zero_int(list, num, str);
	if (list->width == 0 || (ft_strlen(str) >= (unsigned long)list->width))
		ft_str_more_width(list, num, str, s);
	else
		ft_cause_func(list, num, str, s);
	ft_strdel(&s);
	if (str[0] != '\0')
		ft_strdel(&str);
}
