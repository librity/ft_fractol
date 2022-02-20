/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 20:45:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	clean_and_exit(t_fractol *ctl)
{
	mlx_destroy_image(ctl->mlx, ctl->buffer->img);
	mlx_destroy_window(ctl->mlx, ctl->window);
	mlx_destroy_display(ctl->mlx);
	free(ctl->mlx);
	ft_putendl(EXIT_MSG);
	exit(0);
}

void	help_and_die(void)
{
	ft_putstr(HELP_MSG);
	exit(1);
}

void	die(void)
{
	perror("ERROR!\n");
	exit(1);
}

void	die_if_null(void *ptr)
{
	if (ptr == NULL)
		die();
}
