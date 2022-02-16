/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 13:51:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	log_msg(char *message)
{
	if (VERBOSE)
		ft_putstr(message);
}

void	log_endl(char *message)
{
	if (VERBOSE)
		ft_putendl(message);
}

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
