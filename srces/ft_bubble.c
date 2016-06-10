/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 10:26:03 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:47:36 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

int			ft_checklist(t_l *lst)
{
	while (lst->next)
	{
		if (lst->position != 0)
			return (0);
		lst = lst->next;
	}
	if (lst->position != 0)
		return (0);
	return (1);
}

int			ft_abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

int			ft_bdiff(t_l *lst)
{
	int		i;

	i = lst->position;
	while (1)
	{
		if (ft_abs(i) <= ft_abs(lst->position))
			i = lst->position;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	return (i);
}

t_l			*ft_movepile(t_l *lst, int nb, t_opt *opt)
{
	while (!ft_checklist(lst))
	{
		if (ft_bdiff(lst) > 0)
		{
			if (nb - ft_bdiff(lst) > ft_bdiff(lst) && (lst = ft_rra(lst, nb)))
				ft_printf2(33, lst, NULL, opt);
			else
			{
				lst = ft_ra(lst, nb);
				ft_printf2(32, lst, NULL, opt);
			}
		}
		else
		{
			if (ft_bdiff(lst) + nb > nb / 2 && (lst = ft_ra(lst, nb)))
				ft_printf2(32, lst, NULL, opt);
			else
			{
				lst = ft_rra(lst, nb);
				ft_printf2(33, lst, NULL, opt);
			}
		}
		lst = lst->first;
	}
	return (lst->first);
}

t_l			*ft_bubble(t_l *lst, int nb, t_opt *opt)
{
	t_l *lst2;

	lst2 = ft_lstncpy(lst, nb);
	lst2->position = lst->position;
	lst2 = ft_swap(lst2, nb);
	lst = lst->first;
	if (ft_checklist(lst))
		return (lst->first);
	else if (ft_lstcomp(lst, lst2) == 0)
		return (ft_movepile(lst, nb, opt));
	if (!ft_nextswp(lst, nb) && (lst = ft_sa(lst, nb)))
		ft_printf2(31, lst, NULL, opt);
	else if (ft_nextswp(lst, nb) < nb / 2)
	{
		lst = ft_ra(lst, nb);
		ft_printf2(32, lst, NULL, opt);
	}
	else
	{
		lst = ft_rra(lst, nb);
		ft_printf2(33, lst, NULL, opt);
	}
	lst = lst->first;
	return (ft_bubble(lst, nb, opt));
}
