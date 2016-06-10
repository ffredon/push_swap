/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 13:16:04 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:57:55 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

t_l			*ft_initi(int content, t_l *lst)
{
	lst->content = content;
	lst->position = 0;
	lst->next = NULL;
	lst->first = lst;
	return (lst);
}

t_l			*ft_lstcpy(t_l *lst)
{
	t_l		*lst2;
	t_l		*next;

	if ((lst2 = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	lst2 = ft_initi(0, lst2);
	while (lst->next)
	{
		if ((next = (t_l*)malloc(sizeof(t_l))) == NULL)
			return (NULL);
		lst = lst->next;
		next->position = lst->position;
		next->content = 0;
		next->next = NULL;
		next->first = lst2->first;
		lst2->next = next;
		lst2 = lst2->next;
	}
	return (lst2->first);
}

t_l			*ft_lstncpy(t_l *lst, int p)
{
	int		n;
	t_l		*lst2;
	t_l		*next;

	n = 1;
	if ((lst2 = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	lst2 = ft_initi(lst->content, lst2);
	while (n < p)
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
		n++;
	}
	lst2 = lst2->first;
	return (lst2->first);
}

t_l			*ft_lstndcpy(t_l *lst, int q, int nb)
{
	t_l		*lst2;
	t_l		*next;

	while ((int)lst->position < (nb - q))
		lst = lst->next;
	if ((lst2 = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	lst2 = ft_initi(lst->content, lst2);
	while (lst->next)
	{
		if ((next = (t_l*)malloc(sizeof(t_l))) == NULL)
			return (NULL);
		lst = lst->next;
		next->position = lst->position - (nb - q);
		next->content = lst->content;
		next->next = NULL;
		next->first = lst2->first;
		lst2->next = next;
		lst2 = lst2->next;
	}
	return (lst2->first);
}

void		ft_lstdel(t_l *lst)
{
	t_l	*prev;

	prev = NULL;
	while (lst->next)
	{
		prev = lst;
		lst = lst->next;
	}
	lst->first = NULL;
	free(lst);
	if (prev)
	{
		prev->next = NULL;
		prev = prev->first;
		ft_lstdel(prev);
	}
}
