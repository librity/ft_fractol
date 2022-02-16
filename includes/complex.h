/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:13:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 14:53:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <stdbool.h>

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct s_fractal
{
	bool		diverges;
	int			iterations;
}				t_fractal;

t_complex		complex(double real, double imaginary);

double			magnitude(t_complex cmplx);
double			quick_magnitude(t_complex cmplx);
t_complex		squared(t_complex cmplx);

t_complex		plus(t_complex a, t_complex b);
t_complex		times(t_complex a, t_complex b);

t_fractal		mandelbrot(t_complex number,
					int max_iterations,
					double infinity);
t_fractal		quick_mandelbrot(t_complex number,
					int max_iterations,
					double infinity);

t_fractal		julia(t_complex number, t_complex factor, int max_iterations,
					double infinity);
t_fractal		quick_julia(t_complex number, t_complex factor,
					int max_iterations, double infinity);

#endif
