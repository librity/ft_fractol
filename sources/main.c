/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:17:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/14 00:20:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

const double	blue_weight = 0.7;
const double	red_weight = 0.5;
const double	green_weight = 0.2;

int	resolve_color(double iterations, double max_iterations)
{
	double	normalized_iterations;
	double	brightness;
	int		blue;
	int		red;
	int		green;

	normalized_iterations = ft_map_d((t_map_d){iterations, 0, max_iterations, 0,
			1});
	brightness = ft_map_d((t_map_d){sqrt(normalized_iterations), 0, 1, 0, 255
			* 3});
	blue = brightness * blue_weight;
	brightness -= 255;
	red = brightness * red_weight;
	brightness -= 255;
	green = brightness * green_weight;
	return (rgb_to_int(red, green, blue));
}

void	render_mandelbrot(t_fractol *ctl)
{
	int				x;
	int				y;
	int				color;
	double			x_cartesian;
	double			y_cartesian;
	double			normalized_iterations;
	double			brightness;
	t_complex		complex_at_xy;
	t_mandelbrotian	mdlbt_at_xy;
	int				half_width;
	int				half_height;

	half_width = ctl->buffer.width / 2.0;
	half_height = ctl->buffer.height / 2.0;
	x = ctl->width;
	while (x--)
	{
		y = ctl->height;
		while (y--)
		{
			x_cartesian = (x - half_width + ctl->mbt.x_offset) / ctl->mbt.zoom;
			y_cartesian = (y - half_height + ctl->mbt.y_offset) / ctl->mbt.zoom;
			complex_at_xy = complex(x_cartesian, y_cartesian);
			mdlbt_at_xy = quick_mandelbrot(complex_at_xy,
											ctl->mbt.max_iterations,
											ctl->mbt.infinity);
			color = resolve_color(mdlbt_at_xy.iterations,
									ctl->mbt.max_iterations);
			draw_to_buffer(&ctl->buffer, x, y, color);
		}
	}
	mlx_put_image_to_window(ctl->mlx, ctl->window, ctl->buffer.img, 0, 0);
}

void	initialize(t_fractol *ctl)
{
	initialize_mlx(ctl);
	initialize_mlx_window(ctl);
	initialize_mlx_buffer(ctl);
	initialize_mlx_hooks(ctl);
}

t_fractol	initialize_pararams(void)
{
	t_fractol	ctl;

	ctl.width = 500;
	ctl.height = 500;
	ctl.mbt.max_iterations = 50;
	ctl.mbt.infinity = 4;
	ctl.mbt.zoom = 200;
	ctl.mbt.x_offset = -100;
	ctl.mbt.y_offset = 0;
	return (ctl);
}

int	main(void)
{
	t_fractol	ctl;

	ctl = initialize_pararams();
	ft_putendl("=== MinilibX Test Program: Mandelbrot ===");
	initialize(&ctl);
	ft_putstr(" => Rendering Mandelbrot set...");
	render_mandelbrot(&ctl);
	ft_putendl(" OK");
	mlx_loop(ctl.mlx);
	return (0);
}
