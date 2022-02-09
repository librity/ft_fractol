/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_projectiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:39:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/08 20:51:17 by lpaulo-m         ###   ########.fr       */
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

#define ESC_KEY 0xFF1B
#define SPACE_KEY 0x20
#define B_KEY 0x62
#define C_KEY 0x63
#define F_KEY 0x66
#define Q_KEY 0x71
#define R_KEY 0x72

typedef struct s_vector_3d
{
	double x;
	double y;
	double z;
} t_vector_3d;

typedef t_vector_3d t_point_3d;

t_vector_3d add(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.x + second.x;
	result.y = first.y + second.y;
	result.z = first.z + second.z;
	return (result);
}

void *mlx;

void *window;
const int height = 1000;
const int width = 1400;

const int speed = 1;

const t_vector_3d gravity = (t_vector_3d){0, 0.002, 0};

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

	printf(" => Clearing window ...");
	mlx_clear_window(mlx, window);
	// clear_window();
	printf(" OK\n");
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

int random_color(void)
{
	return ((int)random_from(INT_MIN, INT_MAX));
}

t_point_3d new_position(t_point_3d position, t_vector_3d velocity)
{
	return (add(position, velocity));
}

t_point_3d new_velocity(t_vector_3d velocity)
{
	return (add(velocity, gravity));
}

bool in_window(t_point_3d position)
{
	if (position.x < 0)
		return (false);
	if (position.x > width)
		return (false);
	if (position.y < 0)
		return (false);
	if (position.y > height)
		return (false);
	return (true);
}

void fire(void)
{
	t_point_3d position = (t_point_3d){0, height, 0};
	// t_vector_3d velocity = (t_vector_3d){1, -1, 0};
	t_vector_3d velocity = (t_vector_3d){random_from(0.5, 1.5), -random_from(0.5, 1.5), 0};
	int color = random_color();

	while (in_window(position))
	{
		draw_circle(position.x, position.y, 5, color);
		usleep(speed);
		position = new_position(position, velocity);
		velocity = new_velocity(velocity);
	}
}

void handle_keypress(int keycode)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == Q_KEY)
		exit(0);
	if (keycode == B_KEY)
	{
		write(1, "Blanking window...\n", 19);
		blank_window();
	}
	if (keycode == C_KEY)
	{
		write(1, "Clearing window...\n", 19);
		mlx_clear_window(mlx, window);
	}
	if (keycode == R_KEY)
	{
		write(1, "New background...\n", 18);
		fill_window(random_color());
	}
	if (keycode == SPACE_KEY)
		fire();
	if (keycode == F_KEY)
		fire();
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
