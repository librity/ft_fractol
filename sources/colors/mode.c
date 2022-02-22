/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/21 22:28:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	log_and_render(t_fractol *ctl)
{
	log_color_code(ctl);
	ctl->render_fractal(ctl);
}

void	switch_color_mode(t_fractol *ctl)
{
	ctl->color_code = (ctl->color_code + 1) % COLOR_MODES;
	resolve_color_renderer(ctl);
	log_and_render(ctl);
}

void	resolve_color_renderer(t_fractol *ctl)
{
	if (ctl->color_code == ESCAPE_TIME_CODE)
	{
		ctl->render_color = escape_time_color;
		return ;
	}
	if (ctl->color_code == LERP_CODE)
	{
		ctl->render_color = lerp_color;
		return ;
	}
	if (ctl->color_code == BERNSTEIN_CODE)
	{
		ctl->render_color = bernstein_color;
		return ;
	}
	ctl->render_color = escape_time_color;
}
