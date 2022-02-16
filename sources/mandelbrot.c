/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 22:28:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	render_mandelbrot(t_fractol *ctl, int x, int y)
{
	int				color;
	double			x_cartesian;
	double			y_cartesian;
	t_complex		complex_at_xy;
	t_mandelbrotian	mdlbt_at_xy;

	x_cartesian = screen_to_cartesian_x(ctl, x);
	y_cartesian = screen_to_cartesian_y(ctl, y);
	complex_at_xy = complex(x_cartesian, y_cartesian);
	mdlbt_at_xy = quick_mandelbrot(complex_at_xy, ctl->mbt.max_iterations,
			ctl->mbt.infinity);
	color = resolve_color(ctl, mdlbt_at_xy.iterations);
	draw_to_buffer(&ctl->buffer, x, y, color);
}

void	render_mandelbrot_set(t_fractol *ctl)
{
	int	x;
	int	y;

	x = ctl->width;
	while (x--)
	{
		y = ctl->height;
		while (y--)
			render_mandelbrot(ctl, x, y);
	}
	mlx_put_image_to_window(ctl->mlx, ctl->window, ctl->buffer.img, 0, 0);
}
