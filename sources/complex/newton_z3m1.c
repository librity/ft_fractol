/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_newton_z3m1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/21 21:26:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

#define NEWTON_Z3M1_ROOTS 3

static t_complex	get_root(int index)
{
	const t_complex	roots[NEWTON_Z3M1_ROOTS] = {
		(t_complex){1, 0},
		(t_complex){-0.5, 0.866025},
		(t_complex){-0.5, -0.866025},
	};

	return (roots[index]);
}

static t_complex	polynomial(t_complex z)
{
	return (minus(cplx_pow(z, 3), complex(1, 0)));
}

static t_complex	polyn_derivative(t_complex z)
{
	return (times_s(times(z, z), 3));
}

t_newton_z3m1	newton_z3m1(t_complex z, long double tolerance,
	int max_iterations)
{
	int			iteration;
	int			root_index;
	t_complex	difference;

	iteration = 0;
	while (iteration < max_iterations)
	{
		z = minus(z, by(polynomial(z), polyn_derivative(z)));
		root_index = 0;
		while (root_index < NEWTON_Z3M1_ROOTS)
		{
			difference = minus(z, get_root(root_index));
			if (ft_abs_ld(difference.real) < tolerance)
				if (ft_abs_ld(difference.imaginary) < tolerance)
					return ((t_newton_z3m1){true, iteration, root_index});
			root_index++;
		}
		iteration++;
	}
	return ((t_newton_z3m1){false, iteration, -1});
}
