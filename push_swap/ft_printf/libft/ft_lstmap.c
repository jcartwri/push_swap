/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:54:21 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/03 19:00:12 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*ret;
	t_list	*prev;
	t_list	*begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = f(lst);
	lst = lst->next;
	begin = ret;
	while (lst)
	{
		prev = ret;
		ret = f(lst);
		if (ret == NULL)
			return (NULL);
		prev->next = ret;
		lst = lst->next;
	}
	return (begin);
}
