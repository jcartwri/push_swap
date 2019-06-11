/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:21:09 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/16 16:21:15 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atolli(const char *str)
{
	long long int	i;
	long long int	a;
	long long int	m;

	i = 0;
	m = 1;
	a = 0;
	while (str[i] == '\r' || str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			m = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10;
		a = a + str[i] - 48;
		i++;
	}
	return (a * m);
}
