/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:39:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/09 01:22:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang -I ../includes fire_projectiles.c -lm -lbsd -lmlx -lXext -lX11 && ./a.out
// gcc -I ../includes fire_projectiles.c -lm -lbsd -lmlx -lXext -lX11 && ./a.out

#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include <mlx.h>
#include <mlx_int.h>

#include <fractol.h>

#define ESC_KEY 0xFF1B
#define Q_KEY 0x71

void *mlx;

void *window;
const int width = 1400;
const int height = 1000;

const int max_iterations = 50;
const double infinity = 4;

const double zoom = 500;
const double half_width = width / 2;
const double half_height = height / 2;
const double x_offset = 0;
const double y_offset = 0;

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void die(void)
{
	printf(" ERROR!\n");
	exit(1);
}

map(double n, double start1, double stop1, double start2, double stop2)
{
	double mapped;

	mapped = (n - start1) / (stop1 - start1) * (stop2 - start2) + start2;
	return mapped;
};

void render_mandlebrot(void)
{
	int x;
	int y;
	int color;
	double x_cartesian;
	double y_cartesian;
	double normalizedIterations;
	double brightness;
	t_complex complexAtXY;
	t_mdlbt mdlbtAtXY;

	x = width;
	while (x--)
	{
		y = height;
		while (y--)
		{
			x_cartesian = (x - half_width + x_offset) / zoom;
			y_cartesian = (y - half_height + y_offset) / zoom;

			complexAtXY = complex(x_cartesian, y_cartesian);
			mdlbtAtXY = quick_mandlebrot(complexAtXY, max_iterations, infinity);

			normalizedIterations = map(mdlbtAtXY.iterations, 0, max_iterations, 0, 1);
			brightness = map(sqrt(normalizedIterations), 0, 1, 0, 255);

			color = create_trgb(0, brightness, brightness, brightness);
			mlx_pixel_put(mlx, window, x, y, color);
		}
	}
}

void initialize(void)
{
	printf("=== MinilibX Test Program: Mandlebrot ===\n");

	printf(" => Initializing minilibx...");
	mlx = mlx_init();
	if (mlx == NULL)
		die();
	printf(" OK (use_xshm: %d, pshm_format: %d)\n", ((t_xvar *)mlx)->use_xshm, ((t_xvar *)mlx)->pshm_format);

	printf(" => Creating window %dx%d ...", width, height);
	window = mlx_new_window(mlx, width, height, "Mandlebrot");
	if (window == NULL)
		die();
	printf(" OK\n");

	printf(" => Rendering Mandlebrot set...");
	render_mandlebrot();
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
	mlx_hook(window, KeyPress, KeyPressMask, handle_keypress, mlx);
	mlx_loop(mlx);
}

int main(void)
{
	initialize();
	await_orders();
	return (0);
}
