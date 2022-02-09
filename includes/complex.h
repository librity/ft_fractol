/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:13:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/08 21:04:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex_f
{
	float	real;
	float	imaginary;
}				t_complex_f;

typedef struct s_complex_d
{
	double	real;
	double	imaginary;
}				t_complex_d;

typedef struct s_complex_ld
{
	long double	real;
	long double	imaginary;
}				t_complex_ld;

void	inspect(t_complex_ld cmplx);

#endif
