/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_float4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:56:17 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/06 17:56:20 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tail(t_plist *list, long double num)
{
	long double	fl;
	long double	flo;
	int			i;
	char		*tail;
	int			n;

	fl = num - (unsigned long long int)num;
	(VAR);
	if (list->correct == 0 && list->a == 0)
		n = 6;
	while (i < n)
	{
		flo = flo / 10;
		i++;
	}
	fl = fl + flo;
	tail = ft_strnew(n + 1);
	tail[0] = '.';
	i = 0;
	while (++i <= n)
	{
		fl = fl * 10;
		tail[i] = "0123456789"[(unsigned long long int)fl % 10];
	}
	return (tail);
}

int		ft_put_minus(t_plist *list, int a)
{
	if (a == -1)
	{
		ft_putchar('-');
		list->col++;
		return (1);
	}
	return (0);
}

void	ft_out_width(t_plist *list, int n, char c)
{
	char	*s;
	int		i;
	int		a;

	a = 0;
	if (list->flag && ft_strchr(list->flag, '-') && ft_strchr(list->flag, ' ')
	&& n != 1 && c != 'n')
		a = -1;
	s = (char *)malloc(sizeof(char) * (list->width - (n + 3) + 1 + a));
	s[(list->width - (n + 3) + a)] = '\0';
	i = 0;
	while (i < (list->width - (n + 3) + a))
		s[i++] = ' ';
	ft_inf_nan(list, n, c, s);
	list->col = list->col + 3 + (int)ft_strlen(s);
	ft_strdel(&s);
}

void	ft_inf(t_plist *list, int n, char c)
{
	if (list->width > (n + 3))
	{
		ft_out_width(list, n, c);
	}
	else
	{
		ft_put_minus(list, -n);
		if (c == 'n')
			ft_putstr("nan");
		else
			ft_putstr("inf");
		list->col = list->col + 3;
	}
}

int		ft_define_nan_inf(t_plist *list, long double num)
{
	float	f1;
	float	f2;

	f1 = 100;
	f2 = 0;
	if (f1 / f2 == num)
	{
		ft_inf(list, 0, 'i');
		return (1);
	}
	f1 = -100;
	if (f1 / f2 == num)
	{
		ft_inf(list, 1, 'i');
		return (1);
	}
	if (num != num)
	{
		ft_inf(list, 0, 'n');
		return (1);
	}
	return (0);
}
