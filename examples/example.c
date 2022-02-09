/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/08 23:02:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(void)
{
	t_complex_ld number;

	number.real = 3;
	number.imaginary = 4;
	inspect_complex_ld(number);
	return (0);
}
