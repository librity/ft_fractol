/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_lerp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 02:09:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_trgb	trgb_color_lerp_wsteps(t_trgb from, t_trgb to, int steps, int x)
{
	t_trgb	result;

	x = ft_clamp_i(x, 0, 256);
	result.transparency = ft_lerp_wsteps_d(from.transparency, to.transparency,
			steps, x);
	result.red = ft_lerp_wsteps_d(from.red, to.red, steps, x);
	result.green = ft_lerp_wsteps_d(from.green, to.green, steps, x);
	result.blue = ft_lerp_wsteps_d(from.blue, to.blue, steps, x);
	return (result);
}

int	int_color_lerp_wsteps(int from, int to, int steps, int x)
{
	int	result;

	x = ft_clamp_i(x, 0, 256);
	result = ft_lerp_wsteps_i(get_t(from), get_t(to), steps, x);
	result += ft_lerp_wsteps_i(get_r(from), get_r(to), steps, x);
	result += ft_lerp_wsteps_i(get_g(from), get_g(to), steps, x);
	result += ft_lerp_wsteps_i(get_b(from), get_b(to), steps, x);
	return (result);
}

t_trgb	trgb_color_lerp(t_trgb from, t_trgb to, int x)
{
	t_trgb	result;

	x = ft_clamp_i(x, 0, 256);
	result.transparency = ft_lerp_d(from.transparency, to.transparency, x);
	result.red = ft_lerp_d(from.red, to.red, x);
	result.green = ft_lerp_d(from.green, to.green, x);
	result.blue = ft_lerp_d(from.blue, to.blue, x);
	return (result);
}

int	int_color_lerp(int from, int to, int x)
{
	int	result;

	x = ft_clamp_i(x, 0, 256);
	result = ft_lerp_i(get_t(from), get_t(to), x);
	result += ft_lerp_i(get_r(from), get_r(to), x);
	result += ft_lerp_i(get_g(from), get_g(to), x);
	result += ft_lerp_i(get_b(from), get_b(to), x);
	return (result);
}
