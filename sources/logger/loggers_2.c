/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 02:13:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	log_infinity(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Infinity: %Lf\n", ctl->infinity);
}

void	log_colors(t_fractol *ctl)
{
	if (VERBOSE)
	{
		ft_printf(" => Color dye: %p\n", ctl->dye);
		ft_printf(" => LERP from: %p\n", ctl->lerp_from);
		ft_printf(" => LERP to: %p\n", ctl->lerp_to);
	}
}

void	log_color_code(t_fractol *ctl)
{
	if (VERBOSE)
	{
		if (ctl->color_code == ESCAPE_TIME_CODE)
			ft_printf(" => Color mode: %i, %s\n", ctl->color_code,
				ESCAPE_TIME_MODE);
		if (ctl->color_code == LERP_CODE)
			ft_printf(" => Color mode: %i, %s\n", ctl->color_code, LERP_MODE);
		if (ctl->color_code == BERNSTEIN_CODE)
			ft_printf(" => Color mode: %i, %s\n", ctl->color_code,
				BERNSTEIN_MODE);
	}
}
