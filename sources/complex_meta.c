/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_meta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 16:41:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double	magnitude(t_complex number)
{
	double	magnitude;

	magnitude = number.real * number.real + number.imaginary * number.imaginary;
	magnitude = sqrt(magnitude);
	return (magnitude);
}

double	quick_magnitude(t_complex number)
{
	double	magnitude;

	magnitude = number.real * number.real + number.imaginary * number.imaginary;
	return (magnitude);
}

t_complex	squared(t_complex number)
{
	t_complex	result;

	result.real = number.real * number.real;
	result.real -= number.imaginary * number.imaginary;
	result.imaginary = 2 * number.real * number.imaginary;
	return (result);
}
