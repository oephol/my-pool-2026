/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:16:46 by #######           #+#    #+#             */
/*   Updated: 2026/07/29 11:31:27 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int size)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*p;
	int			i;

	i = 0;
	p = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!p)
		return (NULL);
	while (i < ac)
	{
		p[i].size = ft_strlen(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_strdup(av[i], p[i].size);
		i++;
	}
	p[i].size = 0;
	p[i].str = 0;
	p[i].copy = 0;
	return (p);
}
