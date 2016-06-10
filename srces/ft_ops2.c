/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 08:59:04 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:58:20 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

char		*ft_convert(int index)
{
	if (index == 31)
		return ("sa");
	else if (index == 32)
		return ("ra");
	else if (index == 33)
		return ("rra");
	else if (index == 34)
		return ("pb");
	else if (index == 35)
		return ("pa");
	else if (index == 36)
		return ("sb");
	else if (index == 41)
		return ("rb");
	else if (index == 42)
		return ("rrb");
	else if (index == 43)
		return ("rr");
	else if (index == 44)
		return ("rrr");
	else if (index == 45)
		return ("ss");
	else
		return (NULL);
}

void		ft_printf2(int i, t_l *lst, t_l *lst2, t_opt *opt)
{
	if (opt)
	{
		if (opt->r)
			ft_print(lst, opt);
		else if (!opt->silence && i && opt->color)
			ft_printf("\033[1m\033[%dm%s\033[0m", i, ft_convert(i));
		else if (!opt->silence && i)
			ft_printf("%s", ft_convert(i));
		if (!opt->silence && i && opt->v)
			ft_printf("\n");
		if (opt->v && !(opt->silence) && !(opt->r) && lst)
			ft_print(lst, opt);
		if (opt->v && !(opt->silence) && !(opt->r) && lst2)
			ft_print(lst2, opt);
		if ((opt->n) && !(opt->silence) && !(opt->r) && !(opt->v))
			ft_printf("\t%d\n", opt->n);
		if (opt->n)
			opt->n++;
	}
	else if (i)
		ft_printf("%s", ft_convert(i));
	if ((lst2 || ft_tstprt(lst)) && ((opt && !opt->n && !opt->v) || (!opt)))
		ft_printf(" ");
	else if (opt && !opt->n && !opt->v && !opt->r)
		ft_printf("\n");
}

void		ft_print(t_l *lst, t_opt *opt)
{
	while (lst->next)
	{
		ft_printf("%d ", lst->content);
		lst = lst->next;
	}
	if (opt && opt->n && !(opt->r))
		ft_printf("%d\t%d\n", lst->content, opt->n);
	else
		ft_printf("%d\n", lst->content);
	lst = lst->first;
}

int			ft_min(t_l *lst)
{
	int		min;

	min = lst->content;
	while (lst->next)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	if (lst->content < min)
		min = lst->content;
	return (min);
}

t_l			*ft_delf(t_l *lst)
{
	t_l		*lst2;

	lst2 = NULL;
	if (lst->next)
		lst2 = lst->next;
	lst->next = NULL;
	lst->first = NULL;
	free(lst);
	if (lst2)
	{
		lst2->first = lst2;
		while (lst2->next)
		{
			lst2->next->first = lst2->first;
			lst2 = lst2->next;
		}
	}
	if (lst2)
		return (lst2->first);
	return (NULL);
}
