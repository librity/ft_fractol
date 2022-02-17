/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 17:40:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <ft_libbmp.h>

typedef struct s_trgb
{
	unsigned char	transparency;
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_trgb;

void				print_color(int color);
void				inspect_color(int color);
void				inspect_trgb(t_trgb trgb);

int					get_t(int color);
int					get_r(int color);
int					get_g(int color);
int					get_b(int color);
int					zero_transparency(int color);

int					trgb_chars_to_int(unsigned char transparency,
						unsigned char red,
						unsigned char green,
						unsigned char blue);
int					rgb_chars_to_int(unsigned char red, unsigned char green,
						unsigned char blue);
int					trgb_to_int(t_trgb color);
t_trgb				int_to_trgb(int color);
t_bitmap_pixel		int_to_rgb(int color);

t_trgb				trgb_color_lerp_wsteps(t_trgb from, t_trgb to, int steps,
						int x);
int					int_color_lerp_wsteps(int from, int to, int steps, int x);
t_trgb				trgb_color_lerp(t_trgb from, t_trgb to, int x);
int					int_color_lerp(int from, int to, int x);

#endif
