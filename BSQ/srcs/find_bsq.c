/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:21:26 by oezzahi           #+#    #+#             */
/*   Updated: 2026/08/04 15:06:35 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_find_bsq(void)
{
	int		row;
	int		col;

	row = 0;
	g_bsq = (t_bsq){0, 0, 0};
	while (row < g_header.rows)
	{
		col = 0;
		while (col < g_header.columns)
		{
			if (g_grid[row][col] != 0)
				g_grid[row][col] = ft_local_bsq(row, col);
			if (g_grid[row][col] > g_bsq.max)
			{
				g_bsq.max = g_grid[row][col];
				g_bsq.row = row;
				g_bsq.col = col;
			}
			col++;
		}
		row++;
	}
}

int	ft_local_bsq(int row, int col)
{
	int	min;

	if (row == 0 || col == 0)
		min = 0;
	else
		min = g_grid[row - 1][col];
	if (row != 0 && min > g_grid[row - 1][col])
		min = g_grid[row - 1][col];
	if (row != 0 && col != 0 && min > g_grid[row - 1][col - 1])
		min = g_grid[row - 1][col - 1];
	if (col != 0 && min > g_grid[row][col - 1])
		min = g_grid[row][col - 1];
	return (min + 1);
}
