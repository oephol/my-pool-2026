/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:21:45 by #######           #+#    #+#             */
/*   Updated: 2026/08/05 16:21:49 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_handle_map(int fd)
{
	g_grid = NULL;
	g_header = (t_header){0, 0, 0, 0, 0};
	if (ft_check_map(fd) == -1)
	{
		ft_print_error(fd);
		if (g_header.columns == 0 || g_header.rows == 0)
			return ;
		ft_free_grid(g_header.rows - 1);
		return ;
	}
	ft_find_bsq();
	ft_print_full_map();
	ft_free_grid(g_header.rows - 1);
}

int	ft_check_map(int fd)
{
	int		i;

	if (ft_header_first_row(fd) == -1)
		return (-1);
	i = 0;
	while (++i < g_header.rows)
	{
		g_grid[i] = malloc(g_header.columns * sizeof(int));
		if (!g_grid[i])
		{
			ft_free_grid(i - 1);
			return (-1);
		}
	}
	if (ft_check_rows(fd) == -1)
		return (-1);
	return (1);
}

void	ft_free_grid(int rows)
{
	int	i;

	i = 0;
	if (g_grid)
	{
		while (i <= rows)
		{
			if (g_grid[i])
			{
				free(g_grid[i]);
				g_grid[i] = NULL;
			}
			i++;
		}
		free(g_grid);
	}
	g_grid = NULL;
}

int	ft_header_first_row(int fd)
{
	char	*first_row;

	if (!ft_check_header(fd))
		return (-1);
	first_row = ft_get_first_row(fd);
	if (!first_row)
		return (-1);
	g_grid = malloc(g_header.rows * sizeof(int *));
	if (!g_grid)
		return (-1);
	if (ft_fill_and_check_first_row(first_row) == -1)
	{
		ft_free_grid(0);
		g_header.columns = 0;
		return (-1);
	}
	return (1);
}
