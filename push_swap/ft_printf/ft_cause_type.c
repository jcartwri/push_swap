/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cause_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:42:17 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/06 21:05:24 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_cheack_i_s_c(t_plist *list, va_list ap, const char *fmt, int i)
{
	if (fmt[i] == 'c' || fmt[i] == 's' || fmt[i] == 'i' || fmt[i] == 'd')
	{
		if (fmt[i] == 'c')
			ft_output_char(list, (char)va_arg(ap, int));
		if (fmt[i] == 's')
			ft_output_str(list, va_arg(ap, char *));
		if (fmt[i] == 'd' || fmt[i] == 'i')
		{
			list->type = 'i';
			if (list->size == NULL)
				ft_output_int(list, va_arg(ap, int));
			else
			{
				if (list->size && (!ft_strcmp(list->size, "hh")))
					ft_output_int(list, (signed char)va_arg(ap, int));
				if (list->size && (!ft_strcmp(list->size, "h")))
					ft_output_int(list, (short int)va_arg(ap, int));
				if (list->size && (!ft_strcmp(list->size, "l")))
					ft_output_int(list, va_arg(ap, long int));
				if (list->size && (!ft_strcmp(list->size, "ll")))
					ft_output_int(list, va_arg(ap, long long int));
			}
		}
	}
}

void		ft_cheack_u(t_plist *list, va_list ap, const char *fmt, int i)
{
	if (fmt[i] == 'u')
	{
		list->type = 'u';
		if (list->size == NULL)
			ft_output_unsint(list, va_arg(ap, unsigned int));
		else
		{
			if (list->size && (!ft_strcmp(list->size, "hh")))
				ft_output_unsint(list, (unsigned char)va_arg(ap, int));
			if (list->size && (!ft_strcmp(list->size, "h")))
				ft_output_unsint(list, (unsigned int)va_arg(ap, int));
			if (list->size && (!ft_strcmp(list->size, "l")))
				ft_output_unsint(list, va_arg(ap, unsigned long int));
			if (list->size && (!ft_strcmp(list->size, "ll")))
				ft_output_unsint(list, va_arg(ap, unsigned long long int));
		}
	}
}

static void	ft_cheack_type(t_plist *list, const char *fmt, int i)
{
	if (fmt[i] == 'x')
		list->type = 'x';
	if (fmt[i] == 'X')
		list->type = 'X';
	if (fmt[i] == 'o')
		list->type = 'o';
}

void		ft_cheack_x_o(t_plist *list, va_list ap, const char *fmt, int i)
{
	int		a;
	char	*str;

	if (fmt[i] == 'x' || fmt[i] == 'X' || fmt[i] == 'o')
	{
		a = 16;
		str = NULL;
		ft_cheack_type(list, fmt, i);
		if (fmt[i] == 'o')
			a = 8;
		if (list->size == '\0')
			str = ft_ntoa_base(list, (unsigned int)va_arg(ap, char *), a);
		if (list->size && (!ft_strcmp(list->size, "hh")))
			str = ft_ntoa_base(list, (unsigned char)va_arg(ap, char *), a);
		if (list->size && (!ft_strcmp(list->size, "h")))
			str = ft_ntoa_base(list, (unsigned short int)va_arg(ap, char *), a);
		if (list->size && (!ft_strcmp(list->size, "ll")))
			str = ft_ntoa_base(list,
					(unsigned long long int)va_arg(ap, char *), a);
		if (list->size && (!ft_strcmp(list->size, "l")))
			str = ft_ntoa_base(list, (unsigned long int)va_arg(ap, char *), a);
		ft_output_x(list, str);
		ft_strdel(&str);
	}
}

void		ft_cheack_f_p(t_plist *list, va_list ap, const char *fmt, int i)
{
	char	*str;

	if (fmt[i] == 'p')
	{
		list->type = 'p';
		if (list->flag)
		{
			str = list->flag;
			list->flag = ft_strjoin(list->flag, "#");
			ft_strdel(&str);
		}
		else
			list->flag = ft_strdup("#");
		str = ft_ntoa_base(list,
				(unsigned long long int)va_arg(ap, char *), 16);
		ft_output_x(list, str);
		ft_strdel(&str);
	}
	if (fmt[i] == 'f')
	{
		if (list->size == '\0' || !ft_strcmp(list->size, "l"))
			ft_output_float(list, va_arg(ap, double));
		if (list->size && (!ft_strcmp(list->size, "L")))
			ft_output_float(list, va_arg(ap, long double));
	}
}
