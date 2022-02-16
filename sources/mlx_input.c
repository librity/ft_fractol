/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 00:28:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	handle_keypress(int keycode, t_fractol *ctl)
{
	log_keycode(keycode);
	if (keycode == ESC_KEY)
		clean_and_exit(ctl);
	if (keycode == Q_KEY)
		clean_and_exit(ctl);
	if (keycode == PLUS_KEY)
		zoom_in(ctl);
	if (keycode == MINUS_KEY)
		zoom_out(ctl);
	if (keycode == UP_KEY)
		move_up(ctl);
	if (keycode == DOWN_KEY)
		move_down(ctl);
	if (keycode == LEFT_KEY)
		move_left(ctl);
	if (keycode == RIGHT_KEY)
		move_right(ctl);
	render_fractal(ctl);
	return (0);
}
