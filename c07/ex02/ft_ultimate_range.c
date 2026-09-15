/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:04:09 by #######           #+#    #+#             */
/*   Updated: 2026/08/03 17:02:13 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
#include <stdio.h>

int main(void)
{
	int *p;
	ft_ultimate_range(&p, 5, 10);
	int i = 0;
	while (i < 5)
	{
		printf("%d,  ", p[i]);
		i++;
	}
	printf("\n");
	return (0);
}
