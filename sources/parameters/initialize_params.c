/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:39:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:42:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	initialize_fractal_params(t_fractol *ctl)
{
	ctl->julia_factor = cx_new(-0.391, -0.587);
	ctl->newton_tolerance = 0.000001;
	ctl->use_newton_root_color = USE_NEWTON_ROOT_COLOR;
	ctl->render_fractal = render_red;
	ctl->calculate_mbt = cx_fast_mandelbrot;
	ctl->calculate_julia = cx_fast_julia;
	ctl->calculate_newton = cx_newton_z3m1;
}

static void	initialize_colors(t_fractol *ctl)
{
	ctl->color_code = ESCAPE_TIME_CODE;
	resolve_color_renderer(ctl);
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
