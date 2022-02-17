/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:14:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 16:57:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	log_and_render(t_fractol *ctl)
{
	log_infinity(ctl);
	render_fractal(ctl);
}

void	increase_infinity(t_fractol *ctl)
{
	ctl->infinity += INFINITY_STEP;
	log_and_render(ctl);
}

void	decrease_infinity(t_fractol *ctl)
{
	int	new;

	new = ctl->infinity - INFINITY_STEP;
	if (new < 1)
		return (log_endl(MIN_INFINITY_MSG));
	ctl->infinity = new;
	log_and_render(ctl);
}
