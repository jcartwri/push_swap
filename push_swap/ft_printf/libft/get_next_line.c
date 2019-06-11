/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:10:08 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/27 13:38:01 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_lists	*ft_cheak_fd(t_lists **root, int fd)
{
	t_lists	*list;
	t_lists	*alist;

	if (!(*root))
	{
		if (!(alist = (t_lists *)malloc(sizeof(t_lists))))
			return (NULL);
		(LIST_3);
		*root = alist;
		return (*root);
	}
	list = *root;
	if (list->fd == fd)
		return (list);
	while (list->next != NULL)
	{
		list = list->next;
		if (list->fd == fd)
			return (list);
	}
	if (!(alist = (t_lists *)malloc(sizeof(t_lists))))
		return (NULL);
	(LIST_3);
	list->next = alist;
	return (list->next);
}

static	int		input(char **line, char **str, int ret)
{
	*line = ft_strjoin("", *str);
	ft_strdel(str);
	if (ret == 0)
	{
		if (ft_strlen(*line))
			return (1);
		return (0);
	}
	return (1);
}

static	int		set_line(char *buf, t_lists *list, char **line, char **str)
{
	while (list->i != list->size)
	{
		if (ft_strchr((char *)(buf + (list->i)), '\n') == NULL)
		{
			ft_strdel(str);
			if (!(*str = ft_strsub(buf, (list->i), (list->size) - (list->i))))
				return (-1);
			(ONE_MAC);
		}
		else
		{
			ft_strdel(str);
			if (!(*str = ft_strsub(buf, (list->i), (list->size) - (list->i) -
							ft_strlen(ft_strchr((char *)(buf +
										(list->i)), '\n')))))
				return (-1);
			*line = ft_strjoin("", *str);
			ft_strdel(str);
			(list->i) = (list->size) - ft_strlen(ft_strchr((char *)(buf
							+ (list->i)), '\n')) + 1;
			return (1);
		}
	}
	return (2);
}

static	int		ft_read(char *buf, t_lists *list, char **str, int ret)
{
	char	*s;
	long	x;
	char	*a;

	if (ret == -1)
		return (-1);
	(TWO_MAC);
	if (ft_strchr(buf, '\n') != NULL)
		x = list->size - ft_strlen(ft_strchr(buf, '\n'));
	if (ft_strchr(buf, '\n') == NULL)
	{
		a = ft_strjoin(*str, buf);
		ft_strdel(str);
		*str = a;
	}
	else
	{
		ft_strdel(&s);
		if (!(s = ft_strsub(buf, 0, x)))
			return (-1);
		a = ft_strjoin(*str, s);
		(READ);
	}
	ft_strdel(&s);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static	t_lists	*root;
	t_lists			*list;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				ret;

	str = ft_strnew(0);
	list = ft_cheak_fd(&root, fd);
	if (fd < 0 || fd == 1 || fd == 2 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	ret = set_line(list->buf, list, line, &str);
	if (ret == 1 || ret == -1)
		return (ret);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_strdel(&(list->buf));
		if (!(list->buf = ft_strdup(buf)))
			return (-1);
		if (ft_read((list->buf), list, &str, ret) == -1)
			return (-1);
		if (ft_strchr((list->buf), '\n') != NULL)
			break ;
	}
	return (input(line, &str, ret));
}
