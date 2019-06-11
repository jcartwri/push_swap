/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:05:52 by jcartwri          #+#    #+#             */
/*   Updated: 2018/11/29 19:22:26 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ft(char *s, int m, int i, long n)
{
	if (m == -1)
	{
		s[0] = '-';
	}
	s[i] = '\0';
	while (n > 0)
	{
		s[--i] = n % 10 + 48;
		n = n / 10;
	}
}

static char	*ft_nyl(void)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	s[0] = 48;
	s[1] = '\0';
	return (s);
}

static int	ft_col_ele(int i, long n)
{
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		m;
	long	n1;
	char	*s;

	i = 0;
	m = 1;
	n1 = n;
	if (n1 == 0)
		return (ft_nyl());
	if (n1 < 0)
	{
		i++;
		m = -1;
		n1 = n1 * (-1);
	}
	i = ft_col_ele(i, n1);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_ft(s, m, i, n1);
	return (s);
}
