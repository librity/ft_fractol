/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 16:31:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	log_keycode(int keycode)
{
	if (VERBOSE)
		ft_printf(" => Key pressed: %i\n", keycode);
}

void	log_zoom(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Zoom: %i\n", (int)ctl->zoom);
}

void	log_position(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => X: %i, Y: %i\n", (int)ctl->x_offset, (int)ctl->y_offset);
}

void	log_colors(t_fractol *ctl)
{
	if (VERBOSE)
	{
		ft_printf(" => Color dye: %p\n", ctl->dye);
		ft_printf(" => LERP from: %p\n", ctl->lerp_from);
		ft_printf(" => LERP to: %p\n", ctl->lerp_to);
	}
}

void	log_color_code(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Color code: %i\n", ctl->color_code);
}
