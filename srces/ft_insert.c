/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 16:03:26 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:27:03 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

t_l			*ft_insert2(t_l *lst, t_l *lst2, int tmp, int tmp2)
{
	while (lst2->position <= lst->position && lst2->position != 0)
	{
		if ((lst2->position + 2) % 2)
			tmp = lst2->content;
		else
			tmp2 = lst2->content;
		if ((lst2->position + 2) % 2)
			lst2->content = tmp2;
		else
			lst2->content = tmp;
		if (lst2->next)
			lst2 = lst2->next;
		else
			return (lst2);
	}
	return (lst2);
}

t_l			*ft_insert1(t_l *lst, t_l *lst2, int tmp, int tmp2)
{
	while (lst->content > lst2->content && lst->position > lst2->position)
		lst2 = lst2->next;
	if (lst->content == lst2->content && lst2->position < lst->position)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (lst2->position < lst->position)
	{
		if ((lst2->position + 2) % 2)
			tmp = lst2->content;
		else
			tmp2 = lst2->content;
	}
	lst2->content = lst->content;
	if ((lst2->position) < lst->position)
	{
		if (lst2->next)
			lst2 = lst2->next;
		lst2 = ft_insert2(lst, lst2, tmp, tmp2);
	}
	return (lst2->first);
}

t_l			*ft_insert(t_l *lst, t_l *lst2)
{
	int		tmp;
	int		tmp2;

	tmp = 0;
	tmp2 = 0;
	while (lst->next)
	{
		lst2 = ft_insert1(lst, lst2, tmp, tmp2);
		lst = lst->next;
	}
	lst2 = ft_insert1(lst, lst2, tmp, tmp2);
	return (lst2->first);
}
