/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 13:20:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/Xlib.h>
# include <complex.h>
# include <libft.h>
# include <map.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>

# define WINDOW_NAME "fractol"

# define ESC_KEY 0xFF1B
# define Q_KEY 0x71

typedef struct s_img_buffer
{
	void			*img;
	char			*data;
	int				width;
	int				height;
	int				line_size;
	int				bpp;
	int				endian;
}					t_img_buffer;

typedef struct s_mandelbrot
{
	int				max_iterations;
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
	int				line_size;
	int				bpp;
	int				endian;
	t_mandelbrot	mbt;
}					t_fractol;

void				initialize_mlx(t_fractol *ctl);
void				initialize_mlx_window(t_fractol *ctl);
void				initialize_mlx_buffer(t_fractol *ctl);
void				initialize_mlx_hooks(t_fractol *ctl);

int					trgb_to_int(int transparency, int red, int green, int blue);
bool				out_of_bounds(t_img_buffer *buffer, int x, int y);
void				draw_to_buffer(t_img_buffer *buffer, int x, int y,
					int color);

int					handle_keypress(int keycode, t_fractol *ctl);
void				clean_and_exit(t_fractol *ctl);

void				die(void);

#endif
