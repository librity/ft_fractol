/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:30:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(void)
{
	const t_complex	a = cx_new(3.0, 4.0);

	inspect(a);
	printf("magnitude: %f\n", cx_magnitude(a));
	printf("quick_magnitude: %f\n", cx_quick_magnitude(a));
	inspect(cx_squared(a));

	const t_complex	b = cx_new(5.0, 6.0);
	inspect(cx_plus(a, b));
	inspect(cx_times(a, b));

	return (0);
}
