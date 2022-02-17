/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:21:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 16:27:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	log_and_render(t_fractol *ctl)
{
	log_colors(ctl);
	render_fractal(ctl);
}

void	shift_colors_up(t_fractol *ctl)
{
	ctl->dye += DYE_SHIFT;
	ctl->lerp_from += LERP_SHIFT;
	ctl->lerp_to += LERP_SHIFT;
	log_and_render(ctl);
}

void	shift_colors_down(t_fractol *ctl)
{
	ctl->dye -= DYE_SHIFT;
	ctl->lerp_from -= LERP_SHIFT;
	ctl->lerp_to -= LERP_SHIFT;
	log_and_render(ctl);
}
