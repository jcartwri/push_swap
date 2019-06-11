/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:24:37 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/06 20:55:55 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ft(char *s, int m, int i, unsigned long long n)
{
	if (m == -1)
		s[0] = '-';
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

static int	ft_col_ele(int i, unsigned long long n)
{
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_ulltoa(unsigned long long int n)
{
	int					i;
	int					m;
	unsigned long long	n1;
	char				*s;

	i = 0;
	m = 1;
	if (n == 0)
		return (ft_nyl());
	n1 = n;
	i = ft_col_ele(i, n1);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_ft(s, m, i, n1);
	return (s);
}
