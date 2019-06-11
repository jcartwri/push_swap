/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_unsint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:27:46 by jcartwri          #+#    #+#             */
/*   Updated: 2019/02/22 14:27:49 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_correct(t_plist *list, char *str)
{
	char	*s;
	int		a;

	ft_output_liststr(list);
	s = NULL;
	if (list->correct > 0 && ((unsigned long)list->correct >
	ft_strlen(str)))
	{
		if (list->width > list->correct)
		{
			s = ft_strnew(list->width - ft_strlen(str));
			ft_fill_s_unsigned(list, str, s, 1);
		}
		else
		{
			a = 0;
			if (str[0] == '-')
				a = 1;
			s = ft_strnew(list->correct - ft_strlen(str) + a);
			ft_fill_s_unsigned(list, str, s, 2);
		}
	}
	return (s);
}

static void	ft_str_more_width(t_plist *list, char *str, char *s)
{
	if (list->width == '\0' || (ft_strlen(str) >= (unsigned long)list->width))
	{
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

static int	ft_zero(t_plist *list, unsigned long long int num)
{
	int		i;
	char	*s;

	if (list->correct == 0 && num == 0 && list->corr0 == 0)
	{
		if (list->width > 0)
		{
			s = ft_strnew(list->width);
			i = -1;
			while (++i < list->width)
				s[i] = ' ';
			ft_putstr(s);
			list->col = list->col + (int)ft_strlen(s);
		}
		return (1);
	}
	return (0);
}

static void	ft_cause_uns(t_plist *list, char *str, char *s)
{
	if (list->flag && ft_strchr(list->flag, '+'))
	{
		if (!(list->correct > 0 && (unsigned long)list->correct >
		ft_strlen(str)))
			s = ft_less_pl_correct_uns(list, str);
		if (list->flag && ft_strchr(list->flag, '-'))
			ft_less_pl_min_uns(list, str, s);
		else
			ft_less_pl_antimin_uns(list, str, s);
	}
	else
	{
		if (!(list->correct > 0 && (unsigned long)list->correct >
		ft_strlen(str)))
			s = ft_less_antipl_corr_uns(list, str);
		if (list->flag && ft_strchr(list->flag, '-'))
			ft_less_antipl_min_uns(list, str, s);
		else
			anti_pl_and_min_uns(list, str, s);
	}
}

void		ft_output_unsint(t_plist *list, unsigned long long int num)
{
	char	*str;
	char	*s;

	str = ft_ulltoa(num);
	s = ft_correct(list, str);
	if (ft_zero(list, num) == 1)
		return ;
	if (list->width == 0 || (ft_strlen(str) >= (unsigned long)list->width))
		ft_str_more_width(list, str, s);
	else
		ft_cause_uns(list, str, s);
	ft_strdel(&s);
	ft_strdel(&str);
}
