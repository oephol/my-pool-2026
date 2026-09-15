/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:20:01 by #######           #+#    #+#             */
/*   Updated: 2026/07/30 09:20:25 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_digits(long num, int base_len);
int		ft_atoi(char *str, char *base);
int		ft_check_base(char *base);
int		ft_base_len(char *base);
void	ft_put_in_base(long num, char *base, int size, char *result);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		len;
	int		num;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	num = ft_atoi(nbr, base_from);
	len = ft_count_digits(num, ft_base_len(base_to));
	result = malloc(sizeof(char) * len);
	if (!result)
		return (NULL);
	result[len - 1] = '\0';
	ft_put_in_base(num, base_to, len - 2, result);
	return (result);
}

void	ft_put_in_base(long num, char *base, int size, char *result)
{
	int	base_len;

	base_len = ft_base_len(base);
	if (num == 0)
	{
		result[0] = base[0];
		return ;
	}
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	while (num)
	{
		result[size] = base[num % base_len];
		num = num / base_len;
		size--;
	}
}
