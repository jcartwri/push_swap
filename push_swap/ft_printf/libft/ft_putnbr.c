/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:49:30 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/03 18:31:16 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	num;
	int		count;
	char	ret[20];

	count = 0;
	num = n;
	while (count < 20)
		ret[count++] = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (num > 0)
	{
		ret[--count] = '0' + (num % 10);
		num = num / 10;
	}
	while (count < 20)
		ft_putchar(ret[count++]);
}
