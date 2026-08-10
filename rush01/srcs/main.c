/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:36:28 by oezzahi           #+#    #+#             */
/*   Updated: 2026/07/26 15:32:38 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_grid[4][4];
int	g_view[4][4];
int		ft_backtrack(void);
void	ft_print_grid(void);
int		ft_check_input(int argc, char *str);

int	main(int argc, char *argv[])
{
	if (!ft_check_input(argc, argv[1]))
		return (0);
	if (!ft_backtrack())
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_print_grid();
	return (0);
}
