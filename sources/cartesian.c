/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 02:08:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

long double	screen_to_cartesian_x(t_fractol *ctl, int x)
{
	long double	cartesian;

	cartesian = x - ctl->buffer->half_width;
	cartesian /= ctl->zoom;
	cartesian += ctl->x_offset;
	return (cartesian);
}

long double	screen_to_cartesian_y(t_fractol *ctl, int y)
{
	long double	cartesian;

	cartesian = y - ctl->buffer->half_height;
	cartesian /= ctl->zoom;
	cartesian += ctl->y_offset;
	return (cartesian);
}
