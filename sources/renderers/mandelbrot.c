/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 14:53:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

typedef struct s_render_args
{
	t_fractol	*ctl;
	int			x;
	int			y;
}				t_render_args;

static void	*render_pixel(void *args)
{
	int				color;
	long double		x_cartesian;
	long double		y_cartesian;
	t_fractal		mbt_at_xy;
	t_render_args	*a;

	a = args;
	x_cartesian = screen_to_cartesian_x(a->ctl, a->x);
	y_cartesian = screen_to_cartesian_y(a->ctl, a->y);
	mbt_at_xy = a->ctl->calculate_mbt(
			cx_new(x_cartesian, y_cartesian),
			a->ctl->max_iterations,
			a->ctl->infinity);
	color = a->ctl->render_color(a->ctl, mbt_at_xy.iterations);
	bm_draw_to_mlx_image(a->ctl->buffer, a->x, a->y, color);
	return (NULL);
}

static void	render_and_show(t_fractol *ctl)
{
	int				x;
	int				y;
	int				rc;
	pthread_t		thread_id[ctl->width + 10][ctl->height + 10];
	t_render_args	a[ctl->width + 10][ctl->height + 10];

	x = ctl->width;
	while (x > 0)
	{
		y = ctl->height;
		while (y > 0)
		{
			a[x][y] = (t_render_args){ctl, x, y};
			rc = pthread_create(&(thread_id[x][y]), NULL, render_pixel, (void *)&(a[x][y]));
			rc = rc;
			// if (rc) {
         	// 	ft_printf("Error:unable to create thread, %d\n", rc);
         	// 	exit(-1);
      		// }
			y--;
		}
		x--;
	}
	x = ctl->width;
	while (x > 0)
	{
		y = ctl->height;
		while (y > 0)
		{
			pthread_join(thread_id[x][y], NULL);
			y--;
		}
		x--;
	}
	// pthread_exit(NULL);
	mlx_put_image_to_window(ctl->mlx, ctl->window, ctl->buffer->img, 0, 0);
}

void	render_mandelbrot(t_fractol *ctl)
{
	log_msg(MBT_MSG);
	render_and_show(ctl);
	log_endl(SUCCESS_MSG);
}
