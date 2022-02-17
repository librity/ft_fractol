/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 13:43:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	handle_close(int keycode, t_fractol *ctl)
{
	if (keycode == ESC_KEY)
		clean_and_exit(ctl);
	if (keycode == Q_KEY)
		clean_and_exit(ctl);
}

static void	handle_zoom(int keycode, t_fractol *ctl)
{
	if (keycode == EQUALS_KEY)
		zoom_in(ctl);
	if (keycode == MINUS_KEY)
		zoom_out(ctl);
}

static void	handle_navigation(int keycode, t_fractol *ctl)
{
	if (keycode == UP_KEY)
		move_up(ctl);
	if (keycode == DOWN_KEY)
		move_down(ctl);
	if (keycode == LEFT_KEY)
		move_left(ctl);
	if (keycode == RIGHT_KEY)
		move_right(ctl);
}

static void	handle_color_shift(int keycode, t_fractol *ctl)
{
	if (keycode == L_KEY)
		shift_colors_up(ctl);
	if (keycode == PERIOD_KEY)
		shift_colors_down(ctl);
}

int	handle_keypress(int keycode, t_fractol *ctl)
{
	handle_close(keycode, ctl);
	handle_zoom(keycode, ctl);
	handle_navigation(keycode, ctl);
	handle_color_shift(keycode, ctl);
	if (keycode == S_KEY)
		save_to_bitmap(ctl);
	log_keycode(keycode);
	return (0);
}
