/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mdlbt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 13:37:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_mandelbrotian	mandelbrot(t_complex number, int max_iterations,
		double infinity)
{
	t_complex	current;
	int			iteration;

	current = number;
	iteration = 0;
	while (iteration < max_iterations)
	{
		if (magnitude(current) > infinity)
			return ((t_mandelbrotian){true, iteration});
		current = squared(current);
		current = plus(current, number);
		iteration++;
	}
	return ((t_mandelbrotian){false, iteration});
}

t_mandelbrotian	quick_mandelbrot(t_complex number, int max_iterations,
		double infinity)
{
	t_complex	current;
	int			iteration;

	current = number;
	iteration = 0;
	while (iteration < max_iterations)
	{
		if (quick_magnitude(current) > infinity)
			return ((t_mandelbrotian){true, iteration});
		current = squared(current);
		current = plus(current, number);
		iteration++;
	}
	return ((t_mandelbrotian){false, iteration});
}
