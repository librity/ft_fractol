/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:57:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 14:43:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static bool	out_of_bounds(t_img_buffer *buffer, int x, int y)
{
	if (x < 0)
		return (true);
	if (x > buffer->width)
		return (true);
	if (y < 0)
		return (true);
	if (y > buffer->height)
		return (true);
	return (false);
}

static int	get_index(t_img_buffer *buffer, int x, int y)
{
	return (y * buffer->line_length + x * buffer->bits_per_pixel / 8);
}

void	draw_to_buffer(t_img_buffer *buffer, int x, int y, int color)
{
	int	*pixel_color;

	if (out_of_bounds(buffer, x, y))
		return ;
	pixel_color = (int *)&buffer->data[get_index(buffer, x, y)];
	*pixel_color = color;
}

int	get_buffer_pixel(t_img_buffer *buffer, int x, int y)
{
	int	*pixel_color;

	if (out_of_bounds(buffer, x, y))
		return (BLACK);
	pixel_color = (int *)&buffer->data[get_index(buffer, x, y)];
	return (*pixel_color);
}
