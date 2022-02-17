/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log 2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:25:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 16:02:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	log_color_code(t_fractol *ctl)
{
	if (VERBOSE)
		ft_printf(" => Color code: %i\n", ctl->color_code);
}
