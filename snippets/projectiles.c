/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 03:39:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/13 23:01:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang -I ../includes projectiles.c -lm -lbsd -lmlx -lXext -lX11 && ./a.out
// gcc -I ../includes projectiles.c -lm -lbsd -lmlx -lXext -lX11 && ./a.out

#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include <mlx.h>
#include <mlx_int.h>

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

int main(void)
{
	int shells = 3000;

	initialize();
	while (shells--)
		fire();
	getchar();
	return (0);
}
