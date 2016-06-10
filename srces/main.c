/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 09:13:37 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 13:00:28 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"
#include "libprintf.h"

t_opt	*ft_initopt(t_opt *opt)
{
	opt->v = 0;
	opt->color = 0;
	opt->silence = 0;
	opt->r = 0;
	opt->n = 0;
	return (opt);
}

t_opt	*ft_get2(t_opt *opt, char c)
{
	if (c == 'v' && opt->v == 0)
		opt->v = 1;
	else if (c == 'c' && opt->color == 0)
		opt->color = 1;
	else if (c == 's' && opt->silence == 0)
		opt->silence = 1;
	else if (c == 'r' && opt->r == 0)
		opt->r = 1;
	else if (c == 'n' && opt->n == 0)
		opt->n = 1;
	else
		return (NULL);
	return (opt);
}

t_opt	*ft_getopt(char *str)
{
	t_opt	*opt;
	int		i;

	i = 0;
	if ((opt = (t_opt*)malloc(sizeof(t_opt))) == NULL)
		return (NULL);
	opt = ft_initopt(opt);
	if (str[i] != '-')
		return (NULL);
	i++;
	while (str[i])
	{
		opt = ft_get2(opt, str[i]);
		i++;
		if (opt == NULL)
			break ;
	}
	if (opt && opt->silence)
		opt->n = 1;
	return (opt);
}

int		main(int argc, char **argv)
{
	t_l		*lst;
	t_l		*lst2;
	t_opt	*opt;

	if (argc < 2)
		return (0);
	if ((opt = ft_getopt(argv[1])))
		argv++;
	lst = ft_read(argv);
	lst = lst->first;
	lst2 = ft_deal(lst);
	if (opt && opt->r)
		ft_printf2(0, lst2, NULL, opt);
	lst2 = lst2->first;
	if (!(opt) || !(opt->r))
		ft_resolve(lst, lst2, opt);
	return (0);
}
