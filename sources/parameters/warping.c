/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warping.c                                          :+:      :+:    :+:   */
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
	log_position(ctl);
	ctl->render_fractal(ctl);
}

void	warp(t_fractol *ctl, int x, int y)
{
	ctl->x_offset = screen_to_cartesian_x(ctl, x);
	ctl->y_offset = screen_to_cartesian_y(ctl, y);
	log_and_render(ctl);
}
