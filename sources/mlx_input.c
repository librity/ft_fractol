/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 23:04:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	handle_keypress(int keycode, t_fractol *ctl)
{
	ft_printf(" => key pressed: %i\n", keycode);
	if (keycode == ESC_KEY)
		clean_and_exit(ctl);
	if (keycode == Q_KEY)
		clean_and_exit(ctl);
	return (0);
}

int	handle_destroy(t_fractol *ctl)
{
	clean_and_exit(ctl);
	return (0);
}

void	clean_and_exit(t_fractol *ctl)
{
	mlx_destroy_image(ctl->mlx, ctl->buffer.img);
	mlx_destroy_window(ctl->mlx, ctl->window);
	mlx_destroy_display(ctl->mlx);
	free(ctl->mlx);
	ft_putendl("=== That's all folks! ===");
	exit(0);
}
