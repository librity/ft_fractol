/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:39:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 17:02:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	initialize_julia(t_fractol *ctl)
{
	// ctl->julia_factor = complex(0.3, 0.4);
	// ctl->julia_factor = complex(-2.0, 0.0);
	// ctl->julia_factor = complex(-1.0, 0.0);
	// ctl->julia_factor = complex(0.0, 0.0);
	// ctl->julia_factor = complex(1.0, 0.0);
	// ctl->julia_factor = complex(2.0, 0.0);
	// ctl->julia_factor = complex(3.0, 0.0);
	// Dendrite fractal
	// ctl->julia_factor = complex(0.0, 1.0);
	// Douady's rabbit fractal
	// ctl->julia_factor = complex(-0.123, 0.745);
	// San Marco fractal
	// ctl->julia_factor = complex(-0.75, 0.0);
	// Siegel disk fractal
	ctl->julia_factor = complex(-0.391, -0.587);
}

void	initialize_params(t_fractol *ctl)
{
	ctl->width = WINDOW_WIDTH;
	ctl->height = WINDOW_HEIGHT;
	// ctl->fratal_code = MANDELBROT_CODE;
	ctl->fratal_code = JULIA_CODE;
	ctl->max_iterations = MAX_ITERATIONS;
	ctl->infinity = DIVERSION_LIMIT;
	ctl->zoom = ZOOM;
	ctl->x_offset = X_OFFSET;
	ctl->y_offset = Y_OFFSET;
	ctl->dye = DYE4;
	ctl->lerp_steps = LERP_STEPS;
	ctl->lerp_from = GRADIENT2_FROM;
	ctl->lerp_to = GRADIENT2_TO;
	initialize_julia(ctl);
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
