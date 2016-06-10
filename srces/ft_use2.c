/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:18:37 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:02:03 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

t_l			*ft_dinsert3(t_l *lst, t_l *lst2, int content, t_opt *opt)
{
	while (lst2->content < lst->content && lst->content < content &&
			lst2->content < content)
	{
		lst = ft_rra(lst, ft_getnb(lst));
		ft_printf2(33, lst, NULL, opt);
		content = ft_content(lst);
	}
	return (lst);
}

int			ft_tstprt(t_l *lst)
{
	while (lst && lst->next)
	{
		if (lst->next->content < lst->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			ft_strlen2(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int			ft_getnb(t_l *lst)
{
	int		nb;

	nb = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		nb++;
	}
	lst = lst->first;
	return (nb);
}

t_l			*ft_truc(t_l *lst, t_l *lst2, int i, t_opt *opt)
{
	int		m;
	int		l;
	t_l		*lst3;

	lst3 = ft_lstncpy(lst2, ft_getnb(lst2));
	lst3->position = lst2->position;
	m = ft_isit(lst, i);
	l = ft_isit(lst3, i);
	while (m || l)
	{
		if ((lst3 && lst->content < lst3->content && m) || l == 0)
			m--;
		else
		{
			lst = ft_pa(lst3, lst);
			lst3 = ft_delf(lst3);
			ft_printf2(35, lst, lst3, opt);
			l--;
		}
		lst = ft_ra(lst, ft_getnb(lst));
		ft_printf2(32, lst, lst3, opt);
	}
	return (lst->first);
}
