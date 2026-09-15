/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <#######@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:24:42 by #######           #+#    #+#             */
/*   Updated: 2026/07/27 11:02:02 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_fill_with_0(int board[][10])
{
	int		row;
	int		col;

	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	ft_check_row_diagonal(int board[][10], int row, int col)
{
	int	i;

	i = 1;
	while (col - i >= 0 && row - i >= 0)
	{
		if (board[row - i][col - i] == 1)
			return (1);
		i++;
	}
	i = 1;
	while (col - i >= 0 && row + i < 10)
	{
		if (board[row + i][col - i] == 1)
			return (1);
		i++;
	}
	i = col - 1;
	while (i >= 0)
	{
		if (board[row][i] == 1)
			return (1);
		i--;
	}
	return (0);
}

void	ft_print_arrangement(int board[][10])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	col = 0;
	while (col < 10)
	{
		row = 0;
		while (row < 10)
		{
			if (board[row][col] == 1)
			{
				c = row + '0';
				write(1, &c, 1);
			}
			row++;
		}
		col++;
	}
	write(1, "\n", 1);
}

void	ft_place_queen(int board[][10], int col, int *arangments)
{
	int	row;

	if (col == 10)
	{
		*arangments += 1;
		ft_print_arrangement(board);
	}
	else
	{
		row = 0;
		while (row < 10)
		{
			if (!ft_check_row_diagonal(board, row, col))
			{
				board[row][col] = 1;
				ft_place_queen(board, col + 1, arangments);
				board[row][col] = 0;
			}
			row++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arangments;
	int	board[10][10];

	arangments = 0;
	ft_fill_with_0(board);
	ft_place_queen(board, 0, &arangments);
	return (arangments);
}
