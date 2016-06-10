/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:04:13 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:52:19 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

t_l				*ft_lstcmp2(t_l *lst, t_l *lst2)
{
	while (lst2->next)
	{
		if (lst2->content == lst->content)
			lst->position = lst2->position - lst->position;
		lst2 = lst2->next;
	}
	if (lst2->content == lst->content)
		lst->position = lst2->position - lst->position;
	return (lst);
}

t_l				*ft_lstcmp(t_l *lst, t_l *lst2)
{
	while (lst->next)
	{
		lst = ft_lstcmp2(lst, lst2);
		lst = lst->next;
	}
	lst = ft_lstcmp2(lst, lst2);
	return (lst->first);
}

static int		ft_near(t_l *lst)
{
	int		i;
	int		j;

	i = lst->position;
	j = i;
	while (1)
	{
		if (lst->position != i && j == i)
			j = lst->position;
		else if (lst->position != i && lst->position != j)
			return (0);
		if (lst->next)
			lst = lst->next;
		else
			return (1);
	}
}

void			ft_resolve(t_l *lst, t_l *lst2, t_opt *opt)
{
	int		nb;
	t_l		*lst3;

	while (lst->next)
		lst = lst->next;
	nb = lst->position + 1;
	lst = lst->first;
	lst = ft_lstcmp(lst, lst2);
	lst = lst->first;
	lst3 = ft_lstncpy(lst, nb);
	lst3->position = lst->position;
	lst3 = ft_swap(lst3, nb);
	lst3 = lst3->first;
	if (ft_near(lst3))
		lst = ft_bubble(lst, nb, opt);
	else if (nb < 12)
		lst = ft_dinsert(lst, nb, opt);
	else
		lst = ft_fus(lst, nb, opt);
	if (opt && opt->silence && !opt->r && (opt->n = opt->n - 1))
	{
		opt->silence = 0;
		opt->v = 1;
		ft_printf2(0, lst->first, NULL, opt);
	}
}
