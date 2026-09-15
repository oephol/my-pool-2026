/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <#######@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:02:24 by #######           #+#    #+#             */
/*   Updated: 2026/07/26 15:26:53 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_grid[4][4];
extern int	g_view[4][4];
void	ft_find_empty(int *row, int *col);
int		ft_checks(int row, int col, int n);

int	ft_backtrack(void)
{
	int	row;
	int	col;
	int	n;

	ft_find_empty(&row, &col);
	if (row == 4 || col == 4)
		return (1);
	n = 1;
	while (n <= 4)
	{
		if (ft_checks(row, col, n))
		{
			g_grid[row][col] = n;
			if (ft_backtrack())
				return (1);
		}
		g_grid[row][col] = 0;
		n++;
	}
	return (0);
}
