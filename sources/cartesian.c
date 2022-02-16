/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 23:36:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double	screen_to_cartesian_x(t_fractol *ctl, int x)
{
	double	cartesian;

	cartesian = x - (ctl->buffer.half_width) + ctl->x_offset;
	cartesian /= ctl->zoom;
	return (cartesian);
}

double	screen_to_cartesian_y(t_fractol *ctl, int y)
{
	double	cartesian;

	cartesian = y - (ctl->buffer.half_height) + ctl->y_offset;
	cartesian /= ctl->zoom;
	return (cartesian);
}
