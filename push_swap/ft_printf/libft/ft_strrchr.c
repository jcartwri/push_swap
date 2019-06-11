/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:33:31 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/01 15:13:22 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int a;

	i = 0;
	a = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			a = i;
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	if (a == -1)
		return (NULL);
	else
		return ((char *)s + a);
}
