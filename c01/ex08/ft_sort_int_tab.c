/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:54:40 by #######           #+#    #+#             */
/*   Updated: 2026/07/17 12:04:49 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_i;

	i = 0;
	while (i < size - 1)
	{
		min_i = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min_i])
				min_i = j;
			j++;
		}
		ft_swap(&tab[i], &tab[min_i]);
		i++;
	}
}
