/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_walker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:39:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/08 20:58:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang -I ../includes random_walker.c -lbsd -lm -lmlx -lXext -lX11 && ./a.out
// gcc -I ../includes random_walker.c -lbsd -lm -lmlx -lXext -lX11 && ./a.out

#include <stdbool.h>
#include <math.h>
#include <time.h>

#include <mlx.h>
#include <mlx_int.h>

void *mlx;

void *window;
const int height = 1000;
const int width = 1000;

const int step = 5;
const int speed = 10000;

void fill_window(int color)
{
	int x;
	int y;

	x = width;
	while (x--)
	{
		y = height;
		while (y--)
			mlx_pixel_put(mlx, window, x, y, color);
	}
}

void clear_window(void)
{
	fill_window(0x00000000);
}

void blank_window(void)
{
	fill_window(0x00FFFFFF);
}

void die(void)
{
	printf(" ERROR!\n");
	exit(1);
}

void initialize(void)
{
	printf("=== MinilibX Test Program: Random Walker ===\n");

	printf(" => Initializing minilibx...");
	mlx = mlx_init();
	if (mlx == NULL)
		die();
	printf(" OK (use_xshm: %d, pshm_format: %d)\n", ((t_xvar *)mlx)->use_xshm, ((t_xvar *)mlx)->pshm_format);

	printf(" => Creating window %dx%d ...", width, height);
	window = mlx_new_window(mlx, width, height, "Random Walker");
	if (window == NULL)
		die();
	printf(" OK\n");

	// printf(" => Blanking window ...");
	// blank_window();
	// printf(" OK\n");

	printf(" => Clearing window ...");
	mlx_clear_window(mlx, window);
	// clear_window();
	printf(" OK\n");
}

void draw_square(int x, int y, int size, int color)
{
	int half = size / 2;
	int i;
	int j;

	i = -half;
	while (i < half)
	{
		j = -half;
		while (j < half)
		{
			mlx_pixel_put(mlx, window, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void draw_circle(int x, int y, int size, int color)
{
	int half = size / 2;
	int i;
	int j;
	double radius;

	i = -half;
	while (i < half)
	{
		j = -half;
		while (j < half)
		{
			radius = pow(i, 2) + pow(j, 2);
			radius = sqrt(radius);
			if (radius < half)
				mlx_pixel_put(mlx, window, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

double random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double random_from(double min, double max)
{
	return (min + (max - min) * random_double());
}

void walk(void)
{
	double x;
	double y;

	x = width / 2;
	y = height / 2;
	while (true)
	{
		mlx_clear_window(mlx, window);
		draw_circle(x, y, 50, 0x00AAAAAA);
		usleep(speed);
		x = x + random_from(-step, step);
		y = y + random_from(-step, step);
	}
}

int main(void)
{
	initialize();
	walk();
	return (0);
}
