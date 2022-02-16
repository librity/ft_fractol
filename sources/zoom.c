/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:14:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 00:36:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	log_and_render(t_fractol *ctl)
{
	log_zoom(ctl);
	render_fractal(ctl);
}

void	zoom_in(t_fractol *ctl)
{
	ctl->zoom += ZOOM_STEP;
	log_and_render(ctl);
}

void	zoom_out(t_fractol *ctl)
{
	ctl->zoom -= ZOOM_STEP;
	log_and_render(ctl);
}
