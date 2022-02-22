/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 11:21:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static bool	is_newton(int argc, char *fractal)
{
	if (argc != 2)
		return (false);
	if (ft_strncmp(fractal, NEWTON_ARG, ft_strsize(NEWTON_ARG)) != 0)
		return (false);
	return (true);
}

static bool	is_julia(int argc, char *fractal)
{
	if (argc != 4)
		return (false);
	if (ft_strncmp(fractal, JULIA_ARG, ft_strsize(JULIA_ARG)) != 0)
		return (false);
	return (true);
}

static bool	is_mandelbrot(int argc, char *fractal)
{
	if (argc != 2)
		return (false);
	if (ft_strncmp(fractal, MANDELBROT_ARG, ft_strsize(MANDELBROT_ARG)) != 0)
		return (false);
	return (true);
}

void	handle_arguments(t_fractol *ctl, int argc, char **argv)
{
	if (is_mandelbrot(argc, argv[1]))
	{
		ctl->fractal_code = MANDELBROT_CODE;
		ctl->render_fractal = render_mandelbrot;
		return ;
	}
	if (is_julia(argc, argv[1]))
	{
		ctl->fractal_code = JULIA_CODE;
		ctl->render_fractal = render_julia;
		ctl->julia_factor = parse_julia_factor(argv);
		return ;
	}
	if (is_newton(argc, argv[1]))
	{
		ctl->fractal_code = NEWTON_CODE;
		ctl->render_fractal = render_newton;
		return ;
	}
	help_and_die();
}
