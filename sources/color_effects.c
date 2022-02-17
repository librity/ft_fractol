/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_effects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 16:28:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	escape_time_color(t_fractol *ctl, double iterations)
{
	return (iterations * ctl->dye / ctl->max_iterations);
}

int	lerp_color(t_fractol *ctl, double iterations)
{
	double	normalized_iterations;
	double	intensity;
	int		color;

	normalized_iterations = ft_map_d((t_map_d){iterations, 0,
			ctl->max_iterations, 0, 1});
	intensity = ft_map_d((t_map_d){sqrt(normalized_iterations), 0, 1, 0,
			255.999});
	color = int_color_lerp_wsteps(ctl->lerp_from, ctl->lerp_to, ctl->lerp_steps,
			intensity);
	return (color);
}

int	bernstein_color(double iterations)
{
	double	red;
	double	green;
	double	blue;

	red = 9 * (1 - iterations) * pow(iterations, 3) * 255;
	green = 15 * pow((1 - iterations), 2) * pow(iterations, 2) * 255;
	blue = 8.5 * pow((1 - iterations), 3) * iterations * 255;
	return (rgb_chars_to_int(red, green, blue));
}
