/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/21 20:33:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_fractal	slow_julia(t_complex number, t_complex factor, int max_iterations,
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
		current = plus(current, factor);
		iteration++;
	}
	return ((t_fractal){false, iteration});
}

t_fractal	fast_julia(t_complex number, t_complex factor,
		int max_iterations, long double infinity)
{
	int			iteration;
	long double	temp;

	iteration = 0;
	while (iteration < max_iterations)
	{
		if (quick_magnitude(number) > infinity)
			return ((t_fractal){true, iteration});
		temp = number.real;
		number.real = number.real * number.real;
		number.real -= number.imaginary * number.imaginary;
		number.real += factor.real;
		number.imaginary = 2 * number.imaginary * temp + factor.imaginary;
		iteration++;
	}
	return ((t_fractal){false, iteration});
}
