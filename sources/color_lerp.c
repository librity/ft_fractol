/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_lerp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 21:49:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_trgb	trgb_color_lerp_wsteps(t_trgb from, t_trgb to, double steps, double x)
{
	t_trgb	result;

	x = ft_clamp_d(x, 0.0, 255.999);
	result.transparency = ft_lerp_wsteps_d(from.transparency, to.transparency,
			steps, x);
	result.red = ft_lerp_wsteps_d(from.red, to.red, steps, x);
	result.green = ft_lerp_wsteps_d(from.green, to.green, steps, x);
	result.blue = ft_lerp_wsteps_d(from.blue, to.blue, steps, x);
	return (result);
}

int	int_color_lerp_wsteps(int start, int end, double steps, double x)
{
	t_trgb	result;

	result = trgb_color_lerp_wsteps(int_to_trgb(start), int_to_trgb(end), steps,
			x);
	return (trgb_to_int(result));
}

t_trgb	trgb_color_lerp(t_trgb from, t_trgb to, double x)
{
	t_trgb	result;

	x = ft_clamp_d(x, 0.0, 255.999);
	result.transparency = ft_lerp_d(from.transparency, to.transparency, x);
	result.red = ft_lerp_d(from.red, to.red, x);
	result.green = ft_lerp_d(from.green, to.green, x);
	result.blue = ft_lerp_d(from.blue, to.blue, x);
	return (result);
}

int	int_color_lerp(int start, int end, double x)
{
	t_trgb	result;

	result = trgb_color_lerp(int_to_trgb(start), int_to_trgb(end), x);
	return (trgb_to_int(result));
}
