/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:39:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 19:11:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	initialize_fractal_params(t_fractol *ctl)
{
	ctl->julia_factor = complex(-0.391, -0.587);
	ctl->newton_tolerance = 0.000001;
}

static void	initialize_colors(t_fractol *ctl)
{
	ctl->color_code = ESCAPE_TIME_CODE;
	ctl->dye = DYE4;
	ctl->lerp_steps = LERP_STEPS;
	ctl->lerp_from = LERP3_FROM;
	ctl->lerp_to = LERP3_TO;
	if (ctl->lerp_from > ctl->lerp_to)
		ft_swap(&ctl->lerp_from, &ctl->lerp_to);
}

void	initialize_params(t_fractol *ctl, t_mlx_image *buffer)
{
	ctl->width = WINDOW_WIDTH;
	ctl->height = WINDOW_HEIGHT;
	ctl->max_iterations = MAX_ITERATIONS;
	ctl->infinity = MY_INFINITY;
	ctl->zoom = ZOOM;
	ctl->scale_factor = SCALE_FACTOR;
	ctl->x_offset = X_OFFSET;
	ctl->y_offset = Y_OFFSET;
	ctl->buffer = buffer;
	initialize_colors(ctl);
	initialize_fractal_params(ctl);
}
