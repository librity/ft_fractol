/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:13:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/08 23:56:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

t_complex	complex(double real, double imaginary);
void		inspect(t_complex cmplx);

double		magnitude(t_complex cmplx);
double		quick_magnitude(t_complex cmplx);
t_complex	squared(t_complex cmplx);

t_complex	plus(t_complex a, t_complex b);
t_complex	times(t_complex a, t_complex b);

#endif
