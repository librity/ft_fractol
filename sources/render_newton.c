/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_newton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/21 22:19:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	get_root_color(int index)
{
	const int	root_colors[NEWTON_Z3M1_ROOTS] = {
		NEWTON_ROOT_COLOR_1,
		NEWTON_ROOT_COLOR_2,
		NEWTON_ROOT_COLOR_3};

	return (root_colors[index]);
}

static int	render_root_color(t_newton_z3m1 newton)
{
	if (newton.is_root)
		return (get_root_color(newton.root_index));
	return (NEWTON_NOT_ROOT_COLOR);
}

static void	render_pixel(t_fractol *ctl, int x, int y)
{
	int				color;
	long double		x_cartesian;
	long double		y_cartesian;
	t_newton_z3m1	newton_at_xy;

	x_cartesian = screen_to_cartesian_x(ctl, x);
	y_cartesian = screen_to_cartesian_y(ctl, y);
	newton_at_xy = ctl->calculate_newton(
			complex(x_cartesian, y_cartesian),
			ctl->newton_tolerance,
			ctl->max_iterations);
	if (ctl->use_newton_root_color)
		color = render_root_color(newton_at_xy);
	else
		color = ctl->render_color(ctl, newton_at_xy.iterations);
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
			render_pixel(ctl, x, y);
	}
	mlx_put_image_to_window(ctl->mlx, ctl->window, ctl->buffer->img, 0, 0);
}

void	render_newton(t_fractol *ctl)
{
	log_msg(NEWTON_MSG);
	render_and_show(ctl);
	log_endl(SUCCESS_MSG);
}
