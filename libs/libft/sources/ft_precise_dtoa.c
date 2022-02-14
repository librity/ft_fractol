/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precise_dtoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 23:56:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Transforms a floating point number n into an allocated string.
*/

static void	cast_parts(double n, long long *whole, double *decimal)
{
	*whole = (long long)n;
	*decimal = (n - *whole);
	if (*decimal < 0)
		*decimal *= -1;
	if (*whole < 0)
		*whole *= -1;
}

static void	whole_to_string(double n, char **whole_str, long long whole)
{
	char	*aux;

	*whole_str = ft_ltoa(whole);
	if (n < 0)
	{
		aux = *whole_str;
		*whole_str = ft_strjoin("-", *whole_str);
		free(aux);
	}
}

static void	decimal_to_string(int precision, char **decimal_str, double decimal)
{
	char	*aux;

	if (decimal > 1.0 / (double)ft_pow(10, precision))
	{
		*decimal_str = ft_itoa((int)(decimal * ft_pow(10, precision)));
		return ;
	}
	aux = ft_itoa((int)(decimal * ft_pow(10, precision)));
	while (--precision)
	{
		*decimal_str = ft_strjoin("0", aux);
		free(aux);
		aux = *decimal_str;
	}
}

static char	*piece_together(char *whole_str, char *decimal_str)
{
	char	*float_str;

	float_str = ft_strjoin(whole_str, ".");
	free(whole_str);
	float_str = ft_strjoin_and_free_free(float_str, decimal_str);
	return (float_str);
}

char	*ft_precise_dtoa(double n, int precision)
{
	long long	whole;
	double		decimal;
	char		*whole_str;
	char		*decimal_str;

	if (precision < 0)
		return (NULL);
	cast_parts(n, &whole, &decimal);
	whole_to_string(n, &whole_str, whole);
	decimal_to_string(precision, &decimal_str, decimal);
	return (piece_together(whole_str, decimal_str));
}
