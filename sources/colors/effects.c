/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_effects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/21 16:35:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	escape_time_color(t_fractol *ctl, int iterations)
{
	return (iterations * ctl->dye / ctl->max_iterations);
}

int	lerp_color(t_fractol *ctl, int iterations)
{
	long double	normalized_iterations;
	long double	intensity;
	int			color;

	normalized_iterations = (long double)iterations;
	normalized_iterations /= (long double)ctl->max_iterations;
	intensity = sqrtl(normalized_iterations) * 255.999;
	color = int_color_lerp_wsteps(ctl->lerp_from, ctl->lerp_to, ctl->lerp_steps,
			intensity);
	return (color);
}

int	bernstein_color(t_fractol *ctl, int iterations)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	long double		ni;

	ni = (long double)iterations / (long double)ctl->max_iterations;
	red = 9.0 * (1.0 - ni) * pow(ni, 3.0) * 255.0;
	green = 15.0 * pow((1.0 - ni), 2.0) * pow(ni, 2.0) * 255.0;
	blue = 8.5 * pow((1.0 - ni), 3.0) * ni * 255.0;
	return (bm_rgb_chars_to_int(red, green, blue));
}
