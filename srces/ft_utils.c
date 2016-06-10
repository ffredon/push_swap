/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:53:52 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:04:14 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

int			ft_isrelic(t_l *lst, t_l *lst2, int i)
{
	if ((ft_getnb(lst) % (i * 2)) || ((ft_getnb(lst2) % (i * 2))))
		return (1);
	return (0);
}

int			ft_isit(t_l *lst, int i)
{
	return (ft_getnb(lst) % (i * 2));
}

t_l			*ft_relic(t_l *lst, t_l *lst2, t_opt *opt, int i)
{
	int		nb;
	t_l		*lst3;

	lst3 = ft_lstncpy(lst2, ft_getnb(lst2));
	lst3->position = lst2->position;
	if (ft_isit(lst, i) && ft_isit(lst3, i) && ft_getnb(lst3) != i)
	{
		lst = ft_truc(lst, lst3, i, opt);
		while (ft_isit(lst3, i))
			lst3 = ft_delf(lst3);
	}
	else if ((nb = ft_isit(lst, i)))
	{
		while (nb)
		{
			lst = ft_ra(lst, ft_getnb(lst));
			ft_printf2(32, lst, lst3, opt);
			nb--;
		}
	}
	return (lst->first);
}

int			ft_mp(t_l *lst, t_l *lst2)
{
	lst = lst->first;
	while (1)
	{
		lst2 = lst2->first;
		while (1)
		{
			if (lst2->content == lst->content)
				return (1);
			else if (lst2->next)
				lst2 = lst2->next;
			else
				break ;
		}
		if (lst->next)
			lst = lst->next;
		else
			return (0);
	}
}

t_l			*ft_relic2(t_l *lst, t_l *lst2, t_opt *opt, int i)
{
	int		x;

	if ((ft_mp(lst, lst2)) && ft_isit(lst2, i))
	{
		while (ft_isit(lst2, i))
			lst2 = ft_delf(lst2);
	}
	else if ((x = ft_isit(lst2, i)))
	{
		while (x)
		{
			lst2 = ft_ra(lst2, x);
			ft_printf2(41, lst, lst2, opt);
			x--;
		}
	}
	if (lst2)
		return (lst2->first);
	return (NULL);
}
