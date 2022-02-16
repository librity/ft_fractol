/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:17:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 13:52:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(void)
{
	t_fractol		ctl;
	t_img_buffer	buffer;

	ctl.buffer = &buffer;
	log_endl(WELCOME_MSG);
	initialize(&ctl);
	mlx_loop(ctl.mlx);
	return (0);
}
