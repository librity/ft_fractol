/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:13:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 17:21:50 by lpaulo-m         ###   ########.fr       */
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

typedef struct s_fractal
{
	bool		diverges;
	int			iterations;
}				t_fractal;

t_complex		complex(long double real, long double imaginary);

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
t_complex		times(t_complex a, t_complex b);
t_complex		by(t_complex a, t_complex b);
t_complex		cplx_pow(t_complex number, int power);

t_fractal		mandelbrot(t_complex number, int max_iterations,
					long double infinity);
t_fractal		julia(t_complex number, t_complex factor,
					int max_iterations,
					long double infinity);
int				newton_z3m1(t_complex number, int max_iterations);

#endif
