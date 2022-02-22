/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:57:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_fractal	cx_slow_julia(t_complex number,
		t_complex factor,
		int max_iterations,
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
		current = cx_plus(current, factor);
		iteration++;
	}
	return ((t_fractal){false, iteration});
}

t_fractal	cx_fast_julia(t_complex number, t_complex factor,
		int max_iterations, long double infinity)
{
	int			iteration;
	long double	temp;

	iteration = 0;
	while (iteration < max_iterations)
	{
		if (cx_quick_magnitude(number) > infinity)
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
