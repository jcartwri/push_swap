/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:59:07 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/09 11:59:12 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_newcor(t_plist *list, char *str, char *s)
{
	int		i;
	char	*cor;

	cor = ft_strnew(list->correct - (int)ft_strlen(str) + 1);
	i = -1;
	while (++i < (list->correct - (int)ft_strlen(str) + 1))
		cor[i] = '0';
	if (list->flag == NULL || (list->flag && !ft_strchr(list->flag, '-')))
	{
		if (list->width > list->correct)
		{
			ft_putstr(s);
			list->col = list->col + (int)ft_strlen(s);
		}
		ft_putstr(cor);
		list->col = list->col + (int)ft_strlen(cor);
	}
	else
	{
		ft_putstr(cor);
		list->col = list->col + (int)ft_strlen(cor);
		if (list->width > list->correct)
			(PUT_S);
	}
	ft_strdel(&cor);
}

static int	ft_newcor1(t_plist *list, char *str)
{
	char	*cor;
	int		i;

	if (list->width > (int)ft_strlen(str) && list->corr0 == 0)
	{
		cor = ft_strnew(list->width - (int)ft_strlen(str) + 1);
		i = -1;
		while (++i < (list->width - (int)ft_strlen(str) + 1))
			cor[i] = ' ';
		ft_putstr(cor);
		list->col = list->col + (int)ft_strlen(cor);
		ft_strdel(&cor);
		return (-1);
	}
	return (1);
}

static int	ft_newcor2(t_plist *list)
{
	int	i;

	if (list->correct == 0 && list->corr0 == 0 && (!list->flag || (list->flag &&
	!ft_strchr(list->flag, '#')) || list->type == 'x' || list->type == 'X'))
		return (-1);
	if (list->flag && ft_strchr(list->flag, '#'))
	{
		i = 0;
		while (list->flag[i])
		{
			if (list->flag[i] == '#')
				list->flag[i] = 'i';
			i++;
		}
	}
	return (1);
}

static int	ft_str_raven_0(t_plist *list, char *str)
{
	int		i;
	char	*s;

	s = NULL;
	if (ft_newcor1(list, str) == -1)
		return (-1);
	if (list->correct > 0 && list->correct > (int)ft_strlen(str))
	{
		if (list->width > list->correct)
		{
			s = ft_strnew(list->width - list->correct);
			i = -1;
			while (++i < (list->width - list->correct))
				s[i] = ' ';
		}
		ft_newcor(list, str, s);
		ft_strdel(&s);
		return (-1);
	}
	else
	{
		if (ft_newcor2(list) == -1)
			return (-1);
	}
	return (1);
}

void		ft_output_x(t_plist *list, char *str)
{
	t_strlist	*slist;

	slist = NULL;
	slist = ft_create_strlist(slist);
	slist->a = 0;
	if (list->type == 'p' && list->correct == 0 && list->corr0 == 0
	&& str[0] == '0')
		str[0] = '\0';
	if (str[0] == '0' && str[1] == '\0' && list->type != 'p')
	{
		if (ft_str_raven_0(list, str) == -1)
		{
			freeslist(slist);
			return ;
		}
	}
	if (list->flag && ft_strchr(list->flag, '#'))
		slist->a = 2;
	if (list->flag && ft_strchr(list->flag, '#') && list->type == 'o')
		slist->a = 1;
	if ((list->width == 0 || (ft_strlen(str) >= (unsigned long)list->width)))
		ft_widthraven0(list, str);
	else
		ft_allocate_memory(list, str, slist);
	freeslist(slist);
}
