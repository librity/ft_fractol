/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:25:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	cx_conjugate(t_complex number)
{
	t_complex	result;

	result.real = number.real;
	result.imaginary = -number.imaginary;
	return (result);
}

long double	cx_magnitude(t_complex number)
{
	long double	magnitude;

	magnitude = number.real * number.real + number.imaginary * number.imaginary;
	magnitude = sqrtl(magnitude);
	return (magnitude);
}

long double	cx_quick_magnitude(t_complex number)
{
	long double	magnitude;

	magnitude = number.real * number.real + number.imaginary * number.imaginary;
	return (magnitude);
}

t_complex	cx_squared(t_complex number)
{
	t_complex	result;

	result.real = number.real * number.real;
	result.real -= number.imaginary * number.imaginary;
	result.imaginary = 2 * number.real * number.imaginary;
	return (result);
}

t_complex	cx_square_root(t_complex number)
{
	t_complex	result;
	long double	root_of_square_sum;

	root_of_square_sum = sqrtl(
			number.real * number.real
			+ number.imaginary * number.imaginary);
	result.real = sqrtl((number.real + root_of_square_sum) / 2);
	result.imaginary = sqrtl((-number.real + root_of_square_sum) / 2);
	return (result);
}
