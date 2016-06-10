/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trif.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:34:36 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:04:34 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

static t_l		*ft_tst(t_l *lst, t_l *lst2, t_l *lst3)
{
	if (lst2->content == lst3->content)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (lst);
}

static t_l		*ft_fusion2(t_l *lst, t_l *lst2, t_l *lst3, int bol)
{
	while (1)
	{
		if (bol != 1 && (lst2->content < lst3->content || bol == 2))
		{
			lst->content = lst2->content;
			if (lst2->next)
				lst2 = lst2->next;
			else
				bol = 1;
		}
		else
		{
			lst = ft_tst(lst, lst2, lst3);
			lst->content = lst3->content;
			if (lst3->next)
				lst3 = lst3->next;
			else
				bol = 2;
		}
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	return (lst);
}

static t_l		*ft_fusion1(t_l *lst, t_l *lst2, t_l *lst3, int bol)
{
	if (lst2->content == lst3->content)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	lst = ft_fusion2(lst, lst2, lst3, bol);
	lst2 = lst2->first;
	lst3 = lst3->first;
	ft_lstdel(lst2);
	ft_lstdel(lst3);
	return (lst->first);
}

static t_l		*ft_fusion(t_l *lst, t_l *lst2, t_l *lst3)
{
	int		bol;

	bol = 0;
	lst = ft_fusion1(lst, lst2, lst3, bol);
	return (lst->first);
}

t_l				*ft_trif(t_l *lst, int nb)
{
	t_l		*lst2;
	t_l		*lst3;
	int		p;
	int		q;

	p = nb / 2;
	q = nb - p;
	lst2 = ft_lstncpy(lst, p);
	lst3 = ft_lstndcpy(lst, q, nb);
	if (p >= 2)
		lst2 = ft_trif(lst2, p);
	if (q >= 2)
		lst3 = ft_trif(lst3, q);
	return (ft_fusion(lst, lst2, lst3));
}
