/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:57:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 16:44:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
