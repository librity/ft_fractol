/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 16:24:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Takes in a string and parses its digits characters into an unsigned integer.
*/

static void	skip_whitespace_and_sign(const char **number_pointer, int *sign)
{
	*sign = -1;
	while (ft_is_whitespace(**number_pointer))
		(*number_pointer)++;
	if (ft_is_plus_or_minus(**number_pointer))
		if (*(*number_pointer)++ == '-')
			*sign = 1;
}

unsigned int	ft_atoui(const char *number_pointer)
{
	int	number;
	int	sign;
	int	previous_number;

	skip_whitespace_and_sign(&number_pointer, &sign);
	number = 0;
	previous_number = 0;
	while (ft_isdigit(*number_pointer))
	{
		number *= 10;
		number -= (*number_pointer++ - '0');
		if (previous_number < number)
		{
			if (sign < 0)
				return (-1);
			return (0);
		}
		previous_number = number;
	}
	if (number * sign < 0)
		return (number * -1);
	return (number * sign);
}
