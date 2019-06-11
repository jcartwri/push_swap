/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:23:46 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/04 20:23:50 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_less_pl_min_asistent(t_plist *list, char *str, char *s, int a)
{
	int	i;

	if (ft_strchr(list->flag, '+'))
	{
		a = 1;
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
	while (s[i + a] == ' ' && s[i])
	{
		list->col = list->col + 1;
		ft_putchar(s[i++]);
	}
}

void		ft_less_pl_min_int(t_plist *list, char *str, char *s,
		long long int num)
{
	int	a;

	a = 0;
	if (list->correct > 0 && (unsigned long)list->correct > ft_strlen(str))
	{
		ft_less_pl_min_asistent(list, str, s, a);
		return ;
	}
	if (num >= 0)
		ft_putchar('+');
	ft_putstr(str);
	if (num >= 0)
		ft_putstr(s + 1);
	else
		ft_putstr(s);
	list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str);
}

static void	ft_less1(t_plist *list, char *str, char *s, int i)
{
	if (ft_strchr(list->flag, ' '))
	{
		if (((list->width > (int)ft_strlen(str) && ft_strchr(list->flag, '0'))
		|| (list->correct > (int)ft_strlen(str))) && str[0] == '-')
			ft_putchar(str[0]);
		else
			(SPACE);
	}
	i = 0;
	while (s[i] != '0' && s[i])
		i++;
	while (s[i] == '0' && s[i])
		(SYMBOL);
	if ((((list->width > (int)ft_strlen(str) && ft_strchr(list->flag, '0')) ||
	(list->correct > (int)ft_strlen(str))) && str[0] == '-'))
		ft_putstr(str + 1);
	else
		ft_putstr(str);
	list->col = list->col + (int)ft_strlen(str);
	i = 0;
	while (s[i] == ' ' && s[i])
		(SYMBOL);
}

void		ft_less_antipl_min_int(t_plist *list, char *str, char *s)
{
	int		i;
	char	*a;

	i = 0;
	if (list->correct > 0 && (unsigned long)list->correct > ft_strlen(str))
	{
		ft_less1(list, str, s, i);
		return ;
	}
	if (list->flag && ft_strchr(list->flag, ' ') && str[0] != '-'
	&& str[0] != '\0')
	{
		if (ft_strchr(list->flag, '-') && list->width > (int)ft_strlen(str)
		&& str[0] == '0')
		{
			a = s;
			s = ft_strsub(s, 1, ft_strlen(s) - 1);
			ft_strdel(&a);
		}
		list->col = list->col + 1;
		ft_putchar(' ');
	}
	ft_putstr(str);
	ft_putstr(s);
	list->col = list->col + (int)ft_strlen(s) + (int)ft_strlen(str);
}

char		*ft_zero_int(t_plist *list, long long int num, char *str)
{
	if (list->correct == 0 && num == 0 && list->corr0 == 0)
	{
		return (ft_strnew(0));
	}
	return (str);
}
