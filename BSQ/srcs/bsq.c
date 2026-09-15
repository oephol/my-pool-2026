/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:20:59 by #######           #+#    #+#             */
/*   Updated: 2026/08/03 15:21:02 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_header	g_header;
t_bsq		g_bsq;
int			**g_grid;

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	if (argc == 1)
		ft_handle_map(0);
	else
	{
		while (i < argc)
		{
			if (i != 1)
				write(1, "\n", 1);
			fd = open(argv[i], O_RDONLY);
			ft_handle_map(fd);
			i++;
		}
	}
	return (0);
}
