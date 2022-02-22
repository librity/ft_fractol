/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_and_no_leaks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:39:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:25:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_mlx_img
{
	int width;
	int height;
	char *data;
	int size_l;
	int bpp;
	int endian;
	void *ptr;
} t_mlx_img;

void *mlx;

void *mlx_window;
const int width = 500;
const int height = 500;

t_mlx_img mlx_img;

const int max_iterations = 50;
const double infinity = 4;

const double zoom = 200;
const double half_width = width / 2;
const double half_height = height / 2;
const double x_offset = -100;
const double y_offset = 0;

const double blueWeight = 0.7;
const double redWeight = 0.5;
const double greenWeight = 0.2;

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

double clamp_d(double n, double low, double high)
{
	return ft_max_d(ft_max_d(n, high), low);
};

double map_d_constrained(double n, double start1, double stop1, double start2, double stop2)
{
	double mapped;

	mapped = map_d(n, start1, stop1, start2, stop2);

	if (start2 < stop2)
		return clamp_d(mapped, start2, stop2);
	return clamp_d(mapped, stop2, start2);
};

bool out_of_bounds(t_mlx_img img, int x, int y)
{
	if (x < 0)
		return (true);
	if (x > img.width)
		return (true);
	if (y < 0)
		return (true);
	if (y > img.height)
		return (true);
	return (false);
}

void draw_to_img(t_mlx_img img, int x, int y, int color)
{
	int index;
	int *pxl_color;

	if (out_of_bounds(img, x, y))
		return;
	index = y * img.size_l + x * img.bpp / 8;
	pxl_color = (int *)&img.data[index];
	*pxl_color = color;
}

int resolve_color(double iterations)
{
	double normalized_iterations = map_d(iterations, 0, max_iterations, 0, 1);
	double brightness = map_d(sqrt(normalized_iterations), 0, 1, 0, 255 * 3);

	int blue = brightness * blueWeight;
	brightness -= 255;
	int red = brightness * redWeight;
	brightness -= 255;
	int green = brightness * greenWeight;

	int color = create_trgb(0, red, green, blue);
	return (color);
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

	x = width;
	while (x--)
	{
		y = height;
		while (y--)
		{
			x_cartesian = (x - half_width + x_offset) / zoom;
			y_cartesian = (y - half_height + y_offset) / zoom;

			complex_at_xy = cx_new(x_cartesian, y_cartesian);
			mdlbt_at_xy = quick_mandelbrot(complex_at_xy, max_iterations, infinity);

			color = resolve_color(mdlbt_at_xy.iterations);
			draw_to_img(mlx_img, x, y, color);
		}
	}

	mlx_put_image_to_window(mlx, mlx_window, mlx_img.ptr, 0, 0);
}

void initialize_mlx(void)
{
	printf(" => Initializing minilibx...");

	mlx = mlx_init();
	if (mlx == NULL)
		die();

	printf(" OK\n");
}

void initialize_mlx_window(void)
{
	printf(" => Creating window %dx%d ...", width, height);

	mlx_window = mlx_new_window(mlx, width, height, "Mandelbrot");
	if (mlx_window == NULL)
		die();

	printf(" OK\n");
}

void initialize_mlx_img(void)
{
	printf(" => Initializing global image...");

	mlx_img.ptr = mlx_new_image(mlx, width, height);
	if (!(mlx_img.ptr))
		die();
	mlx_img.data = mlx_get_data_addr(mlx_img.ptr, &mlx_img.bpp, &mlx_img.size_l, &mlx_img.endian);
	if (!(mlx_img.data))
		die();
	mlx_img.width = width;
	mlx_img.height = height;

	printf(" OK\n");
}

void handle_keypress(int keycode)
{
	printf("keycode: %i", keycode);
	if (keycode == ESC_KEY)
		return clean_and_exit();
	if (keycode == Q_KEY)
		return clean_and_exit();
}

void initialize_mlx_hooks(void)
{
	printf(" => Adding hooks...");

	mlx_hook(mlx_window, KeyPress, KeyPressMask, handle_keypress, mlx);

	printf(" OK\n");
}

void initialize(void)
{
	initialize_mlx();
	initialize_mlx_window();
	initialize_mlx_img();
	initialize_mlx_hooks();
}

void clean_and_exit(void)
{
	mlx_destroy_image(mlx, mlx_img.ptr);
	mlx_destroy_window(mlx, mlx_window);
	mlx_destroy_display(mlx);

	free(mlx);

	exit(0);
}

int main(void)
{
	printf("=== MinilibX Test Program: Mandelbrot ===\n");
	initialize();

	printf(" => Rendering Mandelbrot set...");
	render_mandelbrot();
	printf(" OK\n");

	mlx_loop(mlx);
	return (0);
}
