/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:29:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_fractal	cx_slow_mandelbrot(t_complex number, int max_iterations,
		long double infinity)
{
	t_complex	current;
	int			iteration;

	current = number;
	iteration = 0;
	while (iteration < max_iterations)
	{
		if (cx_magnitude(current) > infinity)
			return ((t_fractal){true, iteration});
		current = cx_squared(current);
		current = cx_plus(current, number);
		iteration++;
	}
	return ((t_fractal){false, iteration});
}

t_fractal	cx_fast_mandelbrot(t_complex number, int max_iterations,
		long double infinity)
{
	int			iteration;
	t_complex	aux;
	t_complex	current;

	iteration = 0;
	aux = cx_new(0, 0);
	current = cx_new(0, 0);
	while (iteration < max_iterations)
	{
		if (current.real + current.imaginary > infinity)
			return ((t_fractal){true, iteration});
		aux.imaginary = 2 * aux.real * aux.imaginary + number.imaginary;
		aux.real = current.real - current.imaginary + number.real;
		current.real = aux.real * aux.real;
		current.imaginary = aux.imaginary * aux.imaginary;
		iteration++;
	}
	return ((t_fractal){false, iteration});
}
