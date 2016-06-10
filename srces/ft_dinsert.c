/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinsert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 08:35:28 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:54:52 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

int				ft_done(t_l *lst)
{
	int		bol;
	int		i;
	int		j;

	bol = 0;
	i = lst->position;
	while (1)
	{
		if (lst->position != i && bol == 0)
		{
			bol = 1;
			j = lst->position;
		}
		else if (lst->position != i && lst->position != j)
			return (0);
		if (lst->next)
			lst = lst->next;
		else
			return (1);
	}
}

static t_l		*ft_getlst(t_l *lst)
{
	t_l		*lst2;
	t_l		*next;

	while (lst->next && lst->content < lst->next->content)
		lst = lst->next;
	if ((lst2 = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	lst = lst->next;
	lst2 = ft_initi(lst->content, lst2);
	lst2->position = lst->position;
	while (lst->next && lst->content < lst->next->content)
	{
		if ((next = (t_l*)malloc(sizeof(t_l))) == NULL)
			return (NULL);
		lst = lst->next;
		next->position = lst->position;
		next->content = lst->content;
		next->next = NULL;
		next->first = lst2->first;
		lst2->next = next;
		lst2 = lst2->next;
	}
	return (lst2->first);
}

int				ft_content(t_l *lst)
{
	int		content;

	while (lst->next)
		lst = lst->next;
	content = lst->content;
	return (content);
}

t_l				*ft_dinsert2(t_l *lst, t_l *lst2, int nb, t_opt *opt)
{
	t_l		*lst3;

	if ((lst3 = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	lst3 = ft_initi(lst->content, lst3);
	lst3->position = lst->position;
	while (lst2->content < lst->content && (lst3 = ft_pa(lst, lst3)))
	{
		lst = ft_delf(lst);
		ft_printf2(34, lst, lst3, opt);
		nb--;
	}
	while (lst3)
	{
		if (lst3->content < lst->content || lst->content == ft_min(lst))
		{
			lst = ft_pa(lst3, lst);
			lst3 = ft_delf(lst3);
			ft_printf2(35, lst, lst3, opt);
			nb++;
		}
		else if ((lst = ft_ra(lst, nb)))
			ft_printf2(32, lst, lst3, opt);
	}
	return (lst);
}

t_l				*ft_dinsert(t_l *lst, int nb, t_opt *opt)
{
	int		content;
	t_l		*lst2;

	content = ft_content(lst);
	if (ft_checklist(lst))
		return (lst->first);
	else if (ft_done(lst))
		return (ft_movepile(lst, nb, opt));
	if (ft_testswap(lst))
		lst = ft_gtoswp(lst, nb, opt);
	lst = lst->first;
	lst2 = ft_getlst(lst);
	while (lst2->content > lst->content && (lst = ft_ra(lst, nb)))
		ft_printf2(32, lst, NULL, opt);
	lst = ft_dinsert2(lst, lst2, nb, opt);
	while (!(ft_done(lst)) && lst2->next && (lst = ft_ra(lst, nb)))
	{
		ft_printf2(32, lst, NULL, opt);
		lst2 = lst2->next;
	}
	if (!(ft_done(lst)) && (lst = ft_ra(lst, nb)))
		ft_printf2(32, lst, NULL, opt);
	ft_lstdel(lst2);
	lst = lst->first;
	return (ft_dinsert(lst, nb, opt));
}
