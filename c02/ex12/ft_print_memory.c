/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:55:18 by #######           #+#    #+#             */
/*   Updated: 2026/07/20 13:51:18 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned long c, int len)
{
	char	*digits;
	char	str[17];
	int		i;

	digits = "0123456789abcdef";
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		str[i] = *(digits + (c % 16));
		c = c / 16;
		i--;
	}
	write(1, str, len);
}

void	ft_print_str_in_hex(void *addr, unsigned int i, unsigned int size)
{
	char			*c;
	unsigned int	j;

	c = addr;
	j = i;
	while (j < i + 16 && j < size)
	{
		ft_print_hex(c[j], 2);
		if (j % 2 != 0)
			write(1, " ", 1);
		j++;
	}
	while (j < i + 16)
	{
		write(1, "  ", 2);
		if (j % 2 != 0)
			write(1, " ", 1);
		j++;
	}
}

void	ft_print_printable(void *addr, unsigned int i, unsigned int size)
{
	char			*str;
	unsigned int	j;

	str = addr;
	j = i;
	while (j < i + 16 && j < size)
	{
		if (str[j] < ' ' || str[j] > '~')
			write(1, ".", 1);
		else
			write(1, &str[j], 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_print_hex((unsigned long)((char *)addr + i), 16);
		write(1, ": ", 2);
		ft_print_str_in_hex(addr, i, size);
		ft_print_printable(addr, i, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
