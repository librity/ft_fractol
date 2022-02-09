/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_meta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/08 23:58:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fractol.h>

double	magnitude(t_complex cmplx)
{
	double	magnitude;

	magnitude = cmplx.real * cmplx.real + cmplx.imaginary * cmplx.imaginary;
	magnitude = sqrt(magnitude);
	return (magnitude);
}

double	quick_magnitude(t_complex cmplx)
{
	double	magnitude;

	magnitude = cmplx.real * cmplx.real + cmplx.imaginary * cmplx.imaginary;
	return (magnitude);
}

t_complex	squared(t_complex cmplx)
{
	t_complex	result;

	result.real = cmplx.real * cmplx.real - cmplx.imaginary * cmplx.imaginary;
	result.imaginary = 2 * cmplx.real * cmplx.imaginary;
	return (result);
}
