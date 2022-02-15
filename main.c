/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:17:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 20:42:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double	ft_lerp_d(double from, double to, double x)
{
	return (x * (to - from) + from);
}

double	ft_lerp_wsteps_d(double from, double to, double steps, double x)
{
	double	step;

	step = (to - from) / (steps - 1);
	return (from + (step * x));
}

t_trgb	trgb_color_lerp_wsteps(t_trgb from, t_trgb to, double steps, double x)
{
	t_trgb	result;


	x = ft_clamp_d(x, 0.0, 255.999);
	result.transparency = ft_lerp_wsteps_d(from.transparency, to.transparency,
			steps, x);
	result.red = ft_lerp_wsteps_d(from.red, to.red, steps, x);
	result.green = ft_lerp_wsteps_d(from.green, to.green, steps, x);
	result.blue = ft_lerp_wsteps_d(from.blue, to.blue, steps, x);
	return (result);
}

int	int_color_lerp_wsteps(int start, int end, double steps, double x)
{
	t_trgb	result;

	result = trgb_color_lerp_wsteps(
		int_to_trgb(start),
		int_to_trgb(end),
		steps,
		x);
	return (trgb_to_int(result));
}

t_trgb	trgb_color_lerp(t_trgb from, t_trgb to, double x)
{
	t_trgb	result;

	x = ft_clamp_d(x, 0.0, 255.999);
	result.transparency = ft_lerp_d(from.transparency, to.transparency, x);
	result.red = ft_lerp_d(from.red, to.red, x);
	result.green = ft_lerp_d(from.green, to.green, x);
	result.blue = ft_lerp_d(from.blue, to.blue, x);
	return (result);
}

int	int_color_lerp(int start, int end, double x)
{
	t_trgb	result;

	result = trgb_color_lerp(int_to_trgb(start), int_to_trgb(end), x);
	return (trgb_to_int(result));
}

int	resolve_color(double iterations, double max_iterations)
{
	double	normalized_iterations;
	int		intensity;
	// double	intensity;
	int		start;
	int		end;
	int		color;

	normalized_iterations = ft_map_d(
		(t_map_d){iterations, 0, max_iterations, 0, 1});
	intensity = ft_map_d(
		(t_map_d){sqrt(normalized_iterations), 0, 1, 0, 255.999});
	// start = 0x00f9cb9c;
	// end = 0x0000ff7f;
	start = 0x00000000;
	end = 0x00FFFFFF;
	// start = 0x00FFFFFF;
	// end = 0x00000000;
	color = int_color_lerp(start, end, intensity);
	// color = int_color_lerp_wsteps(start, end, 10, intensity);
	// color = zero_transparency(color);
	return (color);
}

void	render_mandelbrot(t_fractol *ctl)
{
	int				x;
	int				y;
	int				color;
	double			x_cartesian;
	double			y_cartesian;
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

	ctl.width = 1000;
	ctl.height = 1000;
	ctl.mbt.max_iterations = 100;
	ctl.mbt.infinity = 30;
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
