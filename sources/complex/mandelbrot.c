/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/21 20:34:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_fractal	slow_mandelbrot(t_complex number, int max_iterations,
		long double infinity)
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

t_fractal	fast_mandelbrot(t_complex number, int max_iterations,
		long double infinity)
{
	int			iteration;
	t_complex	aux;
	t_complex	current;

	iteration = 0;
	aux = complex(0, 0);
	current = complex(0, 0);
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
