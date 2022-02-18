/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_inspect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 21:03:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	print_color(int color)
{
	ft_printf("%p\n", color);
}

void	inspect_color(int color)
{
	inspect_trgb(bm_int_to_trgb(color));
}

void	inspect_trgb(t_trgb trgb)
{
	ft_printf("t: %i | r: %i | g: %i | b: %i\n",
		trgb.transparency,
		trgb.red,
		trgb.green,
		trgb.blue);
}
