/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:08:37 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/04 11:07:38 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_symbol(const char *s, char c)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ret++;
		i++;
	}
	return (ret);
}

static char		*ft_ft(const char *s, char c)
{
	size_t	len;
	char	*ret;
	size_t	i;

	len = 0;
	ret = NULL;
	i = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	if (len != 0)
	{
		ret = (char *)malloc(sizeof(char) * (len + 1));
		if (ret != NULL)
		{
			while (i < len)
			{
				ret[i] = s[i];
				i++;
			}
			ret[i] = '\0';
		}
	}
	return (ret);
}

static char		**pust(char **ret, char *s)
{
	if (s[0] == '\0')
	{
		ret[0] = NULL;
	}
	else
	{
		ret[0] = ft_strdup(s);
		ret[1] = NULL;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	size_t	size;
	size_t	i;
	char	**ret;

	if (!s)
		return (NULL);
	size = ft_number_symbol(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	if ((size == 0) || (s[0] == '\0'))
		return (pust(ret, (char *)s));
	i = 0;
	count = 0;
	while (s[count] != '\0')
	{
		ret[i] = ft_ft(s + count, c);
		if (ret[i] == NULL)
			count++;
		else
			count += (ft_strlen(ret[i++]));
	}
	ret[i] = NULL;
	return (ret);
}
