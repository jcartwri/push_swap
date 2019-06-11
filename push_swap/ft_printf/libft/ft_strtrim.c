/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:40:01 by jcartwri          #+#    #+#             */
/*   Updated: 2018/11/29 16:07:34 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_begin(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

static	int	ft_end(char *s, int l)
{
	int	i;

	i = 0;
	l--;
	while ((s[l] == '\n' || s[l] == ' ' || s[l] == '\t') && (l >= 0))
	{
		l--;
		i++;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		y;
	int		x;
	char	*str;

	if (!s)
		return (NULL);
	x = -1;
	i = ft_begin((char *)s);
	y = ft_end((char *)s, (int)ft_strlen((char *)s));
	if ((int)ft_strlen((char *)s) - i - y + 1 >= 0)
	{
		if (!(str = (char *)malloc(sizeof(char) *
					((int)ft_strlen((char *)s) - i - y + 1))))
			return (NULL);
		while (++x < ((int)ft_strlen((char *)s) - i - y))
			str[x] = s[x + i];
		str[x] = '\0';
	}
	else
	{
		if ((str = (char *)malloc(sizeof(char))) != NULL)
			str[0] = '\0';
	}
	return (str);
}
