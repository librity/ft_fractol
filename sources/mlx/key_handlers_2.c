/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:42:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	handle_color_shift(int keycode, t_fractol *ctl)
{
	if (keycode == L_KEY)
		shift_colors_up(ctl);
	if (keycode == PERIOD_KEY)
		shift_colors_down(ctl);
}

void	handle_color_mode(int keycode, t_fractol *ctl)
{
	if (keycode == C_KEY)
		switch_color_mode(ctl);
}

void	handle_save_to_bitmap(int keycode, t_fractol *ctl)
{
	if (keycode == S_KEY)
		save_to_bitmap(ctl);
}
