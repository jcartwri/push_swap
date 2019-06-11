/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:14:06 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/04 18:14:08 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cheak_str_on_nullwid(t_plist *list, char *str, int i)
{
	if (str == NULL && list->correct == 0 && list->a == 1)
	{
		if (list->width > 0)
		{
			i = 0;
			if (list->flag == NULL || (list->flag &&
			!ft_strchr(list->flag, '0')))
			{
				str = ft_strnew(list->width);
				while (i < list->width)
					str[i++] = ' ';
			}
			else
			{
				str = ft_strnew(list->width);
				while (i < list->width)
					str[i++] = '0';
			}
			ft_putstr(str);
			list->col += (int)ft_strlen(str);
		}
		ft_strdel(&str);
		return (-1);
	}
	return (1);
}

static int	ft_cheak_str_on_null(t_plist *list, char **str)
{
	int		i;
	char	*s;

	if (*str == NULL)
	{
		*str = ft_strdup("(null)");
		return (2);
	}
	if (*str[0] == '\0')
	{
		if (list->width > 0)
		{
			s = ft_strnew(list->width);
			i = -1;
			while (++i < list->width)
				s[i] = ' ';
			ft_putstr(s);
			list->col = list->col + (int)ft_strlen(s);
			ft_strdel(&s);
		}
		return (-1);
	}
	return (1);
}

static void	ft_correct_more_wid(t_plist *list, char *str, int i)
{
	char	*s;

	if (list->width > (int)ft_strlen(str))
	{
		s = (char *)malloc(sizeof(char) * (list->width - ft_strlen(str) + 1));
		i = -1;
		while (++i < (list->width - (int)ft_strlen(str)))
			s[i] = ' ';
		s[i] = '\0';
		ft_putstr(s);
		list->col = list->col + (int)ft_strlen(s);
		ft_strdel(&s);
	}
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(str);
}

static void	ft_correct_lesseq_wid(t_plist *list, char *str, int i, int a)
{
	char	*s;

	if (list->correct <= list->width)
	{
		s = ft_strnew(list->width - (int)ft_strlen(str));
		a = list->width - (int)ft_strlen(str);
		i = -1;
		while (++i < a)
		{
			if (list->flag && !ft_strchr(list->flag, '-') &&
			ft_strchr(list->flag, '0'))
				s[i] = '0';
			else
				s[i] = ' ';
		}
		if (list->flag && ft_strchr(list->flag, '-'))
			(STRS);
		else
			(SSTR);
		list->col = list->col + (int)ft_strlen(str) + (int)ft_strlen(s);
		ft_strdel(&s);
	}
	else
		ft_correct_more_wid(list, str, i);
}

void		ft_output_str(t_plist *list, char *str)
{
	int	i;
	int	a;
	int	m;

	i = 0;
	a = 0;
	ft_output_liststr(list);
	if (ft_cheak_str_on_nullwid(list, str, i) == -1)
		return ;
	if ((m = ft_cheak_str_on_null(list, &str)) == -1)
		return ;
	if (list->a == 1)
	{
		if (list->correct > (int)ft_strlen(str))
			ft_correct_lesseq_wid(list, str, i, a);
		else
			ft_fts(list, str, i);
	}
	else
		ft_no_correct(list, str);
	if (m == 2)
		ft_strdel(&str);
}
