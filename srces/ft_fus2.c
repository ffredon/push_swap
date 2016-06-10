/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fus2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:39:12 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:26:18 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

t_l			*ft_idel(t_l *lst, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		lst = ft_delf(lst);
		j++;
	}
	if (lst)
		return (lst->first);
	else
		return (NULL);
}

int			ft_mini(int i, int j)
{
	if (i < j)
		return (i);
	return (j);
}

t_l			*ft_scdpart(t_l *lst, t_l *lst2, int i, t_opt *opt)
{
	int		j;
	int		l;
	t_l		*lst3;
	int		t;

	lst3 = ft_lstncpy(lst, ft_getnb(lst));
	lst3->position = lst->position;
	j = 0;
	l = 0;
	t = ft_mini(i, ft_getnb(lst2->first));
	while (j < t || l < i)
	{
		if ((lst2->content < lst3->content && j < t) || l == i)
			j++;
		else
		{
			lst2 = ft_pa(lst3, lst2);
			lst3 = ft_delf(lst3);
			ft_printf2(34, lst3, lst2, opt);
			l++;
		}
		lst2 = ft_ra(lst2, ft_getnb(lst2));
		ft_printf2(41, lst3, lst2, opt);
	}
	return (lst2->first);
}

t_l			*ft_fstpart(t_l *lst, t_l *lst2, int i, t_opt *opt)
{
	int		j;
	int		l;
	t_l		*lst3;
	int		t;

	lst3 = ft_lstncpy(lst2, ft_getnb(lst2));
	lst3->position = lst2->position;
	j = 0;
	l = 0;
	t = ft_mini(i, ft_getnb(lst->first));
	while (j < t || l < i)
	{
		if ((l == i) || ((lst->content < lst3->content) && j < t))
			j++;
		else
		{
			lst = ft_pa(lst3, lst);
			lst3 = ft_delf(lst3);
			ft_printf2(35, lst, lst3, opt);
			l++;
		}
		lst = ft_ra(lst, ft_getnb(lst));
		ft_printf2(32, lst, lst3, opt);
	}
	return (lst->first);
}

t_l			*ft_fuss(t_l *lst, t_l *lst2, t_opt *opt)
{
	int		j;
	int		nb;

	nb = ft_getnb(lst);
	j = 0;
	if (lst2 == NULL)
		return (lst->first);
	while (lst2 || j < nb)
	{
		if (j < nb && ((!lst2) || lst->content < lst2->content))
			j++;
		else if (lst2)
		{
			lst = ft_pa(lst2, lst);
			lst2 = ft_delf(lst2);
			ft_printf2(35, lst, lst2, opt);
		}
		lst = ft_ra(lst, ft_getnb(lst));
		ft_printf2(32, lst, lst2, opt);
	}
	return (lst->first);
}
