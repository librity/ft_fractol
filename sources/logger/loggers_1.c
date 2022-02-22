/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 02:13:06 by lpaulo-m         ###   ########.fr       */
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
		ft_printf(" => Zoom: %Lf\n", ctl->zoom);
}

void	log_position(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Fractal position: X=%Lf, Y=%Lf\n", ctl->x_offset,
			ctl->y_offset);
}

void	log_max_iterations(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Max iterations: %i\n", ctl->max_iterations);
}
