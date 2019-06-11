/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:03:58 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/01 15:14:28 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *hay, const char *need)
{
	int i;
	int j;
	int h;
	int n;

	i = 0;
	j = 0;
	h = 0;
	n = 0;
	if (need[i] == '\0')
		return ((char *)hay);
	while (hay[h])
		h++;
	while (need[n])
		n++;
	while (h - i - n >= 0)
	{
		j = 0;
		while (hay[i + j] == need[j])
			if (need[++j] == '\0')
				return ((char *)hay + i);
		i++;
	}
	return (0);
}
