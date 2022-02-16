/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:17:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 23:39:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(void)
{
	t_fractol	ctl;

	ft_putendl("=== lpaulo-m presents: fract-ol ===");
	initialize(&ctl);
	mlx_loop(ctl.mlx);
	return (0);
}
