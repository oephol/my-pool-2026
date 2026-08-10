/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_funcs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:03:07 by oezzahi           #+#    #+#             */
/*   Updated: 2026/08/02 09:34:55 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_FUNCS_H
# define NUM_FUNCS_H

void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
void	ft_do_op(int a, int b, char op, int (*ops[])(int, int));

#endif
