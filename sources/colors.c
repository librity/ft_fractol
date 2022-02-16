/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 23:37:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	resolve_color(t_fractol *ctl, double iterations)
{
	double	normalized_iterations;
	double	intensity;
	int		color;

	normalized_iterations = ft_map_d((t_map_d){iterations, 0,
			ctl->max_iterations, 0, 1});
	intensity = ft_map_d((t_map_d){sqrt(normalized_iterations), 0, 1, 0,
			255.999});
	color = int_color_lerp_wsteps(ctl->lerp_from, ctl->lerp_to,
			ctl->lerp_steps, intensity);
	return (color);
}
