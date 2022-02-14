/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 22:38:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Transforms a number n into an allocated string.
*/

static void	write_digits(char *string,
							unsigned long digit_count,
							unsigned long number,
							int is_negative)
{
	string[digit_count] = '\0';
	while (digit_count--)
	{
		string[digit_count] = '0' + (number % 10);
		number /= 10;
	}
	if (is_negative)
		string[0] = '-';
}

char	*ft_ltoa(long n)
{
	unsigned long	digit_count;
	unsigned long	number;
	int				is_negative;
	char			*string;

	digit_count = ft_count_digits_ul(n);
	number = (unsigned long)n;
	is_negative = 0;
	if (n < 0)
	{
		number *= -1;
		is_negative = 1;
	}
	string = malloc(sizeof(char) * (digit_count + 1));
	if (string == NULL)
		return (NULL);
	write_digits(string, digit_count, number, is_negative);
	return (string);
}
