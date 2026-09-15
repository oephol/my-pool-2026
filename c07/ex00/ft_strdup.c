/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:34:31 by #######           #+#    #+#             */
/*   Updated: 2026/07/26 12:51:23 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dup;

	len = 0;
	while (src[len])
		len++;
	dup = (char *)malloc(len * sizeof(char));
	if (dup != NULL)
	{
		i = 0;
		while (i <= len)
		{
			dup[i] = src[i];
			i++;
		}
	}
	return (dup);
}
