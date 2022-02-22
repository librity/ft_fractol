/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 18:51:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	complex(long double real, long double imaginary)
{
	return ((t_complex){real, imaginary});
}

void	cplx_print(t_complex number)
{
	ft_printf("%Lf + %Lfi\n", number.real, number.imaginary);
}

void	cplx_inspect(t_complex number)
{
	ft_printf("REAL: %Lf, IMAGINARY: %Lf\n", number.real, number.imaginary);
}
