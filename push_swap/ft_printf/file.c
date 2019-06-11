/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:43:37 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/07 16:43:39 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_inf_nan(t_plist *list, int n, char c, char *s)
{
	if (list->flag && ft_strchr(list->flag, '-'))
	{
		if (ft_strchr(list->flag, ' ') && n != 1 && c != 'n')
		{
			list->col++;
			ft_putchar(' ');
		}
		ft_put_minus(list, -n);
		if (c == 'n')
			ft_putstr("nan");
		else
			ft_putstr("inf");
		ft_putstr(s);
	}
	else
	{
		ft_putstr(s);
		(c == 'n') ? ft_putstr("nan") : ft_putstr("inf");
		ft_put_minus(list, -n);
	}
}

void	ft_sokrashenie_int(t_plist *list, char *str, char *s)
{
	if (list->flag && ft_strchr(list->flag, '-'))
		ft_less_antipl_min_int(list, str, s);
	else
		anti_pl_and_min_int(list, str, s);
}

void	cheak_0(t_plist *list, long long int num)
{
	if (num == 0)
		ft_putchar('+');
	list->col++;
}

void	ft_cokr_correct_int(t_plist *list, char *str, char *s, int a)
{
	int	i;

	i = 0;
	while (i < list->width - list->correct)
		s[i++] = ' ';
	while ((unsigned long)i < (unsigned long)list->width - ft_strlen(str) + a)
		s[i++] = '0';
}

void	ft_fill_s_unsigned(t_plist *list, char *str, char *s, int m)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (str[0] == '-')
		a = 1;
	if (m == 1)
	{
		while (i < list->width - list->correct)
			s[i++] = ' ';
		while ((unsigned long)i < (unsigned long)list->width - ft_strlen(str))
			s[i++] = '0';
	}
	if (m == 2)
	{
		while ((unsigned long)i < (unsigned long)list->correct - ft_strlen(str)
		+ a)
			s[list->correct - ft_strlen(str) + a - i++ - 1] = '0';
	}
}
