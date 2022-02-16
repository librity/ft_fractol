/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 00:02:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	render_pixel(t_fractol *ctl, int x, int y)
{
	int				color;
	double			x_cartesian;
	double			y_cartesian;
	t_complex		complex_at_xy;
	t_mandelbrotian	mbt_at_xy;

	x_cartesian = screen_to_cartesian_x(ctl, x);
	y_cartesian = screen_to_cartesian_y(ctl, y);
	complex_at_xy = complex(x_cartesian, y_cartesian);
	mbt_at_xy = quick_mandelbrot(complex_at_xy, ctl->max_iterations,
			ctl->infinity);
	color = resolve_color(ctl, mbt_at_xy.iterations);
	draw_to_buffer(&ctl->buffer, x, y, color);
}

static void	render_and_show(t_fractol *ctl)
{
	int	x;
	int	y;

	x = ctl->width;
	while (x--)
	{
		y = ctl->height;
		while (y--)
			render_pixel(ctl, x, y);
	}
	mlx_put_image_to_window(ctl->mlx, ctl->window, ctl->buffer.img, 0, 0);
}

void	render_julia(t_fractol *ctl)
{
	ft_putstr(JULIA_MSG);
	render_and_show(ctl);
	ft_putendl(SUCCESS_MSG);
}
