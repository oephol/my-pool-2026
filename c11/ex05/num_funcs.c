/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:39:05 by #######           #+#    #+#             */
/*   Updated: 2026/08/02 09:33:10 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "num_funcs.h"

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(nbr * sign));
}

void	ft_do_op(int a, int b, char op, int (*ops[])(int, int))
{
	if (op == '+')
		ft_putnbr(ops[0](a, b));
	else if (op == '-')
		ft_putnbr(ops[1](a, b));
	else if (op == '*')
		ft_putnbr(ops[2](a, b));
	else if (op == '/')
	{
		if (b == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr(ops[3](a, b));
	}
	else if (op == '%')
	{
		if (b == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(ops[4](a, b));
	}
	else
		ft_putnbr(0);
}
