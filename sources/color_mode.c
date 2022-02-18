/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/18 17:09:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	log_and_render(t_fractol *ctl)
{
	log_color_code(ctl);
	render_fractal(ctl);
}

void	switch_color_mode(t_fractol *ctl)
{
	ctl->color_code = (ctl->color_code + 1) % COLOR_MODES;
	log_and_render(ctl);
}

int	render_color(t_fractol *ctl, int iterations)
{
	if (ctl->color_code == ESCAPE_TIME_CODE)
		return (escape_time_color(ctl, iterations));
	if (ctl->color_code == LERP_CODE)
		return (lerp_color(ctl, iterations));
	if (ctl->color_code == BERNSTEIN_CODE)
		return (bernstein_color(ctl, iterations));
	return (escape_time_color(ctl, iterations));
}
