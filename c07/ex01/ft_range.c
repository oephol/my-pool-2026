/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:52:16 by oezzahi           #+#    #+#             */
/*   Updated: 2026/07/26 13:03:26 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
		return (NULL);
	arr = (int *)malloc((max - min) * sizeof(int));
	if (arr != NULL)
	{
		i = 0;
		while (i < max - min)
		{
			arr[i] = min + i;
			i++;
		}
	}
	return (arr);
}
