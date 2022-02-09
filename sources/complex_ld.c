/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:13:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/08 23:04:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	inspect_complex_ld(t_complex_ld cmplx)
{
	printf("complex_ld: %Le + %Lei\n", cmplx.real, cmplx.imaginary);
}
