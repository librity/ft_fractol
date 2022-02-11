/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:39:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/10 21:12:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang -I ../includes fire_projectiles.c -lm -lbsd -lmlx -lXext -lX11 && ./a.out
// gcc -I ../includes fire_projectiles.c -lm -lbsd -lmlx -lXext -lX11 && ./a.out

#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <X11/Xlib.h>

#include <mlx.h>

#include <libft.h>
#include <fractol.h>

#define ESC_KEY 0xFF1B
#define Q_KEY 0x71

void *mlx;

void *window;
const int width = 500;
const int height = 500;

const int max_iterations = 50;
const double infinity = 4;

const double zoom = 200;
const double half_width = width / 2;
const double half_height = height / 2;
const double x_offset = -100;
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

double map_d(double n, double start1, double stop1, double start2, double stop2)
{
	double mapped;

	mapped = (n - start1) / (stop1 - start1) * (stop2 - start2) + start2;
	return mapped;
};

double constrain_d(double n, double low, double high)
{
	return ft_max_d(ft_max_d(n, high), low);
};

double map_d_constrained(double n, double start1, double stop1, double start2, double stop2)
{
	double mapped;

	mapped = map_d(n, start1, stop1, start2, stop2);

	if (start2 < stop2)
		return constrain_d(mapped, start2, stop2);
	return constrain_d(mapped, stop2, start2);
};

void render_mandelbrot(void)
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
			mdlbtAtXY = quick_mandelbrot(complexAtXY, max_iterations, infinity);

			normalizedIterations = map_d(mdlbtAtXY.iterations, 0, max_iterations, 0, 1);
			brightness = map_d(sqrt(normalizedIterations), 0, 1, INT_MIN, INT_MAX);

			mlx_pixel_put(mlx, window, x, y, (int)brightness);
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
	window = mlx_new_window(mlx, width, height, "Mandelbrot");
	if (window == NULL)
		die();
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

int main(void)
{
	initialize();
	mlx_hook(window, KeyPress, KeyPressMask, handle_keypress, mlx);

	printf(" => Rendering Mandelbrot set...");
	render_mandelbrot();
	printf(" OK\n");

	mlx_loop(mlx);
	return (0);
}
