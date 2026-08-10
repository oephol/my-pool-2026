/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:41:18 by oezzahi           #+#    #+#             */
/*   Updated: 2026/07/22 09:46:16 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (base[len])
		len++;
	if (len <= 1)
		return (0);
	while (base[i])
	{
		j = i - 1;
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ' || base[i] > '~')
			return (0);
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	return (len);
}

void	ft_print_base(long n, char *base, int len)
{
	if (n >= (long)len)
		ft_print_base(n / len, base, len);
	write(1, &base[n % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		len;

	n = nbr;
	len = ft_check_base(base);
	if (!len)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	ft_print_base(n, base, len);
}
