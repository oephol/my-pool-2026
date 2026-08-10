/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:23:53 by oezzahi           #+#    #+#             */
/*   Updated: 2026/08/03 15:24:01 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define INT_MAX 2147483647

typedef struct s_header
{
	int		rows;
	int		columns;
	char	empty;
	char	obstacle;
	char	fill;
}	t_header;

typedef struct s_bsq
{
	int	max;
	int	row;
	int	col;
}	t_bsq;

extern t_header		g_header;
extern t_bsq		g_bsq;
extern int			**g_grid;

void	ft_handle_map(int fd);
int		ft_check_map(int fd);
void	ft_free_grid(int rows);
int		ft_header_first_row(int fd);
int		ft_check_header(int fd);
int		ft_check_and_fill_header_args(char *buffer, int i);
int		ft_get_rows(char *buffer, int length);
int		ft_check_rows(int fd);
int		ft_reallocate(char **buffer, int size);
char	*ft_get_first_row(int fd);
int		ft_fill_and_check_first_row(char *buffer);
int		ft_fill_rows(unsigned char c, int row, int column);
void	ft_find_bsq(void);
int		ft_local_bsq(int row, int col);
void	ft_print_error(int fd);
void	ft_print(void);
void	ft_print_full_map(void);
int		ft_free_buffer(char **buffer);

#endif
