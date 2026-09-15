/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <#######@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:53:07 by #######           #+#    #+#             */
/*   Updated: 2026/07/22 11:49:46 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i - 1;
		if (base[i] == '+' || base[i] == '-' || base[i] < ' '
			|| base[i] > '~' || ft_is_space(base[i]))
			return (0);
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_base_int(char *base, char c)
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nbr;
	int	sign;
	int	len;

	i = 0;
	sign = 1;
	nbr = 0;
	len = ft_check_base(base);
	if (!len)
		return (0);
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_base_int(base, str[i]) != -1)
	{
		nbr = nbr * len + ft_base_int(base, str[i]);
		i++;
	}
	return (sign * nbr);
}
