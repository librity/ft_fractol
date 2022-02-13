/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:16:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 12:44:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double	map_d(t_map_d args)
{
	double	mapped;

	mapped = (args.mapped - args.start1) / (args.stop1 - args.start1)
		* (args.stop2 - args.start2) + args.start2;
	return (mapped);
}

double	clamp_d(double n, double low, double high)
{
	return (ft_max_d(ft_min_d(n, high), low));
}

double	map_clamped_d(t_map_d args)
{
	double	mapped;

	mapped = map_d(args);
	if (args.start2 < args.stop2)
		return (clamp_d(mapped, args.start2, args.stop2));
	return (clamp_d(mapped, args.stop2, args.start2));
}
