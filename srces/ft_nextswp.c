/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextswp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:36:11 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:52:21 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

int			ft_lstcomp(t_l *lst, t_l *lst2)
{
	while (lst->next)
	{
		if (lst->content != lst2->content)
			return (1);
		lst = lst->next;
		lst2 = lst2->next;
	}
	if (lst->content != lst2->content)
		return (1);
	return (0);
}

int			ft_firstswp(t_l *lst, t_l *lst2)
{
	int		i;

	i = 0;
	while (lst->content == lst2->content && lst->next)
	{
		lst = lst->next;
		lst2 = lst2->next;
		i++;
	}
	if (lst->content == lst2->content)
		i = 0;
	return (i);
}

int			ft_lastswp(t_l *lst, t_l *lst2)
{
	int		i;
	int		j;

	i = 0;
	while (lst->content == lst2->content && lst->next)
	{
		lst = lst->next;
		lst2 = lst2->next;
		i++;
	}
	if (lst->content == lst2->content)
		i = 0;
	j = i;
	while (lst->next)
	{
		if (lst->content != lst2->content)
			j = i;
		lst = lst->next;
		lst2 = lst2->next;
		i++;
	}
	if (lst->content != lst2->content)
		j = i;
	return (j);
}

static int	ft_t(t_l *lst, t_l *lst2)
{
	int		i;
	int		j;

	i = 0;
	while (lst->content == lst2->content && lst->next)
	{
		lst = lst->next;
		lst2 = lst2->next;
		i++;
	}
	if (lst->content == lst2->content)
		i = 0;
	j = i;
	if (lst->next && lst->next->content != lst2->next->content)
		return (0);
	return (1);
}

int			ft_nextswp(t_l *lst, int nb)
{
	t_l		*lst2;
	int		i;
	int		i2;
	t_l		*lst3;

	lst3 = ft_lstncpy(lst, nb);
	lst3->position = lst->position;
	lst2 = ft_swap(lst3, nb);
	i = ft_firstswp(lst, lst2);
	i2 = ft_lastswp(lst, lst2);
	if (i > (nb - i2 - 1) || ((i2 == nb - 1) && ft_t(lst, lst2)))
		return (i2);
	else
		return (i);
}
