/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:56:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:41:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	cx_new(long double real, long double imaginary)
{
	return ((t_complex){real, imaginary});
}

void	cx_print(t_complex number)
{
	ft_printf("%Lf + %Lfi\n", number.real, number.imaginary);
}

void	cx_inspect(t_complex number)
{
	ft_printf("REAL: %Lf, IMAGINARY: %Lf\n", number.real, number.imaginary);
}
