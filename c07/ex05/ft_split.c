/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:03:28 by #######           #+#    #+#             */
/*   Updated: 2026/07/28 16:04:24 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_sep(charset, str[i]))
		i++;
	return (i);
}

int	ft_count_strs(char *str, char *charset)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (ft_is_sep(charset, str[i]) && str[i])
			i++;
		if (str[i])
			num++;
		while (!ft_is_sep(charset, str[i]) && str[i])
			i++;
	}
	return (num);
}

char	*ft_strcpy(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;

	len = ft_strlen(str, charset);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word)
	{
		word[len] = '\0';
		i = 0;
		while (str[i] && !ft_is_sep(charset, str[i]))
		{
			word[i] = str[i];
			i++;
		}
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**list;
	int		n;
	int		i;
	int		index;

	n = ft_count_strs(str, charset);
	list = (char **)malloc(sizeof(char *) * (n + 1));
	if (!list)
		return (NULL);
	list[n] = NULL;
	i = 0;
	index = 0;
	while (str[i])
	{
		while (ft_is_sep(charset, str[i]) && str[i])
			i++;
		if (str[i])
		{
			list[index] = ft_strcpy(str + i, charset);
			index++;
		}
		while (!ft_is_sep(charset, str[i]) && str[i])
			i++;
	}
	return (list);
}
