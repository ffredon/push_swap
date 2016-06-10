/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:56:20 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:53:15 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

int			ft_notnb(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((i != 0) && (str[i] > '9' || str[i] < '0'))
			return (1);
		else if ((str[i] > '9' || str[i] < '0') && str[i] != '-'
				&& str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int			ft_test(char *str)
{
	if ((ft_strlen(str) > 11) || (ft_notnb(str)))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (ft_atoi(str));
}

t_l			*ft_do_lst(int content, int position, t_l *lst)
{
	t_l			*next;
	int			i;

	i = 1;
	next = NULL;
	if (position)
	{
		while (i < position)
		{
			next = lst->next;
			lst = next;
			i++;
		}
		if ((next = (t_l*)malloc(sizeof(t_l))) == NULL)
			return (NULL);
		next->content = content;
		next->position = position;
		next->next = NULL;
		next->first = lst->first;
		lst->next = next;
	}
	else
		lst = ft_initi(content, lst);
	return (lst->first);
}

t_l			*ft_read(char **argv)
{
	t_l		*lst;
	int		x;

	x = 0;
	if ((lst = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	while (argv[x + 1])
	{
		lst = ft_do_lst(ft_test(argv[x + 1]), x, lst);
		x++;
	}
	return (lst);
}
