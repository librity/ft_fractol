/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_newton_z3m1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 17:48:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static t_complex	function(t_complex z)
{
	return (minus(cplx_pow(z, 3), complex(1, 0)));
}

static t_complex	derivative(t_complex z)
{
	return (times_s(times(z, z), 3));
}

int	newton_z3m1(t_complex number, int max_iterations)
{
	t_complex	z;
	int			iteration;
	int			i;
	long double	tolerance;
	t_complex	difference;

	t_complex roots[3] = {
		(t_complex){1, 0},
		(t_complex){-0.5, sqrtl(3) / 2},
		(t_complex){-0.5, -(sqrtl(3) / 2)},
	};
	int colors[3] = {RED, GREEN, BLUE};
	z = number;
	iteration = 0;
	tolerance = 0.000001;
	while (iteration < max_iterations)
	{
		z = minus(z, by(function(z), derivative(z)));
		i = 0;
		while (i < 3)
		{
			difference = minus(z, roots[i]);
			if (ft_abs_ld(difference.real) < tolerance
				&& ft_abs_ld(difference.imaginary) < tolerance)
			{
				return (colors[i]);
			}
			i++;
		}
		iteration++;
	}
	return (BLACK);
}
