/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:02:42 by oezzahi           #+#    #+#             */
/*   Updated: 2026/07/26 15:37:49 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_grid[4][4];
extern int	g_view[4][4];

void	ft_print_grid(void)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = g_grid[row][col] + '0';
			write(1, &c, 1);
			if (col != 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	ft_find_empty(int *row, int *col)
{
	*row = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (g_grid[*row][*col] == 0)
				break ;
			(*col)++;
		}
		if (*col < 4 && g_grid[*row][*col] == 0)
			break ;
		(*row)++;
	}
}

int	ft_fill_view(char *str)
{
	int	row;
	int	col;
	int	k;

	row = 0;
	k = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (str[k] < '1' || str[k] > '4')
				return (0);
			g_view[row][col] = str[k] - '0';
			k++;
			if ((row != 3 || col != 3) && str[k++] != ' ')
				return (0);
			col++;
		}
		row++;
	}
	return (str[k] == '\0');
}

int	ft_check_input(int argc, char *str)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_fill_view(str))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
