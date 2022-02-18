/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 22:10:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	log_infinity(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Infinity: %i\n", (int)ctl->infinity);
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
		ft_printf(" => Color code: %i\n", ctl->color_code);
}
