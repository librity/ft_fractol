/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 02:05:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	handle_arguments(t_fractol *ctl, int argc, char **argv)
{
	char	*fractal;

	fractal = argv[1];
	if (argc == 2
		&& ft_strncmp(fractal, "mandelbrot", ft_strsize("mandelbrot")) == 0)
	{
		ctl->fractal_code = MANDELBROT_CODE;
		return ;
	}
	if (argc == 4 && ft_strncmp(fractal, "julia", ft_strsize("julia")) == 0)
	{
		ctl->fractal_code = JULIA_CODE;
		ctl->julia_factor = complex(ft_atold(argv[2]), ft_atold(argv[3]));
		return ;
	}
	help_and_die();
}

int	main(int argc, char **argv)
{
	t_fractol	ctl;
	t_mlx_image	buffer;

	initialize_params(&ctl, &buffer);
	handle_arguments(&ctl, argc, argv);
	log_endl(WELCOME_MSG);
	initialize_mlx(&ctl);
	mlx_loop(ctl.mlx);
	return (0);
}
