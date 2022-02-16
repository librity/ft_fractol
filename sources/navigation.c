/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:14:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 00:29:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	move_up(t_fractol *ctl)
{
	ctl->y_offset -= NAVIGATION_STEP;
	log_position(ctl);
}

void	move_down(t_fractol *ctl)
{
	ctl->y_offset += NAVIGATION_STEP;
	log_position(ctl);
}

void	move_left(t_fractol *ctl)
{
	ctl->x_offset -= NAVIGATION_STEP;
	log_position(ctl);
}

void	move_right(t_fractol *ctl)
{
	ctl->x_offset += NAVIGATION_STEP;
	log_position(ctl);
}
