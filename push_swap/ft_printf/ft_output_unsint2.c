/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_unsint2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:26:23 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/05 20:26:25 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_strless_pl_min_uns(t_plist *list, char *str, char *s, int *a)
{
	int	i;

	if (ft_strchr(list->flag, '+'))
	{
		*a = 1;
		list->col = list->col + 1;
		ft_putchar('+');
	}
	i = 0;
	while (s[i] != '0' && s[i])
		i++;
	while (s[i] == '0' && s[i])
	{
		list->col = list->col + 1;
		ft_putchar(s[i++]);
	}
	list->col = list->col + (int)ft_strlen(str);
	ft_putstr(str);
	i = 0;
	while (s[i + *a] == ' ' && s[i])
	{
		list->col = list->col + 1;
		ft_putchar(s[i++]);
	}
}

void		ft_less_pl_min_uns(t_plist *list, char *str, char *s)
{
	int	a;

	a = 0;
	if (list->correct > 0 && (unsigned long)list->correct > ft_strlen(str))
	{
		ft_strless_pl_min_uns(list, str, s, &a);
		return ;
	}
	ft_putstr(str);
	ft_putstr(s);
	list->col = list->col + (int)ft_strlen(s);
	list->col = list->col + (int)ft_strlen(str);
}

static void	ft_less_pl_uns(t_plist *list, char *str, char *s, int i)
{
	if (list->flag && ft_strchr(list->flag, '0') && (list->correct == 0))
	{
		i = -1;
		while (s[++i])
			s[i] = '0';
		if (ft_strchr(list->flag, ' '))
			s[0] = ' ';
	}
	else
	{
		if (list->correct > 0 && (unsigned long)list->correct > ft_strlen(str))
		{
			i = 0;
			while (s[i] == ' ' && s[i])
				i++;
		}
	}
}

void		ft_less_pl_antimin_uns(t_plist *list, char *str, char *s)
{
	int	i;

	i = 0;
	ft_less_pl_uns(list, str, s, i);
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
		return ;
	}
	ft_putstr(s);
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str);
}

char		*ft_less_antipl_corr_uns(t_plist *list, char *str)
{
	int		a;
	int		i;
	char	*s;

	a = 0;
	s = ft_strnew(list->width - ft_strlen(str)) + a;
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
