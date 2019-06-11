/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:30:46 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/01 13:15:01 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*next;
	t_list	*cur;

	next = (*alst)->next;
	ft_lstdelone(alst, del);
	while (next != NULL)
	{
		cur = next;
		next = next->next;
		ft_lstdelone(&cur, del);
	}
}
