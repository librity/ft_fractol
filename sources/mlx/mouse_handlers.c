/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:42:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	handle_mouse_zoom(int mousecode, int x, int y, t_fractol *ctl)
{
	if (mousecode == MOUSE_WHEEL_UP)
		mouse_zoom_in(ctl, x, y);
	if (mousecode == MOUSE_WHEEL_DOWN)
		mouse_zoom_out(ctl, x, y);
}

void	handle_warping(int mousecode, int x, int y, t_fractol *ctl)
{
	if (mousecode == MOUSE_LEFT_CLICK)
		warp(ctl, x, y);
}
