/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:20:28 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:54:09 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

t_l			*ft_sa(t_l *lst, int nb)
{
	t_l		*lst2;

	lst = lst->first;
	lst2 = lst->next;
	nb = lst->position;
	lst->position = lst2->position + 1;
	lst2->position = nb - 1;
	nb = lst->content;
	lst->content = lst2->content;
	lst2->content = nb;
	return (lst->first);
}

t_l			*ft_ra(t_l *lst, int nb)
{
	t_l		*lst2;

	lst = lst->first;
	lst2 = lst->first;
	if (lst->next)
		lst = lst->next;
	lst->first = lst;
	while (lst->next)
	{
		lst->next->first = lst->first;
		lst->position++;
		lst = lst->next;
	}
	lst->position++;
	lst->next = lst2;
	lst2->first = lst->first;
	lst2->next = NULL;
	lst2->position = lst2->position - nb + 1;
	return (lst->first);
}

t_l			*ft_rra(t_l *lst, int nb)
{
	t_l		*lst2;

	lst = lst->first;
	while (lst->next)
	{
		lst->position--;
		lst = lst->next;
	}
	lst->next = lst->first;
	lst2 = lst->first;
	lst->first = lst;
	lst2->first = lst->first;
	lst->position = lst->position + nb - 1;
	while (lst->next && lst->next != lst->first)
	{
		lst->next->first = lst->first;
		lst = lst->next;
	}
	lst->next = NULL;
	return (lst->first);
}

t_l			*ft_pushplus(t_l *lst)
{
	while (lst->next)
	{
		lst->next->position++;
		lst = lst->next;
	}
	return (lst);
}

t_l			*ft_pa(t_l *lst, t_l *lst2)
{
	t_l			*next;
	int			content;

	if (lst2->content != lst->content)
	{
		content = lst2->content;
		lst2->content = lst->content;
		if ((next = (t_l*)malloc(sizeof(t_l))) == NULL)
			return (NULL);
		next->position = lst2->position;
		lst2->position = lst->position;
		next->next = lst2->next;
		next->first = lst2->first;
		next->content = content;
		lst2->next = next;
	}
	lst = ft_pushplus(lst);
	while (lst2->next)
	{
		lst2->next->position--;
		lst2 = lst2->next;
	}
	return (lst2->first);
}
