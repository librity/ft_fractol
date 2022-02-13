/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:45:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 12:46:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map_d
{
	double	mapped;
	double	start1;
	double	stop1;
	double	start2;
	double	stop2;
}			t_map_d;

double		map_d(t_map_d args);
double		clamp_d(double n, double low, double high);
double		map_clamped_d(t_map_d args);

#endif
