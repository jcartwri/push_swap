/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:14:17 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/01 15:06:13 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*sr;
	char	*ds;

	i = -1;
	sr = (char *)src;
	ds = (char *)dst;
	if (sr < ds)
	{
		while ((int)(--len) >= 0)
		{
			ds[len] = sr[len];
		}
	}
	else
	{
		while ((++i) < len)
		{
			ds[i] = sr[i];
		}
	}
	return (dst);
}
