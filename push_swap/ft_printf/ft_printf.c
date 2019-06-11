/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:11:32 by jcartwri          #+#    #+#             */
/*   Updated: 2019/02/04 16:11:34 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_plist	*ft_create_list(t_plist *root)
{
	t_plist *list;

	if (root == NULL)
	{
		if (!(root = (t_plist *)malloc(sizeof(t_plist))))
			return (NULL);
		(LIST1);
		(LIST2);
		root->flag = NULL;
		root->size = NULL;
		return (root);
	}
	while (root->next != NULL)
		root = root->next;
	if (!(list = (t_plist *)malloc(sizeof(t_plist))))
		return (NULL);
	list->next = NULL;
	list->correct = 0;
	list->flag = NULL;
	list->str = NULL;
	list->size = NULL;
	(LIST3);
	root->next = list;
	return (list);
}

t_strlist		*ft_create_strlist(t_strlist *list)
{
	if (!(list = (t_strlist *)malloc(sizeof(t_strlist))))
		return (NULL);
	list->cor = NULL;
	list->s = NULL;
	list->str = NULL;
	return (list);
}

void			freeslist(t_strlist *slist)
{
	ft_strdel(&(slist->cor));
	ft_strdel(&(slist->s));
	ft_strdel(&(slist->str));
	free(slist);
}

static void		freelist(t_plist **root)
{
	t_plist	*next;
	t_plist	*list;

	next = (*root)->next;
	ft_strdel(&(*root)->str);
	ft_strdel(&(*root)->flag);
	ft_strdel(&(*root)->size);
	free(*root);
	*root = NULL;
	while (next != NULL)
	{
		list = next;
		next = list->next;
		ft_strdel(&list->str);
		ft_strdel(&list->size);
		ft_strdel(&list->flag);
		free(list);
	}
}

int				ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	t_plist	*list;
	t_plist	*root;

	root = NULL;
	va_start(ap, fmt);
	(PRIN);
	while (fmt[++i] != '\0')
	{
		if ((i = ft_parsing(list, fmt, i)) == -1)
			break ;
		if (i >= (int)ft_strlen(fmt))
		{
			ft_output_liststr(list);
			return (list->col);
		}
		if (ft_exploer_while(list, fmt, &i, ap) == -100)
			return (list->col);
		if (fmt[i + 1] != '\0')
			list = ft_create_list(root);
	}
	i = ft_output_end(root, list);
	freelist(&root);
	return (i);
}
