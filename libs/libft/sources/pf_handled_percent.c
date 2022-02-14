/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handled_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 17:17:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	initialize_control(t_printf *print_control,
								t_handle_percent *control)
{
	control->print_me = '%';
	control->char_count = 1;
	initialize_flag_control(print_control, &(control->flag_control));
}

static void	interpret_flags(t_parse_flags *flag_control)
{
	if (flag_control->is_left_justified)
		flag_control->left_padder = ' ';
}

bool	handled_percent(t_printf *print_control)
{
	t_handle_percent	control;
	t_parse_flags		*flag_control;

	if (print_control->conversion != '%')
		return (false);
	initialize_control(print_control, &control);
	flag_control = &(control.flag_control);
	parse_flags(print_control, flag_control);
	interpret_flags(flag_control);
	printf_percent(print_control, &control, flag_control);
	return (true);
}
