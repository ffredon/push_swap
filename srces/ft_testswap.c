/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:36:16 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:37:25 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

t_l			*ft_gtoswp(t_l *lst, int nb, t_opt *opt)
{
	while (lst->content < lst->next->content)
	{
		lst = ft_ra(lst, nb);
		ft_printf2(32, lst, NULL, opt);
	}
	lst = ft_sa(lst, nb);
	ft_printf2(31, lst, NULL, opt);
	return (lst->first);
}

int			ft_testswap(t_l *lst)
{
	while (1)
	{
		if (lst->next && lst->content > lst->next->content && ft_dif(lst) == 2)
			return (1);
		else if (lst->next && lst->content > lst->next->content)
			break ;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	return (0);
}
