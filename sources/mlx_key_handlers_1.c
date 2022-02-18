/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_handlers_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 22:54:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	handle_close(int keycode, t_fractol *ctl)
{
	if (keycode == ESC_KEY)
		clean_and_exit(ctl);
	if (keycode == Q_KEY)
		clean_and_exit(ctl);
}

void	handle_zoom(int keycode, t_fractol *ctl)
{
	if (keycode == EQUALS_KEY)
		zoom_in(ctl);
	if (keycode == MINUS_KEY)
		zoom_out(ctl);
}

void	handle_navigation(int keycode, t_fractol *ctl)
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

void	handle_max_iterations(int keycode, t_fractol *ctl)
{
	if (keycode == I_KEY)
		increase_max_iterations(ctl);
	if (keycode == K_KEY)
		decrease_max_iterations(ctl);
}

void	handle_infinity(int keycode, t_fractol *ctl)
{
	if (keycode == T_KEY)
		increase_infinity(ctl);
	if (keycode == G_KEY)
		decrease_infinity(ctl);
}
