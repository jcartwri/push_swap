/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:01:32 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/01 15:12:25 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dest;

	i = 0;
	l_dest = 0;
	while (dest[i] && (i < size))
		i++;
	l_dest = i;
	if (l_dest == size)
		return (l_dest + ft_strlen((char *)src));
	while ((i < size - 1) && (src[i - l_dest]))
	{
		dest[i] = src[i - l_dest];
		i++;
	}
	dest[i] = '\0';
	return (l_dest + ft_strlen((char *)src));
}
