/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:59:17 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/09 11:59:22 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_widthraven0(t_plist *list, char *str)
{
	char	*s;
	int		i;

	if (list->type != 'o' || ((unsigned long)list->correct <=
	(ft_strlen(str)) && list->type == 'o'))
		ft_output_ox(list);
	if ((unsigned long)list->correct > (ft_strlen(str)))
	{
		s = ft_strnew(list->correct - (ft_strlen(str)));
		i = 0;
		while ((unsigned long)i < ((unsigned long)list->correct
		- (ft_strlen(str))))
			s[i++] = '0';
		ft_putstr(s);
		list->col = list->col + (int)ft_strlen(s);
		ft_strdel(&s);
	}
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(str);
}

static char	*ft_allocate_memory1(t_plist *list, char *str, t_strlist *slist)
{
	int		i;
	char	*s;

	if (!((unsigned long)list->correct > ft_strlen(str)))
	{
		s = ft_strnew(list->width - (ft_strlen(str) + slist->a));
		i = -1;
		while (++i < (list->width - ((int)ft_strlen(str) + slist->a)))
		{
			if (list->flag && ft_strchr(list->flag, '0')
			&& !ft_strchr(list->flag, '-'))
				s[i] = '0';
			else
				s[i] = ' ';
		}
	}
	else
	{
		s = ft_strnew(list->width - (list->correct + slist->a));
		i = -1;
		while (++i < list->width - (list->correct + slist->a))
			s[i] = ' ';
	}
	return (s);
}

static void	ft_cornew(t_plist *list, char *str, t_strlist *slist)
{
	int	i;

	if ((unsigned long)list->correct > ft_strlen(str))
	{
		slist->cor = ft_strnew(list->correct - (ft_strlen(str)));
		i = -1;
		while (++i < (list->correct - ((int)ft_strlen(str))))
			slist->cor[i] = '0';
		slist->cor[i] = '\0';
	}
}

static void	ft_body(t_plist *list, char *str, t_strlist *slist)
{
	if (list->flag && ft_strchr(list->flag, '-'))
	{
		ft_output_ox(list);
		if (!((unsigned long)list->correct > ft_strlen(str)))
		{
			if (list->width > ((int)ft_strlen(str) + slist->a)
			&& list->correct == 0)
				(PUT_STR_SLIST);
			else
				(PUT_SLIST_STR);
			list->col = list->col + (int)ft_strlen(slist->s) +
					(int)ft_strlen(str);
		}
		else
		{
			ft_putstr(slist->cor);
			ft_putstr(str);
			ft_putstr(slist->s);
			list->col = list->col + (int)ft_strlen(slist->s) +
					(int)ft_strlen(str) + (int)ft_strlen(slist->cor);
		}
	}
	else
		ft_else_body(list, str, slist);
}

void		ft_allocate_memory(t_plist *list, char *str, t_strlist *slist)
{
	int	i;

	if (list->width > list->correct)
		slist->s = ft_allocate_memory1(list, str, slist);
	else
	{
		if (list->flag && ft_strchr(list->flag, '#') && list->type != 'o')
			slist->a = 0;
		slist->s = ft_strnew(list->correct - (ft_strlen(str) + slist->a));
		i = -1;
		while (++i < (list->correct - ((int)ft_strlen(str) + slist->a)))
			slist->s[i] = '0';
		if (list->flag && ft_strchr(list->flag, '#') && list->type != 'o')
			slist->a = 2;
	}
	if (list->width > list->correct)
	{
		ft_cornew(list, str, slist);
		ft_body(list, str, slist);
	}
	else
		ft_allocate_memory_else(list, str, slist);
}
