/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:56:56 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/04 15:56:59 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_output_liststr(t_plist *list)
{
	if (list->str)
	{
		list->col = list->col + (int)ft_strlen(list->str);
		ft_putstr(list->str);
	}
}

static char	*ft_cheak_c_0(t_plist *list, int i)
{
	char	*str;

	str = NULL;
	if ((int)list->width > 1)
	{
		str = ft_strnew(list->width - 1);
		i = -1;
		while (++i < (list->width - 1))
		{
			if (list->flag && ft_strchr(list->flag, '0') &&
			!ft_strchr(list->flag, '-'))
				str[i] = '0';
			else
				str[i] = ' ';
		}
	}
	if (list->width > 1 && (!list->flag ||
	(list->flag && !ft_strchr(list->flag, '-'))))
	{
		ft_putstr(str);
		list->col = list->col + ft_strlen(str);
	}
	ft_putchar(0);
	list->col = list->col + 1;
	return (str);
}

static void	ft_cheak_width(t_plist *list, char c, int i)
{
	char	*str;

	str = ft_strnew(list->width);
	i = -1;
	while (++i < list->width)
	{
		if (list->flag && ft_strchr(list->flag, '0') &&
		!ft_strchr(list->flag, '-'))
			str[i] = '0';
		else
			str[i] = ' ';
	}
	if (!(list->flag) || ft_strchr(list->flag, '-') == NULL)
		str[i - 1] = c;
	else
		str[0] = c;
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(str);
	ft_strdel(&str);
}

static void	ft_putout_c_noflags(t_plist *list, char c)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = c;
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(str);
	ft_strdel(&str);
}

void		ft_output_char(t_plist *list, char c)
{
	int		i;
	char	*str;

	i = 0;
	ft_output_liststr(list);
	if (c == 0)
	{
		str = ft_cheak_c_0(list, i);
		if (list->width > 1 && (list->flag && ft_strchr(list->flag, '-')))
		{
			ft_putstr(str);
			list->col = list->col + ft_strlen(str);
		}
		ft_strdel(&str);
		return ;
	}
	if (list->width > 0)
	{
		ft_cheak_width(list, c, i);
		return ;
	}
	ft_putout_c_noflags(list, c);
}
