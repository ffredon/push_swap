/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:58:58 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:55:36 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

void		ft_firsttri(t_l *lst, t_l *l2, t_opt *opt, int x)
{
	int		nb;

	nb = ft_getnb(lst);
	if (lst->content > lst->next->content && l2->content > l2->next->content)
	{
		lst = ft_sa(lst, nb);
		l2 = ft_sa(l2, nb);
		ft_printf2(45, lst, l2, opt);
	}
	else if (lst->content > lst->next->content)
	{
		lst = ft_sa(lst, nb);
		ft_printf2(31, lst, l2, opt);
	}
	else if (l2->content > l2->next->content)
	{
		l2 = ft_sa(l2, x);
		ft_printf2(36, lst, l2, opt);
	}
	lst = ft_ra(lst, nb);
	l2 = ft_ra(l2, x);
	ft_printf2(43, lst, l2, opt);
	lst = ft_ra(lst, nb);
	l2 = ft_ra(l2, x);
	ft_printf2(43, lst, l2, opt);
}

t_l			*ft_case(t_l *lst, t_l *lst2, t_opt *opt, int nb)
{
	if (lst->content > lst->next->content)
	{
		lst = ft_sa(lst, nb);
		ft_printf2(31, lst, lst2, opt);
	}
	lst = ft_ra(lst, nb);
	ft_printf2(32, lst, lst2, opt);
	lst = ft_ra(lst, nb);
	lst2 = ft_ra(lst2, ft_getnb(lst2));
	ft_printf2(43, lst, lst2, opt);
	return (lst->first);
}

void		ft_firstsort(t_l *lst, t_l *lst2, t_opt *opt)
{
	int		i;

	i = 0;
	while (i < (ft_getnb(lst2->first) - 1))
	{
		ft_firsttri(lst->first, lst2->first, opt, ft_getnb(lst->first));
		i = i + 2;
	}
	if (i == ft_getnb(lst2->first) - 1 && i == ft_getnb(lst->first) - 2 &&
		(lst = ft_case(lst->first, lst2->first, opt, ft_getnb(lst->first))))
		i = i + 2;
	if (i < ft_getnb(lst2->first))
	{
		lst = ft_ra(lst, ft_getnb(lst->first));
		lst2 = ft_ra(lst2, ft_getnb(lst2->first));
		ft_printf2(43, lst->first, lst2->first, opt);
		i++;
	}
	if (i < ft_getnb(lst->first))
	{
		lst = ft_ra(lst->first, ft_getnb(lst->first));
		ft_printf2(32, lst->first, lst2->first, opt);
		i++;
	}
}

t_l			*ft_sort(t_l *lst, t_l *lst2, t_opt *opt)
{
	int		i;
	int		k;

	i = 2;
	while (lst2 && (i) < (ft_getnb(lst) + ft_getnb(lst2)))
	{
		k = 0;
		while (lst2 && k < (ft_getnb(lst) + ft_getnb(lst2) - i - 1))
		{
			if (ft_getnb(lst) >= i && ft_getnb(lst) <= ft_getnb(lst2) &&
				(ft_getnb(lst2) >= (i * 2) || ft_getnb(lst2) == i) &&
				(lst = ft_fstpart(lst, lst2, i, opt)))
				lst2 = ft_idel(lst2, i);
			else if (ft_getnb(lst) > i &&
					((lst2 = ft_scdpart(lst, lst2, i, opt))))
				lst = ft_idel(lst, i);
			k = (i * 2) + k;
		}
		if (lst2 && ft_isrelic(lst, lst2, i) &&
			(lst = ft_relic(lst, lst2, opt, i)))
			lst2 = ft_relic2(lst, lst2, opt, i);
		i = i * 2;
	}
	return (ft_fuss(lst, lst2, opt));
}

t_l			*ft_fus(t_l *lst, int nb, t_opt *opt)
{
	t_l			*lst2;
	int			x;

	if ((lst2 = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	lst2 = ft_initi(lst->content, lst2);
	lst2->position = lst->position;
	x = 0;
	while (x < (nb / 2))
	{
		lst2 = ft_pa(lst, lst2);
		lst = ft_delf(lst);
		ft_printf2(34, lst, lst2, opt);
		x++;
	}
	nb = nb - x;
	ft_firstsort(lst, lst2, opt);
	return (ft_sort(lst, lst2, opt));
}
