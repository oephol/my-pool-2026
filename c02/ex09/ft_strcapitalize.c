/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ####### <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:15:52 by #######           #+#    #+#             */
/*   Updated: 2026/07/20 13:37:28 by #######          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_c_is_alpha(char c)
{
	if (c < 65 || c > 122 || (c < 97 && c > 90))
		return (0);
	return (1);
}

int	ft_c_is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_c_is_lowercase(char c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

int	ft_c_is_uppercase(char c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_c_is_alpha(str[i]))
		{
			if (i == 0)
			{
				if (ft_c_is_lowercase(str[i]))
					str[i] = str[i] - 'a' + 'A';
			}
			else if (ft_c_is_alpha(str[i - 1]) || ft_c_is_numeric(str[i - 1]))
			{
				if (ft_c_is_uppercase(str[i]))
					str[i] = str[i] - 'A' + 'a';
			}
			else if (ft_c_is_lowercase(str[i]))
				str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return (str);
}
