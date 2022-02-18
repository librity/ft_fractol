/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 20:58:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/Xlib.h>
# include <colors.h>
# include <complex.h>
# include <defines.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_fractol
{
	int			width;
	int			height;
	void		*mlx;
	void		*window;
	t_mlx_image	*buffer;

	int			fractal_code;
	int			max_iterations;
	double		infinity;
	t_complex	julia_factor;

	int			color_code;
	double		zoom;
	double		scale_factor;
	double		x_offset;
	double		y_offset;

	int			dye;
	int			lerp_steps;
	int			lerp_from;
	int			lerp_to;
}					t_fractol;

void				initialize_params(t_fractol *ctl);
void				initialize(t_fractol *ctl);

void				initialize_mlx(t_fractol *ctl);
void				initialize_mlx_window(t_fractol *ctl);
void				initialize_mlx_buffer(t_fractol *ctl);
void				initialize_mlx_hooks(t_fractol *ctl);

void				switch_color_mode(t_fractol *ctl);
int					render_color(t_fractol *ctl, double iterations);
int					escape_time_color(t_fractol *ctl, double iterations);
int					lerp_color(t_fractol *ctl, double iterations);
int					bernstein_color(double iterations);

void				shift_colors_up(t_fractol *ctl);
void				shift_colors_down(t_fractol *ctl);

int					handle_destroy(t_fractol *ctl);
int					handle_keypress(int keycode, t_fractol *ctl);

void				handle_close(int keycode, t_fractol *ctl);
void				handle_zoom(int keycode, t_fractol *ctl);
void				handle_navigation(int keycode, t_fractol *ctl);
void				handle_color_shift(int keycode, t_fractol *ctl);
void				handle_save_to_bitmap(int keycode, t_fractol *ctl);
void				handle_color_mode(int keycode, t_fractol *ctl);
void				handle_max_iterations(int keycode, t_fractol *ctl);
void				handle_infinity(int keycode, t_fractol *ctl);

void				zoom_in(t_fractol *ctl);
void				zoom_out(t_fractol *ctl);

void				move_up(t_fractol *ctl);
void				move_down(t_fractol *ctl);
void				move_left(t_fractol *ctl);
void				move_right(t_fractol *ctl);

void				increase_max_iterations(t_fractol *ctl);
void				decrease_max_iterations(t_fractol *ctl);

void				increase_infinity(t_fractol *ctl);
void				decrease_infinity(t_fractol *ctl);

void				log_msg(char *message);
void				log_endl(char *message);

void				log_keycode(int keycode);
void				log_zoom(t_fractol *ctl);
void				log_position(t_fractol *ctl);
void				log_colors(t_fractol *ctl);
void				log_color_code(t_fractol *ctl);
void				log_max_iterations(t_fractol *ctl);
void				log_infinity(t_fractol *ctl);

double				screen_to_cartesian_x(t_fractol *ctl, int x);
double				screen_to_cartesian_y(t_fractol *ctl, int y);

void				render_fractal(t_fractol *ctl);
void				render_mandelbrot(t_fractol *ctl);
void				render_julia(t_fractol *ctl);

void				save_to_bitmap(t_fractol *ctl);
char				*build_filename(t_fractol *ctl);

void				clean_and_exit(t_fractol *ctl);
void				die(void);

#endif
