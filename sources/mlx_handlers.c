/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 16:16:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	handle_destroy(t_fractol *ctl)
{
	clean_and_exit(ctl);
	return (0);
}

int	handle_keypress(int keycode, t_fractol *ctl)
{
	log_keycode(keycode);
	handle_close(keycode, ctl);
	handle_zoom(keycode, ctl);
	handle_navigation(keycode, ctl);
	handle_color_shift(keycode, ctl);
	handle_save_to_bitmap(keycode, ctl);
	handle_color_mode(keycode, ctl);
	return (0);
}
