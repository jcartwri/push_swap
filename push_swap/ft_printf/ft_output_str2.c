/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:14:28 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/04 18:14:31 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fts_assistent(t_plist *list, char *str, char *s, int i)
{
	if (list->flag && ft_strchr(list->flag, '-'))
	{
		i = -1;
		while (++i < list->correct)
		{
			ft_putchar(str[i]);
			list->col = list->col + 1;
		}
		if (list->width > list->correct)
			(PUT_S);
	}
	else
	{
		if (list->width > list->correct)
			(PUT_S);
		i = -1;
		while (++i < list->correct)
		{
			ft_putchar(str[i]);
			list->col = list->col + 1;
		}
	}
}

void		ft_fts(t_plist *list, char *str, int i)
{
	char	*s;

	s = NULL;
	if (list->width > list->correct)
	{
		s = ft_strnew(list->width - list->correct);
		i = -1;
		while (++i < (list->width - list->correct))
		{
			if (list->flag && ft_strchr(list->flag, '0') &&
			!ft_strchr(list->flag, '-'))
				s[i] = '0';
			else
				s[i] = ' ';
		}
	}
	ft_fts_assistent(list, str, s, i);
	ft_strdel(&s);
}

static void	ft_ft_no_correct(t_plist *list, char *str, char *s)
{
	if (list->flag && ft_strchr(list->flag, '-'))
	{
		ft_putstr(str);
		list->col = list->col + (int)ft_strlen(str);
		if (list->width > (int)ft_strlen(str))
		{
			ft_putstr(s);
			list->col = list->col + (int)ft_strlen(s);
		}
	}
	else
	{
		if (list->width > (int)ft_strlen(str))
		{
			ft_putstr(s);
			list->col = list->col + (int)ft_strlen(s);
		}
		ft_putstr(str);
		list->col = list->col + (int)ft_strlen(str);
	}
}

void		ft_no_correct(t_plist *list, char *str)
{
	char	*s;
	int		i;

	s = NULL;
	if (list->width > (int)ft_strlen(str))
	{
		s = ft_strnew(list->width - (int)ft_strlen(str));
		i = -1;
		while (++i < (list->width - (int)ft_strlen(str)))
		{
			if (list->flag && ft_strchr(list->flag, '0') &&
			!ft_strchr(list->flag, '-'))
				s[i] = '0';
			else
				s[i] = ' ';
		}
	}
	ft_ft_no_correct(list, str, s);
}
