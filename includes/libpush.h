/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 09:17:39 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:02:01 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_H
# define LIBPUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libprintf.h"

typedef struct		s_l
{
	int				content;
	int				position;
	struct s_l		*next;
	struct s_l		*first;
}					t_l;

typedef struct		s_opt
{
	int				v;
	int				color;
	int				silence;
	int				n;
	int				r;
}					t_opt;

t_l					*ft_read(char **argv);
t_l					*ft_do_lst(int content, int position, t_l *lst);
t_l					*ft_initi(int content, t_l *lst);
int					ft_test(char *str);
int					ft_notnb(char *str);
int					ft_strlen2(char *str);
int					ft_atoi(char *str);
t_l					*ft_deal(t_l *lst);
t_l					*ft_lstcpy(t_l *lst);
t_l					*ft_insert(t_l *lst, t_l *lst2);
t_l					*ft_insert1(t_l *lst, t_l *lst2, int tmp, int tmp2);
t_l					*ft_insert2(t_l*lst, t_l *lst2, int tmp, int tmp2);
t_l					*ft_trif(t_l *lst, int nb);
t_l					*ft_lstncpy(t_l *lst, int p);
t_l					*ft_lstndcpy(t_l *lst, int q, int nb);
void				ft_lstdel(t_l *lst);
void				ft_resolve(t_l *lst, t_l *lst2, t_opt *opt);
t_l					*ft_swap(t_l *lst3, int nb);
t_l					*ft_swpfirst(t_l *lst, int nb);
t_l					*ft_swp(t_l *lst, int bol, int nb);
int					ft_position(t_l *lst, int nb, int bol);
int					ft_dif(t_l *lst);
t_l					*ft_bubble(t_l *lst, int nb, t_opt *opt);
int					ft_abs(int i);
int					ft_bdiff(t_l *lst);
t_l					*ft_movepile(t_l *lst, int nb, t_opt *opt);
t_l					*ft_swpfst(t_l *lst, int nb);
t_l					*ft_sa(t_l *lst, int nb);
t_l					*ft_ra(t_l *lst, int nb);
t_l					*ft_rra(t_l *lst, int nb);
t_l					*ft_lstcmp(t_l *lst, t_l *lst2);
t_l					*ft_lstcmp2(t_l *lst, t_l *lst2);
int					ft_nextswp(t_l *lst, int nb);
int					ft_lstcomp(t_l *lst, t_l *lst2);
t_l					*ft_dinsert(t_l *lst, int nb, t_opt *opt);
t_l					*ft_dinsert2(t_l *lst, t_l *lst2, int nb, t_opt *opt);
t_l					*ft_delf(t_l *lst);
t_l					*ft_pa(t_l *lst, t_l *lst2);
t_l					*ft_pb(t_l *lst, t_l *lst2);
int					ft_checklist(t_l *lst);
int					ft_min(t_l *lst);
void				ft_print(t_l *lst, t_opt *opt);
int					ft_testswap(t_l *lst);
t_l					*ft_gtoswp(t_l *lst, int nb, t_opt *opt);
t_l					*ft_fus(t_l *lst, int nb, t_opt *opt);
void				ft_printf2(int i, t_l *lst, t_l *lst2, t_opt *opt);
int					ft_tstprt(t_l *lst);
t_l					*ft_idel(t_l *lst, int i);
t_l					*ft_fstpart(t_l *lst, t_l *lst2, int i, t_opt *opt);
t_l					*ft_scdpart(t_l *lst, t_l *lst2, int i, t_opt *opt);
int					ft_getnb(t_l *lst);
t_l					*ft_fuss(t_l *lst, t_l *lst2, t_opt *opt);
t_l					*ft_truc(t_l *lst, t_l *lst2, int i, t_opt *opt);
int					ft_isrelic(t_l *lst, t_l *lst2, int i);
t_l					*ft_relic(t_l *lst, t_l *lst2, t_opt *opt, int i);
t_l					*ft_relic2(t_l *lst, t_l *lst2, t_opt *opt, int i);
int					ft_isit(t_l *lst, int i);
t_l					*ft_dinsert3(t_l *lst, t_l *lst2, int h, t_opt *opt);
int					ft_content(t_l *lst);

#endif
