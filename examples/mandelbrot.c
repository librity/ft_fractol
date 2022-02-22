/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:39:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:20:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <X11/Xlib.h>

#include <mlx.h>

#include <fractol.h>

#define ESC_KEY 0xFF1B
#define Q_KEY 0x71

void *mlx;

void *mlx_window;
const int width = 500;
const int height = 500;

const int max_iterations = 50;
const double infinity = 4;

const double zoom = 200;
const double half_width = width / 2;
const double half_height = height / 2;
const double x_offset = -100;
const double y_offset = 0;

const int white = 0x00FFFFFF;
const int black = 0x00000000;

void die(void)
{
	printf(" ERROR!\n");
	exit(1);
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int resolve_color(bool is_mandelbrot)
{
	if (is_mandelbrot)
		return (black);
	return (white);
}

void render_mandelbrot(void)
{
	int x;
	int y;
	int color;
	double x_cartesian;
	double y_cartesian;
	double normalized_iterations;
	double brightness;
	t_complex complex_at_xy;
	t_fractal mdlbt_at_xy;
	bool is_mandelbrot;

	x = width;
	while (x--)
	{
		y = height;
		while (y--)
		{
			x_cartesian = (x - half_width + x_offset) / zoom;
			y_cartesian = (y - half_height + y_offset) / zoom;

			complex_at_xy = cplx_build(x_cartesian, y_cartesian);
			mdlbt_at_xy = quick_mandelbrot(complex_at_xy, max_iterations, infinity);
			is_mandelbrot = !mdlbt_at_xy.diverges;
			color = resolve_color(is_mandelbrot);

			mlx_pixel_put(mlx, mlx_window, x, y, color);
		}
	}
}

void initialize(void)
{
	printf("=== MinilibX Test Program: Mandelbrot ===\n");

	printf(" => Initializing minilibx...");
	mlx = mlx_init();
	if (mlx == NULL)
		die();
	printf(" OK\n");

	printf(" => Creating window %dx%d ...", width, height);
	mlx_window = mlx_new_window(mlx, width, height, "Mandelbrot");
	if (mlx_window == NULL)
		die();
	printf(" OK\n");

	printf(" => Rendering Mandelbrot set...");
	render_mandelbrot();
	printf(" OK\n");
}

void handle_keypress(int keycode)
{
	printf("keycode: %i", keycode);
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == Q_KEY)
		exit(0);
}

void await_orders(void)
{
	mlx_hook(mlx_window, KeyPress, KeyPressMask, handle_keypress, mlx);
	mlx_loop(mlx);
}

int main(void)
{
	initialize();
	await_orders();
	return (0);
}
