/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:21:13 by #######           #+#    #+#             */
/*   Updated: 2026/08/03 15:21:15 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_header(int fd)
{
	char	*buffer;
	int		i;
	int		size;

	size = 100;
	buffer = malloc(sizeof(int) * size);
	i = 0;
	while (read(fd, &buffer[i], 1) > 0)
	{
		if (i == size - 1)
			size = ft_reallocate(&buffer, size);
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	if (i < 4)
		return (ft_free_buffer(&buffer));
	buffer[i] = '\0';
	if (!ft_check_and_fill_header_args(buffer, i))
		return (ft_free_buffer(&buffer));
	return (1);
}

int	ft_check_and_fill_header_args(char *buffer, int i)
{
	if (buffer[i - 1] < ' ' || buffer[i - 1] > '~' || buffer[i - 2] < ' '
		|| buffer[i - 2] > '~' || buffer[i - 3] < ' ' || buffer[i - 3] > '~'
		|| buffer[i - 1] == buffer[i - 2]
		|| buffer[i - 1] == buffer[i - 3]
		|| buffer[i - 2] == buffer[i - 3])
		return (0);
	g_header.fill = buffer[i - 1];
	g_header.obstacle = buffer[i - 2];
	g_header.empty = buffer[i - 3];
	g_header.rows = ft_get_rows(buffer, i - 3);
	if (g_header.rows == 0)
		return (0);
	return (1);
}

int	ft_get_rows(char *buffer, int length)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	while (i < length)
	{
		if (buffer[i] < '0' || buffer[i] > '9')
			return (0);
		num = num * 10 + (buffer[i] - '0');
		if (num > INT_MAX)
			return (0);
		i++;
	}
	return (num);
}

int	ft_free_buffer(char **buffer)
{
	free(*buffer);
	return (0);
}
