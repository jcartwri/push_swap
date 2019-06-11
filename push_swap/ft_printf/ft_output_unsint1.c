/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_unsint1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:38:15 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/05 17:38:17 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pl1uns(t_plist *list, char *str, char *s)
{
	int	i;

	if (list->flag && ft_strchr(list->flag, '0') && (list->correct == 0))
	{
		i = -1;
		while (s[++i])
			s[i] = '0';
		if (list->flag && ft_strchr(list->flag, ' '))
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

void		anti_pl_and_min_uns(t_plist *list, char *str, char *s)
{
	int	i;
	int	a;

	if (ft_pl1uns(list, str, s) == -1)
		return ;
	a = 0;
	if (str[0] == '-')
		a = 1;
	if ((list->correct > ((int)ft_strlen(str) - a)) && (str[0] == '-'))
	{
		ft_putchar('-');
		ft_putstr(s);
		i = 0;
		while (str[++i])
			ft_putchar(str[i]);
		list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str);
		return ;
	}
	ft_putstr(s);
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str);
}

static void	ft_less_ant_uns(t_plist *list, char *str, char *s, int i)
{
	if (ft_strchr(list->flag, ' '))
	{
		list->col = list->col + 1;
		ft_putchar(' ');
	}
	i = 0;
	while (s[i] != '0' && s[i])
		i++;
	while (s[i] == '0' && s[i])
	{
		list->col = list->col + 1;
		ft_putchar(s[i++]);
	}
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(str);
	i = 0;
	while (s[i] == ' ' && s[i])
	{
		list->col = list->col + 1;
		ft_putchar(s[i++]);
	}
}

void		ft_less_antipl_min_uns(t_plist *list, char *str, char *s)
{
	int	i;

	i = 0;
	if (list->correct > 0 && (unsigned long)list->correct > ft_strlen(str))
	{
		ft_less_ant_uns(list, str, s, i);
		return ;
	}
	if (list->flag && ft_strchr(list->flag, ' '))
	{
		list->col = list->col + 1;
		ft_putchar(' ');
	}
	ft_putstr(str);
	ft_putstr(s);
	list->col = list->col + (int)ft_strlen(s);
	list->col = list->col + (int)ft_strlen(str);
}

char		*ft_less_pl_correct_uns(t_plist *list, char *str)
{
	int		i;
	int		a;
	char	*s;

	s = ft_strnew(list->width - ft_strlen(str));
	a = (int)(list->width - ft_strlen(str));
	i = -1;
	while (++i < a)
		s[i] = ' ';
	return (s);
}
