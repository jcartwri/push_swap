/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_float3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:56:02 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/06 17:56:25 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_sign_null(double num)
{
	long val;

	val = ((*(long*)(&num)) >> 63);
	if (num == 0)
	{
		if (val == -1)
			return (-1);
	}
	return (1);
}

void		ft_get_head(long double num, t_strlist *slist)
{
	unsigned long long	i;
	unsigned long long	j;
	long double			fl;

	i = 0;
	fl = num;
	if (slist->s)
		ft_strdel(&(slist->s));
	if (fl == 1)
		slist->s = ft_strdup("1");
	while (fl > 1)
	{
		fl /= 10;
		i++;
	}
	if (!(slist->s = (char *)malloc(sizeof(char) * (i + 1))))
		return ;
	slist->s[i] = '\0';
	j = 0;
	while (j < i)
	{
		slist->s[j++] = (char)('0' + ((unsigned long long int)((fl * 10))
				% 10));
		fl *= 10;
	}
}

void		ft_str_istina(t_plist *list, char *str)
{
	if (str != NULL)
	{
		list->col = list->col + (int)ft_strlen(str);
		ft_putstr(str);
	}
}

int			ft_out_plus_spac(t_plist *list, char *str)
{
	if (ft_strchr(list->flag, '+'))
	{
		ft_putchar('+');
		list->col = list->col + 1;
	}
	else
	{
		if (str == NULL || str[0] == '\0' || (str && !ft_strchr(str, ' ')))
		{
			list->col = list->col + 1;
			ft_putchar(' ');
			return (1);
		}
	}
	return (0);
}

long double	ft_round(long double num)
{
	long double				fl1;
	unsigned long long int	n;

	n = (unsigned long long int)num;
	if (n % 2)
	{
		fl1 = ((num - (unsigned long long int)num) * 10);
		if ((int)fl1 >= 5)
			return (num + 1);
	}
	else
	{
		fl1 = num - (unsigned long long int)num;
		if (fl1 > 0.500000)
			return (num + 1);
	}
	return (num);
}
