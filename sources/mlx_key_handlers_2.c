/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_handlers_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 16:53:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	handle_save_to_bitmap(int keycode, t_fractol *ctl)
{
	if (keycode == S_KEY)
		save_to_bitmap(ctl);
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
