/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 20:54:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <ft_libbmp.h>

void	print_color(int color);
void	inspect_color(int color);
void	inspect_trgb(t_trgb trgb);

t_trgb	trgb_color_lerp_wsteps(t_trgb from, t_trgb to, int steps, int x);
int		int_color_lerp_wsteps(int from, int to, int steps, int x);
t_trgb	trgb_color_lerp(t_trgb from, t_trgb to, int x);
int		int_color_lerp(int from, int to, int x);

#endif
