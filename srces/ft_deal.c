/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:06:03 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:04:50 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

static int	ft_count(t_l *lst)
{
	int		nb;

	nb = 0;
	if (lst)
	{
		nb++;
		while (lst->next)
		{
			lst = lst->next;
			nb++;
		}
	}
	return (nb);
}

t_l			*ft_deal(t_l *lst)
{
	t_l		*lst2;
	int		nb;

	nb = ft_count(lst);
	if (nb <= 20)
	{
		lst2 = ft_lstcpy(lst);
		lst2 = ft_insert(lst, lst2);
	}
	else
	{
		lst2 = ft_lstncpy(lst, nb);
		lst2 = ft_trif(lst2, nb);
	}
	return (lst2->first);
}
