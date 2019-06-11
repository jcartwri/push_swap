/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:07:23 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/03 18:45:38 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	while (num > 0)
	{
		ret[--count] = '0' + (num % 10);
		num = num / 10;
	}
	while (count < 20)
		ft_putchar_fd(ret[count++], fd);
}
