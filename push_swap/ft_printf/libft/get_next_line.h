/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:32:20 by jcartwri          #+#    #+#             */
/*   Updated: 2018/12/27 12:53:50 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# define ONE_MAC {(list->size) = 0;	(list->i) = (list->size);	break ;}
# define TWO_MAC {list->size = ret; list->i = list->size; s = ft_strnew(0);}
# define READ {ft_strdel(str); *str = a; list->i = x + 1;}
# define LIST_1 {alist->fd = fd; alist->size = 0; alist->i = 0;}
# define LIST_2 {alist->buf = NULL; alist->next = NULL;}
# define LIST_3 {LIST_1 LIST_2}

# include "libft.h"

typedef struct		s_lists
{
	int				i;
	int				size;
	int				fd;
	char			*buf;
	struct s_lists	*next;
}					t_lists;

int					get_next_line(const int fd, char **line);

#endif
