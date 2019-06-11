/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:23:56 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/04 20:23:59 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pl1(t_plist *list, char *str, char *s)
{
	int i;

	if (list->flag && ft_strchr(list->flag, '0') && (list->correct == 0))
	{
		i = -1;
		while (s[++i])
			s[i] = '0';
		if (list->flag && ft_strchr(list->flag, ' ') && list->corr0 != -1)
			s[0] = ' ';
	}
	if ((list->flag && ft_strchr(list->flag, '0') && (list->correct == 0))
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
	return (1);
}

static int	ft_pl2(t_plist *list, char *str, char *s, int a)
{
	int	i;

	if ((list->correct > ((int)ft_strlen(str) - a)) && (str[0] == '-'))
	{
		if (list->width <= list->correct && list->correct >=
		(int)ft_strlen(str))
			(MINUS1);
		else
		{
			a = 1;
			i = 0;
			while (s[i] == ' ')
				i++;
			if (s[0] == '0' && ft_strchr(list->flag, '0') && str[0] == '-'
			&& !ft_strchr(list->flag, '-') && list->width > list->correct)
				(MINUS2);
			s[i - 1] = '-';
		}
		(VARIB);
		while (str[++i])
			ft_putchar(str[i]);
		list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str) - a;
		return (-1);
	}
	return (1);
}

static void	ft_pl3(t_plist *list, char *str)
{
	if (list->flag && ft_strchr(list->flag, ' ') && str[0] != '-'
	&& str[0] != '\0')
	{
		if (str[0] == '0')
		{
			if (list->width <= list->correct)
			{
				ft_putchar(' ');
				list->col = list->col + 1;
			}
		}
		else
		{
			if (!(list->width > list->correct && list->correct >
			(int)ft_strlen(str) && list->corr0 != 0))
			{
				ft_putchar(' ');
				list->col = list->col + 1;
			}
		}
	}
}

void		anti_pl_and_min_int(t_plist *list, char *str, char *s)
{
	int a;

	if (ft_pl1(list, str, s) == -1)
		return ;
	a = 0;
	if (str[0] == '-')
		a = 1;
	if (ft_pl2(list, str, s, a) == -1)
		return ;
	ft_pl3(list, str);
	if (list->width > (int)ft_strlen(str) && list->a == 0 && list->flag &&
	ft_strchr(list->flag, ' ') && ft_strchr(list->flag, '0') &&
	!ft_strchr(list->flag, '-') && (str[0] == '-' || str[0] == '0'))
		s[0] = ' ';
	ft_putstr(s);
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str);
}

char		*ft_correct_int(t_plist *list, char *str)
{
	int		i;
	char	*s;
	int		a;

	(VARIB1);
	a = (str[0] == '-') ? 1 : a;
	if (list->correct > 0 && ((unsigned long)list->correct >
	ft_strlen(str)))
	{
		if (list->width > list->correct)
		{
			s = ft_strnew(list->width - ft_strlen(str) + a);
			ft_cokr_correct_int(list, str, s, a);
		}
		else
		{
			s = ft_strnew(list->correct - ft_strlen(str) + a);
			i = 0;
			while ((unsigned long)i < (unsigned long)list->correct -
			ft_strlen(str) + a)
				s[list->correct - ft_strlen(str) + a - i++ - 1] = '0';
		}
	}
	return (s);
}
