/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 17:05:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_fractal	mandelbrot(t_complex number, int max_iterations, double infinity)
{
	t_complex	current;
	int			iteration;

	current = number;
	iteration = 0;
	while (iteration < max_iterations)
	{
		if (magnitude(current) > infinity)
			return ((t_fractal){true, iteration});
		current = squared(current);
		current = plus(current, number);
		iteration++;
	}
	return ((t_fractal){false, iteration});
}

t_fractal	quick_mandelbrot(t_complex number, int max_iterations,
		double infinity)
{
	t_complex	current;
	int			iteration;
	double		temp;

	current = number;
	iteration = 0;
	while (iteration < max_iterations)
	{
		if (quick_magnitude(current) > infinity)
			return ((t_fractal){true, iteration});
		temp = current.real;
		current.real = current.real * current.real;
		current.real -= current.imaginary * current.imaginary;
		current.real += number.real;
		current.imaginary = 2 * current.imaginary * temp + number.imaginary;
		iteration++;
	}
	return ((t_fractal){false, iteration});
}
