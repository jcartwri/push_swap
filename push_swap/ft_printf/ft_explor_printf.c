/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explor_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:41:42 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/05 18:41:49 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_expl(t_plist *list)
{
	int		a;
	char	*str;

	if (list->width > 1)
	{
		str = ft_strnew(list->width - 1);
		a = -1;
		while (++a < (list->width - 1))
			str[a] = ' ';
		if (list->flag && ft_strchr(list->flag, '0') &&
		(!ft_strchr(list->flag, '-')))
		{
			a = -1;
			while (++a < (list->width - 1))
				str[a] = '0';
		}
		if (list->flag && ft_strchr(list->flag, '-'))
			(PUT_STR_PROCENT);
		else
			(PUT_STR);
		list->col = list->col + 1 + (int)ft_strlen(str);
		ft_strdel(&str);
	}
	else
		(PUT_PROCENT);
}

int		ft_exploer_while(t_plist *list, const char *fmt, int *i, va_list ap)
{
	int	a;

	if (fmt[*i] == 'h' || (fmt[*i] == 'h' && fmt[*i + 1] == 'h') || fmt[*i] ==
	'l' || (fmt[*i] == 'l' && fmt[*i + 1] == 'l') || fmt[*i] == 'L')
	{
		a = *i;
		while (fmt[*i] == 'h' || fmt[*i] == 'l' || fmt[*i] == 'L')
			(*i)++;
		list->size = ft_strsub(fmt, a, *i - a);
	}
	if (*i >= (int)ft_strlen(fmt))
	{
		ft_output_liststr(list);
		return (-100);
	}
	ft_cheack_i_s_c(list, ap, fmt, *i);
	ft_cheack_u(list, ap, fmt, *i);
	ft_cheack_f_p(list, ap, fmt, *i);
	ft_cheack_x_o(list, ap, fmt, *i);
	if (fmt[*i] != 'x' && fmt[*i] != 'X' && fmt[*i] != 'o' && fmt[*i] != 'f'
	&& fmt[*i] != 'c' && fmt[*i] != 's' && fmt[*i] != 'i' && fmt[*i] != 'd'
	&& fmt[*i] != 'u' && fmt[*i] == '%')
		ft_expl(list);
	return (1);
}

int		ft_output_end(t_plist *root, t_plist *list)
{
	int	i;

	i = 0;
	list = root;
	while (list != NULL)
	{
		i = i + list->col;
		list = list->next;
	}
	return (i);
}
