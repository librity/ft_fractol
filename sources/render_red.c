/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 17:32:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	render_and_show(t_fractol *ctl)
{
	int	x;
	int	y;

	x = ctl->width;
	while (x--)
	{
		y = ctl->height;
		while (y--)
			bm_draw_to_mlx_image(ctl->buffer, x, y, RED);
	}
	mlx_put_image_to_window(ctl->mlx, ctl->window, ctl->buffer->img, 0, 0);
}

void	render_red(t_fractol *ctl)
{
	log_msg(RED_MSG);
	render_and_show(ctl);
	log_endl(SUCCESS_MSG);
}
