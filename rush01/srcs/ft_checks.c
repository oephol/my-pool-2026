/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <#######@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:01:44 by #######           #+#    #+#             */
/*   Updated: 2026/07/26 15:37:04 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


extern int	g_grid[4][4];
extern int	g_view[4][4];
int	ft_check_view_coltop(int view, int col);
int	ft_check_view_colbottom(int view, int col);
int	ft_check_view_rowright(int view, int row);
int	ft_check_view_rowleft(int view, int row);

int	ft_check_in_row(int row, int n)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (g_grid[row][col] == n)
			return (1);
		col++;
	}
	return (0);
}

int	ft_check_in_col(int col, int n)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (g_grid[row][col] == n)
			return (1);
		row++;
	}
	return (0);
}

int	ft_row_complete(int row)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (g_grid[row][col] == 0)
			return (0);
		col++;
	}
	return (1);
}

int	ft_col_complete(int col)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (g_grid[row][col] == 0)
			return (0);
		row++;
	}
	return (1);
}

int	ft_checks(int g_grid[4][4], int g_view[4][4], int row, int col, int n)
{
	if (ft_check_in_row(row, n)
		|| ft_check_in_col(col, n))
		return (0);
	g_grid[row][col] = n;
	if (ft_col_complete(col)
		&& (!ft_check_view_coltop(g_view[0][col], col)
		|| !ft_check_view_colbottom(g_view[1][col], col)))
	{
		g_grid[row][col] = 0;
		return (0);
	}
	if (ft_row_complete(row)
		&& (!ft_check_view_rowleft(g_view[2][row], row)
		|| !ft_check_view_rowright(g_view[3][row], row)))
	{
		g_grid[row][col] = 0;
		return (0);
	}
	return (1);
}
