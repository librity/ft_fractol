/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/19 15:39:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	handle_arguments(int argc, char **argv)
{
	argv = argv;
	argc = argc;
	if (argc < 2 || argc > 4)
		help_and_die();
}

int	main(int argc, char **argv)
{
	t_fractol	ctl;
	t_mlx_image	buffer;

	handle_arguments(argc, argv);
	ctl.buffer = &buffer;
	log_endl(WELCOME_MSG);
	initialize(&ctl);
	mlx_loop(ctl.mlx);
	return (0);
}
