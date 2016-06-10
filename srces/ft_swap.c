/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 09:29:06 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:36:59 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

int				ft_dif(t_l *lst)
{
	int		n;

	if (lst->next)
		n = ft_abs(lst->position - lst->next->position);
	else
		n = lst->first->position - lst->position;
	return (n);
}

int				ft_position(t_l *lst, int nb, int bol)
{
	if (bol)
		return (0);
	if ((lst->next && lst->position != lst->next->position))
	{
		if (ft_dif(lst) == 2 || ft_dif(lst) == (nb + nb - 2) ||
			(ft_dif(lst) == nb - 2))
			return (1);
	}
	else if (lst->position != lst->first->position)
	{
		if (ft_dif(lst) == (nb + nb - 2) || ft_dif(lst) == nb - 2)
			return (1);
	}
	return (0);
}

t_l				*ft_swp(t_l *lst, int bol, int nb)
{
	if (ft_dif(lst) == 2)
	{
		lst->position--;
		lst->next->position++;
	}
	else
	{
		lst->position = lst->position + nb - 1;
		lst->next->position = lst->next->position - nb + 1;
	}
	bol = lst->content;
	lst->content = lst->next->content;
	lst->next->content = bol;
	return (lst);
}

t_l				*ft_swpfst(t_l *lst, int nb)
{
	t_l		*lst2;

	lst2 = lst->first;
	lst->position = lst->position + nb - 1;
	lst2->position = lst2->position - nb + 1;
	lst->next = lst2->next;
	lst2->next = NULL;
	lst->first = lst;
	lst2->first = lst->first;
	while (lst->next && lst->next != lst->first)
	{
		lst->next->first = lst->first;
		lst = lst->next;
	}
	lst->next = lst2;
	return (lst->first);
}

t_l				*ft_swap(t_l *lst3, int nb)
{
	int		bol;

	bol = 0;
	while (1)
	{
		if (ft_position(lst3, nb, bol) && lst3->next)
		{
			lst3 = ft_swp(lst3, bol, nb);
			bol = 1;
		}
		else if (ft_position(lst3, nb, bol))
		{
			lst3 = ft_swpfst(lst3, nb);
			bol = 1;
		}
		else
			bol = 0;
		if (lst3->next)
			lst3 = lst3->next;
		else
			break ;
	}
	return (lst3->first);
}
