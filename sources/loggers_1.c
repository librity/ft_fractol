/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 22:10:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	log_keycode(int keycode)
{
	if (VERBOSE)
		ft_printf(" => Key pressed: %i\n", keycode);
}

void	log_mouse_event(int mousecode, int x, int y)
{
	if (VERBOSE)
		ft_printf(" => Mouse event: code=%i, X=%i, Y=%i\n", mousecode, x, y);
}

void	log_zoom(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Zoom: %i\n", (int)ctl->zoom);
}

void	log_position(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Fractal position: X=%i, Y=%i\n", (int)ctl->x_offset,
			(int)ctl->y_offset);
}

void	log_max_iterations(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Max iterations: %i\n", ctl->max_iterations);
}
