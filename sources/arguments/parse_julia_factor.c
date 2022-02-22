/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_julia_factor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:39:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/22 11:25:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	print_julia_factor(char **argv)
{
	ft_putstr(" => Julia Factor: ");
	ft_putstr(argv[2]);
	ft_putstr(" ");
	ft_putendl(argv[3]);
}

static void	print_parsed_julia_factor(long double real, long double imaginary)
{
	ft_putstr(" => Parsed Julia Factor: ");
	ft_putnbr_ld(real);
	ft_putstr(" ");
	ft_putnbr_ld(imaginary);
	ft_putstr("\n");
}

t_complex	parse_julia_factor(char **argv)
{
	long double	real;
	long double	imaginary;

	print_julia_factor(argv);
	real = ft_atold(argv[2]);
	imaginary = ft_atold(argv[3]);
	print_parsed_julia_factor(real, imaginary);
	return (complex(real, imaginary));
}
