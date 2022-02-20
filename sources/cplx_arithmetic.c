/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 17:03:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	plus(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imaginary = a.imaginary + b.imaginary;
	return (result);
}

t_complex	minus(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real - b.real;
	result.imaginary = a.imaginary - b.imaginary;
	return (result);
}

t_complex	times(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real * b.real - a.imaginary * b.imaginary;
	result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	return (result);
}

t_complex	by(t_complex a, t_complex b)
{
	t_complex	result;
	long double	denominator;

	denominator = b.real * b.real + b.imaginary * b.imaginary;
	result.real = (a.real * b.real + a.imaginary * b.imaginary)
		/ denominator;
	result.imaginary = (a.imaginary * b.real - a.real * b.imaginary)
		/ denominator;
	return (result);
}

t_complex	cplx_pow(t_complex number, int power)
{
	t_complex	result;

	if (power < 0)
		return (complex(0.0, 0.0));
	if (power == 0)
		return (complex(1.0, 0.0));
	result = times(number, cplx_pow(number, power - 1));
	return (result);
}
