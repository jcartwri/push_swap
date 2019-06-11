/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:59:28 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/09 11:59:33 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_allocate_memory_else(t_plist *list, char *str, t_strlist *slist)
{
	ft_output_ox(list);
	ft_putstr(slist->s);
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(slist->s) + (int)ft_strlen(str);
}

void		ft_output_ox(t_plist *list)
{
	if (list->flag)
	{
		if (ft_strchr(list->flag, '#'))
		{
			if (list->type == 'o')
			{
				list->col = list->col + 1;
				ft_putstr("0");
			}
			if (list->type == 'x' || list->type == 'p')
			{
				list->col = list->col + 2;
				ft_putstr("0x");
			}
			if (list->type == 'X')
			{
				list->col = list->col + 2;
				ft_putstr("0X");
			}
		}
	}
}

static void	ft_else_else_body(t_plist *list, char *str, t_strlist *slist)
{
	if (list->width > ((int)ft_strlen(str) + slist->a))
	{
		list->col = list->col + (int)ft_strlen(slist->s);
		ft_putstr(slist->s);
	}
	ft_output_ox(list);
	ft_putstr(slist->cor);
	ft_putstr(str);
	list->col = list->col + (int)ft_strlen(slist->cor) + (int)ft_strlen(str);
}

static void	ft_body_else_body(t_plist *list, t_strlist *slist)
{
	int	i;

	i = 0;
	if (list->flag && ft_strchr(list->flag, '0'))
	{
		i = 0;
		if (list->a == 1)
		{
			while (slist->s[i])
				slist->s[i++] = ' ';
		}
		else
		{
			while (slist->s[i])
				slist->s[i++] = '0';
			ft_output_ox(list);
		}
		i = -1000;
	}
	list->col = list->col + (int)ft_strlen(slist->s);
	ft_putstr(slist->s);
	if (list->a == 1 || i != -1000)
		ft_output_ox(list);
}

void		ft_else_body(t_plist *list, char *str, t_strlist *slist)
{
	if (!((unsigned long)list->correct > ft_strlen(str)))
	{
		if (list->width > ((int)ft_strlen(str) + slist->a))
			ft_body_else_body(list, slist);
		else
			ft_output_ox(list);
		ft_putstr(str);
		list->col = list->col + (int)ft_strlen(str);
	}
	else
		ft_else_else_body(list, str, slist);
}
