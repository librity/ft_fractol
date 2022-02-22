/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:13:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 12:59:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <stdbool.h>

typedef struct s_complex
{
	long double		real;
	long double		imaginary;
}				t_complex;

t_complex		complex(long double real, long double imaginary);
void			cplx_print(t_complex number);
void			cplx_inspect(t_complex number);

long double		magnitude(t_complex cmplx);
long double		quick_magnitude(t_complex cmplx);
t_complex		squared(t_complex cmplx);
t_complex		conjugate(t_complex number);
t_complex		square_root(t_complex number);

t_complex		plus_s(t_complex x, long double scalar);
t_complex		minus_s(t_complex x, long double scalar);
t_complex		times_s(t_complex x, long double scalar);
t_complex		by_s(t_complex x, long double scalar);

t_complex		plus(t_complex a, t_complex b);
t_complex		minus(t_complex a, t_complex b);
t_complex		cplx_times(t_complex a, t_complex b);
t_complex		by(t_complex a, t_complex b);
t_complex		cplx_pow(t_complex number, int power);

typedef struct s_fractal
{
	bool		diverges;
	int			iterations;
}				t_fractal;

typedef t_fractal		(*t_mbt_cb)(
			t_complex number,
			int max_iterations,
			long double infinity);
t_fractal		slow_mandelbrot(t_complex number, int max_iterations,
					long double infinity);
t_fractal		fast_mandelbrot(t_complex number, int max_iterations,
					long double infinity);

typedef t_fractal		(*t_julia_cb)(
			t_complex number,
			t_complex factor,
			int max_iterations,
			long double infinity);
t_fractal		slow_julia(t_complex number,
					t_complex factor,
					int max_iterations,
					long double infinity);
t_fractal		fast_julia(t_complex number,
					t_complex factor,
					int max_iterations,
					long double infinity);

# define NEWTON_Z3M1_ROOTS 3

typedef struct s_newton_z3m1
{
	bool		is_root;
	int			iterations;
	int			root_index;
}				t_newton_z3m1;

typedef t_newton_z3m1	(*t_newton_cb)(
			t_complex number,
			long double tolerance,
			int max_iterations);
t_newton_z3m1	newton_z3m1(t_complex z, long double tolerance,
					int max_iterations);

#endif
