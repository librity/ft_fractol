/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/09 00:11:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	complex(double real, double imaginary)
{
	return ((t_complex){real, imaginary});
}

void	inspect(t_complex number)
{
	printf("%f + %fi\n", number.real, number.imaginary);
}
