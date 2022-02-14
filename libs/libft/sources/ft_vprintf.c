/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:18:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 17:17:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static bool	is_a_flag(char current_char)
{
	if (current_char == '.')
		return (true);
	if (current_char == '-')
		return (true);
	if (current_char == '*')
		return (true);
	if (ft_isdigit(current_char))
		return (true);
	return (false);
}

static void	find_current_conversion_position(t_printf *print_control)
{
	int	conversion_position;

	(print_control->format)++;
	conversion_position = 0;
	while (is_a_flag((print_control->format)[conversion_position]) &&
			(print_control->format)[conversion_position] != '\0')
		conversion_position++;
	print_control->conversion_position = conversion_position;
	print_control->conversion = (print_control->format)[conversion_position];
}

void	ft_vprintf(t_printf *print_control)
{
	while (*(print_control->format) != '\0')
	{
		if (handled_no_conversion(print_control))
			continue ;
		find_current_conversion_position(print_control);
		if (handled_percent(print_control))
			continue ;
		if (handled_c(print_control))
			continue ;
		if (handled_s(print_control))
			continue ;
		if (handled_int(print_control))
			continue ;
		if (handled_u(print_control))
			continue ;
		if (handled_p(print_control))
			continue ;
		if (handled_hex(print_control))
			continue ;
	}
}
