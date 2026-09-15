/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:21:36 by #######           #+#    #+#             */
/*   Updated: 2026/08/03 15:21:38 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_error(int fd)
{
	write(1, "map error\n", 10);
	close(fd);
}

void	ft_print(void)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < g_header.rows)
	{
		col = 0;
		while (col < g_header.columns)
		{
			c = g_grid[row][col] + '0';
			write(1, &c, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	ft_print_full_map(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < g_header.rows)
	{
		col = 0;
		while (col < g_header.columns)
		{
			if (g_grid[row][col] == 0)
				write(1, &g_header.obstacle, 1);
			else if (g_bsq.row - row < g_bsq.max && g_bsq.row - row >= 0
				&& g_bsq.col - col < g_bsq.max && g_bsq.col - col >= 0)
				write(1, &g_header.fill, 1);
			else
				write(1, &g_header.empty, 1);
			col++;
		}
		row++;
		write(1, "\n", 1);
	}
}
