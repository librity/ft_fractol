/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/09 00:03:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	complex(double real, double imaginary)
{
	return ((t_complex){real, imaginary});
}

void	inspect(t_complex cmplx)
{
	printf("%f + %fi\n", cmplx.real, cmplx.imaginary);
}
