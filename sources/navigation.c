/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:14:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 00:49:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	log_and_render(t_fractol *ctl)
{
	log_position(ctl);
	render_fractal(ctl);
}

void	move_up(t_fractol *ctl)
{
	ctl->y_offset -= NAVIGATION_STEP;
	log_and_render(ctl);
}

void	move_down(t_fractol *ctl)
{
	ctl->y_offset += NAVIGATION_STEP;
	log_and_render(ctl);
}

void	move_left(t_fractol *ctl)
{
	ctl->x_offset -= NAVIGATION_STEP;
	log_and_render(ctl);
}

void	move_right(t_fractol *ctl)
{
	ctl->x_offset += NAVIGATION_STEP;
	log_and_render(ctl);
}
