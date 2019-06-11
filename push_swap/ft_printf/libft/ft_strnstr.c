/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:40:25 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/01 15:15:43 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	int	i;
	int	j;
	int	h;
	int	n;

	i = 0;
	j = 0;
	h = 0;
	n = 0;
	if (need[i] == '\0')
		return ((char *)hay);
	h = ft_strlen((char *)hay);
	n = ft_strlen((char *)need);
	while ((h - i - n >= 0) && (i < (int)len))
	{
		j = 0;
		while ((hay[i + j] == need[j]) && (i + j < (int)len))
		{
			if (need[++j] == '\0')
				return ((char *)hay + i);
		}
		i++;
	}
	return (NULL);
}
