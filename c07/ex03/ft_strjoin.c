/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <#######@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:43:39 by #######           #+#    #+#             */
/*   Updated: 2026/07/30 18:29:59 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_join(int size, char **strs, char *sep, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && (i + 1) != size)
			str[k++] = sep[j++];
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*str;
	int		i;
	int		sep_len;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		if (str)
			str [0] = '\0';
		return (str);
	}
	i = 0;
	len = 1;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		len += ft_strlen(strs[i]) + sep_len;
		i++;
	}
	len -= sep_len;
	str = (char *)malloc(len);
	if (str != NULL)
		str = ft_join(size, strs, sep, str);
	return (str);
}
