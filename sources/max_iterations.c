/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_iterations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:14:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/21 21:08:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	log_and_render(t_fractol *ctl)
{
	log_max_iterations(ctl);
	ctl->render_fractal(ctl);
}

void	increase_max_iterations(t_fractol *ctl)
{
	ctl->max_iterations += MAX_ITERATIONS_STEP;
	log_and_render(ctl);
}

void	decrease_max_iterations(t_fractol *ctl)
{
	int	new;

	new = ctl->max_iterations - MAX_ITERATIONS_STEP;
	if (new < 1)
		return (log_endl(MIN_ITERATIONS_MSG));
	ctl->max_iterations = new;
	log_and_render(ctl);
}
