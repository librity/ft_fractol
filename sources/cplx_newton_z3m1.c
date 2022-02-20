/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_newton_z3m1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:06:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 19:16:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

#define Z3M1_ROOTS 3

static t_complex	get_root(int index)
{
	const t_complex	roots[Z3M1_ROOTS] = {
		(t_complex){1, 0},
		(t_complex){-0.5, 0.866025},
		(t_complex){-0.5, -0.866025},
	};

	return (roots[index]);
}

static int	get_root_color(int index)
{
	const int	root_colors[Z3M1_ROOTS] = {RED, GREEN, BLUE};

	return (root_colors[index]);
}

static t_complex	polynomial(t_complex z)
{
	return (minus(cplx_pow(z, 3), complex(1, 0)));
}

static t_complex	polyn_derivative(t_complex z)
{
	return (times_s(times(z, z), 3));
}

int	newton_z3m1(t_complex z, long double tolerance, int max_iterations)
{
	int			iteration;
	int			i_roots;
	t_complex	difference;

	iteration = 0;
	while (iteration < max_iterations)
	{
		z = minus(z, by(polynomial(z), polyn_derivative(z)));
		i_roots = 0;
		while (i_roots < Z3M1_ROOTS)
		{
			difference = minus(z, get_root(i_roots));
			if (ft_abs_ld(difference.real) < tolerance
				&& ft_abs_ld(difference.imaginary) < tolerance)
				return (get_root_color(i_roots));
			i_roots++;
		}
		iteration++;
	}
	return (BLACK);
}
