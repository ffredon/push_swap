/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:58:14 by fredon            #+#    #+#             */
/*   Updated: 2016/02/08 12:53:52 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

static int		ft_sign2(int c, char *str)
{
	int		sign;

	sign = 1;
	if (str[c] == '-')
		sign = -1;
	return (sign);
}

static int		ft_overflow(long int i)
{
	int		j;

	if (i > 2147483647 || i < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	j = i;
	return (j);
}

int				ft_atoi(char *str)
{
	long int	i;
	int			c;
	int			sign;

	i = 0;
	c = 0;
	if ((sign = ft_sign2(c, str)) < 0)
		c++;
	else if (str[c] == '+')
		c++;
	while (str[c] <= '9' && str[c] >= '0')
	{
		i = i * 10;
		i = i + str[c] - 48;
		c++;
	}
	i = sign * i;
	return (ft_overflow(i));
}
