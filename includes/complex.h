/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:13:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 13:30:04 by lpaulo-m         ###   ########.fr       */
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

t_complex		cx_new(long double real, long double imaginary);
void			cx_print(t_complex number);
void			cx_inspect(t_complex number);

long double		cx_magnitude(t_complex cmplx);
long double		cx_quick_magnitude(t_complex cmplx);
t_complex		cx_squared(t_complex cmplx);
t_complex		cx_conjugate(t_complex number);
t_complex		cx_square_root(t_complex number);

t_complex		cx_plus_s(t_complex x, long double scalar);
t_complex		cx_minus_s(t_complex x, long double scalar);
t_complex		cx_times_s(t_complex x, long double scalar);
t_complex		cx_by_s(t_complex x, long double scalar);

t_complex		cx_plus(t_complex a, t_complex b);
t_complex		cx_minus(t_complex a, t_complex b);
t_complex		cx_times(t_complex a, t_complex b);
t_complex		cx_by(t_complex a, t_complex b);
t_complex		cx_pow(t_complex number, int power);

typedef struct s_fractal
{
	bool		diverges;
	int			iterations;
}				t_fractal;

typedef t_fractal		(*t_mbt_cb)(
			t_complex number,
			int max_iterations,
			long double infinity);
t_fractal		cx_slow_mandelbrot(t_complex number, int max_iterations,
					long double infinity);
t_fractal		cx_fast_mandelbrot(t_complex number, int max_iterations,
					long double infinity);

typedef t_fractal		(*t_julia_cb)(
			t_complex number,
			t_complex factor,
			int max_iterations,
			long double infinity);
t_fractal		cx_slow_julia(t_complex number,
					t_complex factor,
					int max_iterations,
					long double infinity);
t_fractal		cx_fast_julia(t_complex number,
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
t_newton_z3m1	cx_newton_z3m1(t_complex z, long double tolerance,
					int max_iterations);

#endif
