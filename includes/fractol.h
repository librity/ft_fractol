/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/15 23:02:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/Xlib.h>
# include <complex.h>
# include <ft_libbmp.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WINDOW_NAME "lpaulo-m's fract-ol"

/******************************************************************************\
 * QUIT
\******************************************************************************/

# define ESC_KEY 65307
# define Q_KEY 113

/******************************************************************************\
 * ZOOM
\******************************************************************************/

# define PLUS_KEY 61
# define MINUS_KEY 45

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

/******************************************************************************\
 * MAX ITERATIONS
\******************************************************************************/

# define I_KEY 105
# define K_KEY 107

/******************************************************************************\
 * INFINITY
\******************************************************************************/

# define T_KEY 116
# define G_KEY 103

/******************************************************************************\
 * LERP STEPS
\******************************************************************************/

# define L_KEY 108
# define PERIOD_KEY 46

typedef struct s_trgb
{
	unsigned char	transparency;
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_trgb;

typedef struct s_img_buffer
{
	void			*img;
	char			*data;
	int				width;
	int				height;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	int				half_width;
	int				half_height;
}					t_img_buffer;

typedef struct s_mandelbrot
{
	int				max_iterations;
	int				lerp_steps;
	int				lerp_from;
	int				lerp_to;
	double			infinity;
	double			zoom;
	double			x_offset;
	double			y_offset;
}					t_mandelbrot;

typedef struct s_fractol
{
	int				width;
	int				height;
	void			*mlx;
	void			*window;
	t_img_buffer	buffer;
	t_mandelbrot	mbt;
}					t_fractol;

void				die(void);

void				initialize_mlx(t_fractol *ctl);
void				initialize_mlx_window(t_fractol *ctl);
void				initialize_mlx_buffer(t_fractol *ctl);
void				initialize_mlx_hooks(t_fractol *ctl);

void				print_bits_ui(unsigned int x);

void				print_color(int color);
void				inspect_color(int color);
void				inspect_trgb(t_trgb trgb);

int					trgb_chars_to_int(unsigned char transparency,
						unsigned char red,
						unsigned char green,
						unsigned char blue);
int					rgb_chars_to_int(unsigned char red,
						unsigned char green,
						unsigned char blue);
int					trgb_to_int(t_trgb color);
t_trgb				int_to_trgb(int color);
t_bitmap_pixel		int_to_rgb(int color);

int					zero_transparency(int color);

t_trgb				trgb_color_lerp_wsteps(t_trgb from, t_trgb to, double steps,
						double x);
int					int_color_lerp_wsteps(int start, int end, double steps,
						double x);
t_trgb				trgb_color_lerp(t_trgb from, t_trgb to, double x);
int					int_color_lerp(int start, int end, double x);

int					resolve_color(t_fractol *ctl, double iterations);

bool				out_of_bounds(t_img_buffer *buffer, int x, int y);
void				draw_to_buffer(t_img_buffer *buffer, int x, int y,
						int color);

int					handle_keypress(int keycode, t_fractol *ctl);
int					handle_destroy(t_fractol *ctl);
void				clean_and_exit(t_fractol *ctl);

double				screen_to_cartesian_x(t_fractol *ctl, int x);
double				screen_to_cartesian_y(t_fractol *ctl, int y);

void				mandelbrot_to_buffer(t_fractol *ctl, int x, int y);
void				render_mandelbrot_set(t_fractol *ctl);
void				render_mandelbrot(t_fractol *ctl);

#endif
