/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 12:59:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(void)
{
	const t_complex	a = complex(3.0, 4.0);

	inspect(a);
	printf("magnitude: %f\n", magnitude(a));
	printf("quick_magnitude: %f\n", quick_magnitude(a));
	inspect(squared(a));

	const t_complex	b = complex(5.0, 6.0);
	inspect(plus(a, b));
	inspect(cplx_times(a, b));

	return (0);
}
