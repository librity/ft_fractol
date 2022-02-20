/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_newton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 17:45:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	render_pixel(t_fractol *ctl, int x, int y)
{
	int			color;
	long double	x_cartesian;
	long double	y_cartesian;

	x_cartesian = screen_to_cartesian_x(ctl, x);
	y_cartesian = screen_to_cartesian_y(ctl, y);
	color = newton_z3m1(complex(x_cartesian, y_cartesian), ctl->max_iterations);
	bm_draw_to_mlx_image(ctl->buffer, x, y, color);
}

static void	render_and_show(t_fractol *ctl)
{
	int	x;
	int	y;

	x = ctl->width;
	while (x--)
	{
		y = ctl->height;
		while (y--)
		{
			render_pixel(ctl, x, y);
		}
	}
	mlx_put_image_to_window(ctl->mlx, ctl->window, ctl->buffer->img, 0, 0);
}

void	render_newton(t_fractol *ctl)
{
	log_msg(NEWTON_MSG);
	render_and_show(ctl);
	log_endl(SUCCESS_MSG);
}
