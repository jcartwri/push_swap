/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:52:11 by jcartwri          #+#    #+#             */
/*   Updated: 2019/02/08 20:52:17 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ft(char *s, int m, int i, long long n)
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

static int	ft_col_ele(int i, long long n)
{
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_lltoa(long long int n)
{
	int			i;
	int			m;
	long long	n1;
	char		*s;

	i = 0;
	m = 1;
	n1 = -9223372036854775807;
	if (n == 0)
		return (ft_nyl());
	if (n == (n1 - 1))
		return (ft_strdup("-9223372036854775808"));
	n1 = n;
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
