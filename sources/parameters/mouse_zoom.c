/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:14:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/21 21:08:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	log_and_render(t_fractol *ctl)
{
	log_zoom(ctl);
	log_position(ctl);
	ctl->render_fractal(ctl);
}

static void	follow_mouse(t_fractol *ctl, int x, int y)
{
	if (x < ctl->buffer->half_width - DEADZONE)
		ctl->x_offset -= ctl->scale_factor;
	else if (x > ctl->buffer->half_width + DEADZONE)
		ctl->x_offset += ctl->scale_factor;
	if (y < ctl->buffer->half_height - DEADZONE)
		ctl->y_offset -= ctl->scale_factor;
	else if (y > ctl->buffer->half_height + DEADZONE)
		ctl->y_offset += ctl->scale_factor;
}

void	mouse_zoom_in(t_fractol *ctl, int x, int y)
{
	ctl->scale_factor /= ZOOM_MAGNIFICATION;
	ctl->zoom *= ZOOM_MAGNIFICATION;
	follow_mouse(ctl, x, y);
	log_and_render(ctl);
}

void	mouse_zoom_out(t_fractol *ctl, int x, int y)
{
	ctl->scale_factor *= ZOOM_MAGNIFICATION;
	ctl->zoom /= ZOOM_MAGNIFICATION;
	follow_mouse(ctl, x, y);
	log_and_render(ctl);
}
