/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_effects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/18 17:18:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	escape_time_color(t_fractol *ctl, int iterations)
{
	return (iterations * ctl->dye / ctl->max_iterations);
}

int	lerp_color(t_fractol *ctl, int iterations)
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

int	bernstein_color(t_fractol *ctl, int iterations)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	double			ni;

	ni = ft_map_d((t_map_d){iterations, 0, ctl->max_iterations, 0, 1});
	red = 9.0 * (1.0 - ni) * pow(ni, 3.0) * 255.0;
	green = 15.0 * pow((1.0 - ni), 2.0) * pow(ni, 2.0) * 255.0;
	blue = 8.5 * pow((1.0 - ni), 3.0) * ni * 255.0;
	return (0x00000000 | red << 16 | green << 8 | blue);
}
