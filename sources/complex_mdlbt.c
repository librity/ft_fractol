/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mdlbt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/09 01:03:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_mdlbt	mandlebrot(t_complex number, int max_iterations, double infinity)
{
	t_complex	current;
	int			iteration;

	current = number;
	iteration = 0;
	while (iteration < max_iterations)
	{
		if (magnitude(current) > infinity)
			return ((t_mdlbt){true, iteration});
		current = squared(current);
		current = plus(current, number);
		iteration++;
	}
	return ((t_mdlbt){false, iteration});
}

t_mdlbt	quick_mandlebrot(t_complex number, int max_iterations, double infinity)
{
	t_complex	current;
	int			iteration;

	current = number;
	iteration = 0;
	while (iteration < max_iterations)
	{
		if (quick_magnitude(current) > infinity)
			return ((t_mdlbt){true, iteration});
		current = squared(current);
		current = plus(current, number);
		iteration++;
	}
	return ((t_mdlbt){false, iteration});
}
