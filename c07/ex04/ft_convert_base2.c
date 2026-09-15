/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:01:54 by #######           #+#    #+#             */
/*   Updated: 2026/07/30 14:49:19 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_base_len(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+'
			|| base[i] == ' ' || (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base)
{
	int		i;
	int		sign;
	int		len;
	long	num;

	sign = 1;
	i = 0;
	num = 0;
	len = ft_base_len(base);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_in_base(base, str[i]) != -1)
	{
		num = num * len + ft_in_base(base, str[i]);
		i++;
	}
	return (num * sign);
}

int	ft_count_digits(long num, int base_len)
{
	int	len;

	if (num == 0)
		return (2);
	len = 1;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num)
	{
		len++;
		num /= base_len;
	}
	return (len);
}
