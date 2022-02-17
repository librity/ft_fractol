/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 17:02:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	log_max_iterations(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Max iterations: %i\n", ctl->max_iterations);
}

void	log_infinity(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Infinity: %i\n", (int)ctl->infinity);
}
