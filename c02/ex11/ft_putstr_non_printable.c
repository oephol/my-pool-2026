/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:37:38 by #######           #+#    #+#             */
/*   Updated: 2026/07/20 12:40:51 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned char c)
{
	char	*digit;

	digit = "0123456789abcdef";
	write(1, &digit[c / 16], 1);
	write(1, &digit[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			write(1, "\\", 1);
			ft_print_hex((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
