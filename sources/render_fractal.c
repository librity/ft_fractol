/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 17:34:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	render_fractal(t_fractol *ctl)
{
	if (ctl->fractal_code == MANDELBROT_CODE)
		return (render_mandelbrot(ctl));
	if (ctl->fractal_code == JULIA_CODE)
		return (render_julia(ctl));
	if (ctl->fractal_code == NEWTON_CODE)
		return (render_newton(ctl));
	return (render_red(ctl));
}
