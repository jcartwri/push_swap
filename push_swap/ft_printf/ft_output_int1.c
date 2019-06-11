/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:23:36 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/04 20:23:38 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_less_pl1_assis(t_plist *list, char *str, char *s, int i)
{
	char	*a;

	if (list->correct > 0 && (unsigned long)list->correct > ft_strlen(str))
	{
		if (list->correct >= list->width && list->correct >=
		(int)ft_strlen(str))
		{
			list->col++;
			ft_putchar('-');
		}
		else
		{
			i = 0;
			while (s[i] == ' ')
				i++;
			s[i - 1] = '-';
		}
		a = ft_strsub(str, 1, ft_strlen(str) - 1);
		ft_putstr(s);
		ft_putstr(a);
		list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(a);
		ft_strdel(&a);
		return (-1);
	}
	return (1);
}

static int	ft_less_pl1(t_plist *list, char *str, char *s, long long int num)
{
	int	i;

	i = 0;
	if (num >= 0)
	{
		if (list->correct > 0 && (unsigned long)list->correct > ft_strlen(str))
		{
			i = 0;
			if (num > 0 || (list->width > list->correct))
			{
				while (s[i] == ' ' && s[i])
					i++;
				s[i - 1] = '+';
			}
			else
				cheak_0(list, num);
		}
		else
			s[list->width - ft_strlen(str) - 1] = '+';
	}
	else
		return (ft_less_pl1_assis(list, str, s, i));
	return (1);
}

int			ft_less_pl2(t_plist *list, char *str, char *s)
{
	int	i;

	if (list->flag && ft_strchr(list->flag, '0') && (list->correct == 0)
	&& (str[0] == '-'))
	{
		ft_putchar('-');
		ft_putstr(s);
		list->col = list->col + 1 + (int)ft_strlen(s);
		i = 0;
		while (str[++i])
		{
			ft_putchar(str[i]);
			list->col = list->col + 1;
		}
		return (-1);
	}
	if (str[0] != '0' && str[0] != '-' && list->width <= list->correct &&
	ft_strchr(list->flag, '+'))
	{
		ft_putchar('+');
		list->col = list->col + 1;
	}
	return (1);
}

void		ft_less_pl_antimin_int(t_plist *list, char *str, char *s,
		long long int num)
{
	int	i;

	if (list->flag && ft_strchr(list->flag, '0') && (list->correct == 0))
	{
		i = -1;
		while (s[++i])
			s[i] = '0';
		if (ft_strchr(list->flag, ' '))
			s[0] = ' ';
		if (num >= 0)
			s[0] = '+';
	}
	else
	{
		if (ft_less_pl1(list, str, s, num) == -1)
			return ;
	}
	if (ft_less_pl2(list, str, s) == -1)
		return ;
	ft_putstr(s);
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str);
}

char		*ft_less_antipl_corr_int(t_plist *list, char *str)
{
	int		a;
	int		i;
	char	*s;

	a = 0;
	if (list->flag && ft_strchr(list->flag, ' ') && list->corr0 == -1 &&
	str[0] != '-' && str[0] != '0')
		a = -1;
	s = ft_strnew(list->width - ft_strlen(str) + a);
	a = list->width - (int)ft_strlen(str) + a;
	i = -1;
	while (++i < a)
		s[i] = ' ';
	if (list->flag && ft_strchr(list->flag, '0') && !ft_strchr(list->flag, '-'))
	{
		i = -1;
		while (++i < a)
			s[i] = '0';
	}
	return (s);
}
