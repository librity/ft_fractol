/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 09:12:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	get_t(int color)
{
	return (color & T_MASK);
}

int	get_r(int color)
{
	return (color & R_MASK);
}

int	get_g(int color)
{
	return (color & G_MASK);
}

int	get_b(int color)
{
	return (color & B_MASK);
}

int	zero_transparency(int color)
{
	int	transparency;

	transparency = color >> 24 << 24;
	color = color - transparency;
	return (color);
}
