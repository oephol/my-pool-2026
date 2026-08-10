/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:16:49 by oezzahi           #+#    #+#             */
/*   Updated: 2026/08/02 11:20:45 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ops.h"
#include "num_funcs.h"

int	main(int argc, char **argv)
{
	char	op;
	int		num1;
	int		num2;
	int		(*ops[5])(int, int);

	if (argc != 4)
		return (0);
	if (argv[2][1] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	ops[0] = add;
	ops[1] = sub;
	ops[2] = mul;
	ops[3] = div;
	ops[4] = mod;
	num1 = ft_atoi(argv[1]);
	op = argv[2][0];
	num2 = ft_atoi(argv[3]);
	ft_do_op(num1, num2, op, ops);
	write(1, "\n", 1);
	return (0);
}
