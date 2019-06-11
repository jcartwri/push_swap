/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:58 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/12 16:44:00 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_ablist_int_del(t_ablist *list)
{
	free(list->a);
	free(list->b);
	free(list);
}

t_ablist	*ft_creat_ablist(int len)
{
	t_ablist	*list;

	list = (t_ablist *)malloc(sizeof(t_ablist));
	list->lena = len;
	list->v = 0;
	list->lenb = 0;
	list->a = (int *)malloc(sizeof(int) * (len + 1));
	list->b = (int *)malloc(sizeof(int) * (len + 1));
	list->next = NULL;
	return (list);
}

int			ft_atoips(const char *str, int j)
{
	int	i;
	int	a;
	int	m;

	i = j;
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

int			ft_fill_array(t_ablist *list, int argc, char **argv)
{
	int i;
	int j;
	int	m;
	int k;

	i = 0;
	k = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && argv[i][j] == ' ')
				j++;
			m = ft_atoips(argv[i], j);
			list->a[k++] = m;
			j = ft_get_count(argv, i, j);
		}
	}
	if (equal_test(list) == -1)
		return (-1);
	return (1);
}

int			ft_checker(int argc, char **argv)
{
	int				i;
	int				j;
	int				l;
	long long int	m;

	l = 0;
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' && argv[i][j] != '\0')
				j++;
			m = j;
			if (ft_check_on_correct(argv, i, m) == -1)
				return (-1);
			m = ft_atolli(argv[i] + j);
			if (m < -2147483648 || m > 2147483647)
				return (-1);
			j = ft_get_count(argv, i, j);
			l++;
		}
	}
	return (l);
}
