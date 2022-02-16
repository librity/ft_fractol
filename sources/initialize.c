/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:39:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 23:50:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	initialize_params(t_fractol *ctl)
{
	ctl->width = WINDOW_WIDTH;
	ctl->height = WINDOW_HEIGHT;
	ctl->fratal_code = JULIA_CODE;
	ctl->max_iterations = MAX_ITERATIONS;
	ctl->infinity = DIVERSION_LIMIT;
	ctl->zoom = ZOOM;
	ctl->x_offset = X_OFFSET;
	ctl->y_offset = Y_OFFSET;
	ctl->lerp_steps = LERP_STEPS;
	ctl->lerp_from = GRADIENT1_FROM;
	ctl->lerp_to = GRADIENT1_TO;
	ctl->julia_factor = complex(4.0, 5.0);
}

void	initialize(t_fractol *ctl)
{
	initialize_params(ctl);
	initialize_mlx(ctl);
	initialize_mlx_window(ctl);
	initialize_mlx_buffer(ctl);
	initialize_mlx_hooks(ctl);
	render_fractal(ctl);
}
