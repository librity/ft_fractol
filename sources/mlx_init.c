/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:28:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 20:48:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	initialize_mlx_core(t_fractol *ctl)
{
	log_msg(MLX_MSG);
	ctl->mlx = mlx_init();
	die_if_null(ctl->mlx);
	log_endl(SUCCESS_MSG);
}

static void	initialize_mlx_window(t_fractol *ctl)
{
	log_msg(WINDOW_MSG);
	ctl->window = mlx_new_window(ctl->mlx,
			ctl->width,
			ctl->height,
			WINDOW_NAME);
	die_if_null(ctl->window);
	log_endl(SUCCESS_MSG);
}

static void	initialize_mlx_buffer(t_fractol *ctl)
{
	log_msg(BUFFER_MSG);
	ctl->buffer->img = mlx_new_image(ctl->mlx, ctl->width, ctl->height);
	die_if_null(ctl->buffer->img);
	ctl->buffer->data = mlx_get_data_addr(ctl->buffer->img,
			&ctl->buffer->bits_per_pixel,
			&ctl->buffer->line_length,
			&ctl->buffer->endian);
	die_if_null(ctl->buffer->data);
	ctl->buffer->width = ctl->width;
	ctl->buffer->height = ctl->height;
	ctl->buffer->half_width = ctl->width / 2.0;
	ctl->buffer->half_height = ctl->height / 2.0;
	log_endl(SUCCESS_MSG);
}

static void	initialize_mlx_hooks(t_fractol *ctl)
{
	log_msg(HOOKS_MSG);
	mlx_hook(ctl->window, DestroyNotify, ButtonPressMask, handle_destroy, ctl);
	mlx_hook(ctl->window, KeyPress, KeyPressMask, handle_keypress, ctl);
	mlx_mouse_hook(ctl->window, handle_mouse, ctl);
	log_endl(SUCCESS_MSG);
}

void	initialize_mlx(t_fractol *ctl)
{
	initialize_mlx_core(ctl);
	initialize_mlx_window(ctl);
	initialize_mlx_buffer(ctl);
	initialize_mlx_hooks(ctl);
	render_fractal(ctl);
}
