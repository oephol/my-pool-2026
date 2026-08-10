/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 09:17:01 by oezzahi           #+#    #+#             */
/*   Updated: 2026/08/04 09:17:06 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int	ft_check_rows(int fd)
{
	int		row;
	int		col;
	char	c;

	row = 1;
	while (row < g_header.rows)
	{
		col = 0;
		read(fd, &c, 1);
		while (c != '\n')
		{
			if (ft_fill_rows(c, row, col) == -1)
				return (-1);
			read(fd, &c, 1);
			col++;
		}
		if (col < g_header.columns)
			return (-1);
		row++;
	}
	if (row < g_header.rows || read(fd, &c, 1) != 0)
		return (-1);
	return (1);
}

int	ft_reallocate(char **buffer, int size)
{
	char	*temp;
	int		i;

	temp = *buffer;
	*buffer = malloc(size * 2);
	i = 0;
	while (*buffer && i < size)
	{
		(*buffer)[i] = temp[i];
		i++;
	}
	free(temp);
	return (size * 2);
}

char	*ft_get_first_row(int fd)
{
	char	*buffer;
	int		i;
	int		size;

	i = 0;
	size = 100;
	buffer = malloc(size);
	while (buffer && read(fd, &buffer[i], 1) > 0)
	{
		if (buffer[i] == '\n')
			break ;
		if (i == size - 1)
			size = ft_reallocate(&buffer, size);
		if (!buffer)
			return (NULL);
		i++;
	}
	if (i < 1)
		return (NULL);
	g_header.columns = i;
	return (buffer);
}

int	ft_fill_and_check_first_row(char *buffer)
{
	int	col;

	col = 0;
	g_grid[0] = malloc(sizeof(int) * g_header.columns);
	if (!g_grid[0])
	{
		ft_free_grid(-1);
		return (-1);
	}
	while (col < g_header.columns)
	{
		if (ft_fill_rows(buffer[col], 0, col) == -1)
		{
			free(buffer);
			return (-1);
		}
		col++;
	}
	free(buffer);
	return (1);
}

int	ft_fill_rows(unsigned char c, int row, int column)
{
	if (column >= g_header.columns)
		return (-1);
	else if (c == g_header.empty)
		g_grid[row][column] = 1;
	else if (c == g_header.obstacle)
		g_grid[row][column] = 0;
	else
		return (-1);
	return (1);
}
