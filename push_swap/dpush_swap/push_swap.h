/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:39:29 by jcartwri          #+#    #+#             */
/*   Updated: 2019/03/16 10:59:46 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR {ft_putendl("Error"); return (0);}
# define NOELEMENT {ft_putendl("Nety elementov"); return (0);}
# define SORT {sorted(list, pindx, 'a'); sorted(list, size - pindx, 'b');}
# define MAX(a, m, lmin, lmax) a < m ? lmin++ : lmax++
# define INITIAL {j = -1; lmn = 0; lmax = 0; m = mas[i];}
# define INITI {i = -1; m = mas[0];}

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef	struct	s_alist
{
	int				lena;
	int				lenb;
	int				*a;
	int				*b;
	int				v;
	struct s_alist	*next;
}				t_ablist;

int				main(int argc, char **argv);
long long int	ft_atolli(const char *str);
int				ft_atoips(const char *str, int j);
int				ft_checker(int argc, char **argv);
int				ft_fill_array(t_ablist	*list, int argc, char **argv);
int				ft_atoips(const char *str, int j);
t_ablist		*ft_creat_ablist(int len);
void			ft_ablist_int_del(t_ablist *list);
int				ft_cheak_sorted_a(int *mas, int size);
void			ft_out_put_steak(t_ablist *list);
int				equal_test(t_ablist	*list);
int				ft_get_count(char **argv, int i, int j);
void			ft_sorted_elem_b(t_ablist *list, int size);
int				ft_commands(t_ablist *list, int size);
void			sorted(t_ablist *list, int size, char steck);
int				find_max_in_size(int *mas, int size);
void			ft_sba(t_ablist *list);
void			ft_sab(t_ablist *list);
int				ft_cheak_sorted_b(int *mas, int size);
int				ft_cheak_stop_a(t_ablist *list, int size);
int				ft_revers_a(t_ablist *list);
int				ft_find_meridian(int l, int *mas);
void			ft_turn_up_begin_a(t_ablist *list, int l, int size, int begin);
void			ft_turn_up_begin_b(t_ablist *list, int l, int size, int begin);
int				ft_get_begin_a(int *mas, int size, int m);
int				ft_get_begin_b(int *mas, int size, int m);
int				ft_break_array_half_b(t_ablist *list, int m,
		int begin, int size);
int				ft_break_array_half_a(t_ablist *list, int m,
		int begin, int size);
int				ft_body_sort_a(t_ablist *list, int size);
int				ft_check_on_correct(char **argv, int i, int m);
void			ft_sa(t_ablist	*list, int i);
void			ft_sb(t_ablist	*list, int i);
void			ft_ss(t_ablist	*list);
void			ft_pa(t_ablist *list);
void			ft_pb(t_ablist *list);
void			ft_ra(t_ablist *list, int k);
void			ft_rb(t_ablist *list, int k);
void			ft_rr(t_ablist *list);
void			ft_rra(t_ablist *list, int k);
void			ft_rrb(t_ablist *list, int k);
void			ft_rrr(t_ablist *list);

#endif
