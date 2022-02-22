/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:41:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	clean(t_fractol *ctl)
{
	mlx_destroy_image(ctl->mlx, ctl->buffer->img);
	mlx_destroy_window(ctl->mlx, ctl->window);
	mlx_destroy_display(ctl->mlx);
	free(ctl->mlx);
	ft_putendl(EXIT_MSG);
}

void	clean_and_exit(t_fractol *ctl)
{
	clean(ctl);
	exit(EXIT_SUCCESS);
}
