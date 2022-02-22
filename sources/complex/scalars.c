/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:41:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	cx_plus_s(t_complex x, long double scalar)
{
	t_complex	result;

	result.real = x.real + scalar;
	result.imaginary = x.imaginary;
	return (result);
}

t_complex	cx_minus_s(t_complex x, long double scalar)
{
	t_complex	result;

	result.real = x.real - scalar;
	result.imaginary = x.imaginary;
	return (result);
}

t_complex	cx_times_s(t_complex x, long double scalar)
{
	t_complex	result;

	result.real = x.real * scalar;
	result.imaginary = x.imaginary * scalar;
	return (result);
}

t_complex	cx_by_s(t_complex x, long double scalar)
{
	t_complex	result;

	result.real = x.real / scalar;
	result.imaginary = x.imaginary / scalar;
	return (result);
}
