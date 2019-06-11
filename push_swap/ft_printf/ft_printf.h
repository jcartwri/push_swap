/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:14:47 by jcartwri          #+#    #+#             */
/*   Updated: 2019/02/04 16:14:50 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PUT_STR {ft_putstr(str); ft_putchar('%');}
# define PUT_STR_PROCENT {ft_putchar('%'); ft_putstr(str);}
# define PUT_PROCENT {ft_putchar('%'); list->col = list->col + 1;}
# define NEGATIVE {slist->a = -1; *num = *num * (-1);}
# define DEL {ft_strdel(&(slist->s)); slist->s = ft_strdup("0");}
# define SF {ft_putstr(str); list->col += (int)ft_strlen(str); ft_strdel(&str);}
# define OFF {freeslist(slist); return ;}
# define OFFF {ft_body_coorect0(list, slist); freeslist(slist); return ;}
# define FLAG {ft_flags(list, slist); slist->str = ft_strnew(slist->b); i = -1;}
# define SPACE {list->col++; ft_putchar(' ');}
# define VAR {i = 0; flo = 0.5; n = list->correct;}
# define SYMBOL {list->col = list->col + 1; ft_putchar(s[i++]);}
# define MINUS1 {a = 0; ft_putchar('-');}
# define MINUS2 {ft_putchar('-'); list->col++;}
# define VARIB {ft_putstr(s); i = 0;}
# define VARIB1 {ft_output_liststr(list); s = NULL; a = 0;}
# define STRS {ft_putstr(str); ft_putstr(s);}
# define SSTR {ft_putstr(s); ft_putstr(str);}
# define PUT_S {ft_putstr(s); list->col = list->col + (int)ft_strlen(s);}
# define PUT_SLIST_STR {ft_putstr(slist->s); ft_putstr(str);}
# define PUT_STR_SLIST {ft_putstr(str); ft_putstr(slist->s);}
# define LIST1 {root->width = 0; root->correct = 0; root->a = 0; root->col = 0;}
# define LIST2 {root->next = NULL; root->corr0 = -1; root->str = NULL;}
# define LIST3 {list->width = 0; list->a = 0; list->corr0 = -1; list->col = 0;}
# define PRIN {i = -1; root = ft_create_list(root); list = root;}
# define CAUSE {s = ft_less_antipl_corr_int(list, str); a = s;}

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_plist
{
	char			*str;
	char			*flag;
	char			*size;
	char			type;
	int				width;
	int				correct;
	int				corr0;
	int				a;
	int				col;
	struct s_plist	*next;
}					t_plist;

typedef struct		s_strlist
{
	char			*s;
	char			*cor;
	char			*str;
	int				a;
	int				b;
}					t_strlist;

int					ft_printf(const char *fmt, ...);
char				*ft_lltoa(long long n);
void				ft_output_int(t_plist *list, long long int num);
char				*ft_ntoa_base(t_plist *list, unsigned long long int num,
		int base);
void				ft_output_x(t_plist *list, char *str);
void				ft_output_float(t_plist *list, long double num);
void				ft_output_unsint(t_plist *list, unsigned long long int num);
char				*ft_ulltoa(unsigned long long int n);
int					ft_parsing(t_plist *list, const char *fmt, int i);
void				ft_output_char(t_plist *list, char c);
void				ft_output_liststr(t_plist *list);
void				ft_no_correct(t_plist *list, char *str);
void				ft_fts(t_plist *list, char *str, int i);
void				ft_output_str(t_plist *list, char *str);
void				ft_cheack_i_s_c(t_plist *list, va_list ap, const char *fmt,
		int i);
char				*ft_less_antipl_corr_int(t_plist *list, char *str);
void				ft_less_pl_antimin_int(t_plist *list, char *str, char *s,
		long long int num);
void				ft_less_pl_min_int(t_plist *list, char *str, char *s,
		long long int num);
void				ft_less_antipl_min_int(t_plist *list, char *str, char *s);
void				anti_pl_and_min_int(t_plist *list, char *str, char *s);
char				*ft_correct_int(t_plist *list, char *str);
char				*ft_zero_int(t_plist *list, long long int num, char *str);
int					ft_less_pl2(t_plist *list, char *str, char *s);
int					ft_less_pl1_assis(t_plist *list, char *str, char *s, int i);
void				ft_cheack_u(t_plist *list, va_list ap, const char *fmt,
		int i);
void				ft_cheack_f_p(t_plist *list, va_list ap, const char *fmt,
		int i);
void				ft_cheack_x_o(t_plist *list, va_list ap, const char *fmt,
		int i);
void				ft_expl(t_plist *list);
int					ft_output_end(t_plist *root, t_plist *list);
int					ft_exploer_while(t_plist *list, const char *fmt,
		int *i, va_list ap);
void				anti_pl_and_min_uns(t_plist *list, char *str, char *s);
void				ft_less_antipl_min_uns(t_plist *list, char *str, char *s);
char				*ft_less_pl_correct_uns(t_plist *list, char *str);
void				ft_less_pl_min_uns(t_plist *list, char *str, char *s);
void				ft_less_pl_antimin_uns(t_plist *list, char *str, char *s);
char				*ft_less_antipl_corr_uns(t_plist *list, char *str);
t_strlist			*ft_create_strlist(t_strlist *root);
void				ft_allocate_memory(t_plist *list, char *str,
		t_strlist *slist);
void				ft_widthraven0(t_plist *list, char *str);
void				ft_allocate_memory_else(t_plist *list, char *str,
		t_strlist *slist);
void				ft_output_ox(t_plist *list);
void				ft_else_body(t_plist *list, char *str, t_strlist *slist);
long double			ft_round_correct(t_plist *list, long double num);
void				ft_horror(t_plist *list, t_strlist *slist, long double num);
void				ft_big_width(t_plist *list, t_strlist *slist);
void				ft_body_coorect0(t_plist *list, t_strlist *slist);
long double			ft_round(long double num);
int					ft_out_plus_spac(t_plist *list, char *str);
void				ft_str_istina(t_plist *list, char *str);
void				ft_get_head(long double num, t_strlist *slist);
int					ft_sign_null(double num);
int					ft_define_nan_inf(t_plist *list, long double num);
void				ft_inf(t_plist *list, int n, char c);
void				ft_out_width(t_plist *list, int n, char c);
int					ft_put_minus(t_plist *list, int a);
char				*ft_tail(t_plist *list, long double num);
void				freeslist(t_strlist *slist);
void				ft_out_2_func(t_plist *list, t_strlist *slist);
void				ft_float_sokrashenie(t_plist *list, t_strlist *slist);
void				ft_inf_nan(t_plist *list, int n, char c, char *s);
void				ft_sokrashenie_int(t_plist *list, char *str, char *s);
void				cheak_0(t_plist *list, long long int num);
void				ft_cokr_correct_int(t_plist *list, char *str, char *s,
		int a);
void				ft_fill_s_unsigned(t_plist *list, char *str, char *s,
		int m);
void				ft_parspars1(t_plist *list, const char *fmt, int *i,
		int *a);
void				ft_pars_free(t_plist *list, const char *fmt, int *i,
		int *a);

#endif
