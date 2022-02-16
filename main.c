/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:17:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 23:02:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	initialize_params(t_fractol *ctl)
{
	ctl->width = 500;
	ctl->height = 500;
	ctl->mbt.max_iterations = 100;
	ctl->mbt.infinity = 30;
	ctl->mbt.zoom = 200;
	ctl->mbt.x_offset = -100;
	ctl->mbt.y_offset = 0;
	ctl->mbt.lerp_steps = 256;
	// ctl->mbt.lerp_from = 0x00f9cb9c;
	// ctl->mbt.lerp_to = 0x0000ff7f;
	ctl->mbt.lerp_from = 0x00000000;
	ctl->mbt.lerp_to = 0x00FFFFFF;
}

void	initialize(t_fractol *ctl)
{
	initialize_params(ctl);
	initialize_mlx(ctl);
	initialize_mlx_window(ctl);
	initialize_mlx_buffer(ctl);
	initialize_mlx_hooks(ctl);
	render_mandelbrot(ctl);
}

int	main(void)
{
	t_fractol	ctl;

	ft_putendl("=== lpaulo-m presents: fract-ol ===");
	initialize(&ctl);
	mlx_loop(ctl.mlx);
	return (0);
}
