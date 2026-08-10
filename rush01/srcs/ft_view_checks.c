/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_view_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:02:07 by oezzahi           #+#    #+#             */
/*   Updated: 2026/07/26 15:02:10 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_grid[4][4];
extern int	g_view[4][4];

int	ft_check_view_coltop(int view, int col)
{
	int	row;
	int	i;
	int	sight;

	sight = 1;
	row = 1;
	while (row < 4)
	{
		i = 0;
		sight++;
		while (i < row)
		{
			if (g_grid[row][col] < g_grid[i][col])
			{
				sight--;
				break ;
			}
			i++;
		}
		row++;
	}
	return (sight == view);
}

int	ft_check_view_colbottom(int view, int col)
{
	int	row;
	int	i;
	int	sight;

	sight = 1;
	row = 2;
	while (row >= 0)
	{
		i = 3;
		sight++;
		while (i > row)
		{
			if (g_grid[row][col] < g_grid[i][col])
			{
				sight--;
				break ;
			}
			i--;
		}
		row--;
	}
	return (sight == view);
}

int	ft_check_view_rowright(int view, int row)
{
	int	col;
	int	i;
	int	sight;

	sight = 1;
	col = 2;
	while (col >= 0)
	{
		i = 3;
		sight++;
		while (i > col)
		{
			if (g_grid[row][col] < g_grid[row][i])
			{
				sight--;
				break ;
			}
			i--;
		}
		col--;
	}
	return (sight == view);
}

int	ft_check_view_rowleft(int view, int row)
{
	int	col;
	int	i;
	int	sight;

	sight = 1;
	col = 1;
	while (col < 4)
	{
		i = 0;
		sight++;
		while (i < col)
		{
			if (g_grid[row][col] < g_grid[row][i])
			{
				sight--;
				break ;
			}
			i++;
		}
		col++;
	}
	return (sight == view);
}
