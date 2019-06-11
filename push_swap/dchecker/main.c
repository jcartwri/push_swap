/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:46:25 by jcartwri          #+#    #+#             */
/*   Updated: 2019/04/11 22:46:29 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_cheak_sort(int *mas, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (mas[i] > mas[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

static	int	ft_check_checker(t_ablist *list)
{
	if (list->lenb > 0)
		return (-1);
	if (ft_cheak_sort(list->a, list->lena) == -1)
		return (-1);
	if (list->lenb == 0)
		return (1);
	else
		return (0);
}

static void	ft_check(char *str, t_ablist *list)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_sa1(list, 0);
	else if (ft_strcmp(str, "sb") == 0)
		ft_sb1(list, 0);
	else if (ft_strcmp(str, "ss") == 0)
		ft_ss1(list);
	else if (ft_strcmp(str, "pa") == 0)
		ft_pa1(list);
	else if (ft_strcmp(str, "pb") == 0)
		ft_pb1(list);
	else if (ft_strcmp(str, "ra") == 0)
		ft_ra1(list, 0);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rb1(list, 0);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rr1(list);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rra1(list, 0);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rrb1(list, 0);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rrr1(list);
	else
		(EXIT);
}

static int	ft_return(t_ablist *list)
{
	char	*str;
	int		i;

	i = 0;
	while (get_next_line(0, &str) > 0)
	{
		ft_check(str, list);
		free(str);
		i++;
	}
	if (ft_check_checker(list) == 1)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}

int			main(int argc, char **argv)
{
	t_ablist	*list;
	int			l;

	if (ft_strcmp(argv[argc - 1], "-v") == 0)
		argc--;
	if ((l = ft_checker(argc, argv)) == -1)
	{
		ft_putendl("Error");
		return (0);
	}
	if (l == 0)
		return (0);
	list = ft_creat_ablist(l);
	if (argv[argc] && ft_strcmp(argv[argc], "-v") == 0)
		list->v = 1;
	if (ft_fill_array(list, argc, argv) == -1)
	{
		ft_ablist_int_del(list);
		ft_putendl("Error");
		return (0);
	}
	return (ft_return(list));
}
