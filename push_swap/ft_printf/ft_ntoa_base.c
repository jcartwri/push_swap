/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:46:04 by jcartwri          #+#    #+#             */
/*   Updated: 2019/02/09 18:46:11 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ntoa_len(unsigned long long int num, int base)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / base;
		i++;
	}
	return (i);
}

char		*ft_ntoa_base(t_plist *list, unsigned long long int num, int base)
{
	char	*s;
	int		i;
	int		len;

	if (list->str)
	{
		list->col = list->col + (int)ft_strlen(list->str);
		ft_putstr(list->str);
	}
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_ntoa_len(num, base);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (num > 0)
	{
		if (list->type == 'X')
			s[len - ++i] = "0123456789ABCDEF"[num % base];
		else
			s[len - ++i] = "0123456789abcdef"[num % base];
		num = num / base;
	}
	s[len] = '\0';
	return (s);
}
