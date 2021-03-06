/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 21:07:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int argc, char **argv)
{
	t_fractol	ctl;
	t_mlx_image	buffer;

	initialize_params(&ctl, &buffer);
	handle_arguments(&ctl, argc, argv);
	ft_putendl(WELCOME_MSG);
	initialize_mlx(&ctl);
	mlx_loop(ctl.mlx);
	return (EXIT_SUCCESS);
}
