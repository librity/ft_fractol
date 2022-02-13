/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:57:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 13:52:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	trgb_to_int(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

int	rgb_to_int(int red, int green, int blue)
{
	return (trgb_to_int(0, red, green, blue));
}

bool	out_of_bounds(t_img_buffer *buffer, int x, int y)
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

void	draw_to_buffer(t_img_buffer *buffer, int x, int y, int color)
{
	int	index;
	int	*pxl_color;

	if (out_of_bounds(buffer, x, y))
		return ;
	index = y * buffer->line_length + x * buffer->bits_per_pixel / 8;
	pxl_color = (int *)&buffer->data[index];
	*pxl_color = color;
}
