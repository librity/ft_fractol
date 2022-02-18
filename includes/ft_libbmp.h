/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 21:08:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBBMP_H
# define FT_LIBBMP_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/******************************************************************************\
 * COLORS
\******************************************************************************/

# define T_MASK 0xFF000000
# define R_MASK 0x00FF0000
# define G_MASK 0x0000FF00
# define B_MASK 0x000000FF

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_bitmap_pixel
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_bitmap_pixel;

typedef struct s_trgb
{
	unsigned char	transparency;
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_trgb;

int					bm_get_t(int color);
int					bm_get_r(int color);
int					bm_get_g(int color);
int					bm_get_b(int color);
int					bm_zero_transparency(int color);

int					bm_trgb_chars_to_int(unsigned char transparency,
						unsigned char red,
						unsigned char green,
						unsigned char blue);
int					bm_rgb_chars_to_int(unsigned char red, unsigned char green,
						unsigned char blue);
int					bm_trgb_to_int(t_trgb color);
t_trgb				bm_int_to_trgb(int color);
t_bitmap_pixel		bm_int_to_rgb(int color);

# define BITMAP_MAGIC_BITS "BM"

/******************************************************************************\
 * BITMAP
\******************************************************************************/

typedef struct s_bitmap_header
{
	unsigned int	buffer_size;
	unsigned int	buffer_reserved;
	unsigned int	buffer_offset;

	unsigned int	total_size;
	int				width;
	int				height;

	unsigned short	planes;
	unsigned short	bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	int				x_resolution_ppm;
	int				y_resolution_ppm;
	unsigned int	colors_used;
	unsigned int	important_colors;
}					t_bitmap_header;

typedef struct s_bitmap_image
{
	t_bitmap_header	header;
	t_bitmap_pixel	**pixels;
}					t_bitmap_image;

typedef struct s_write_pixels
{
	size_t			height;
	size_t			offset;
	size_t			row_width;
	size_t			padding_width;
	unsigned char	padding[3];
}					t_write_pixels;

typedef enum e_bitmap_error
{
	FILE_NOT_OPENED = 1,
	HEADER_NOT_INITIALIZED,
	BAD_MALLOC,
	GENERIC_BITMAP_ERROR
}					t_bitmap_error;

void				bm_initialize_bitmap(t_bitmap_image *image,
						int width,
						int height);

void				bm_set_pixel(t_bitmap_pixel *pxl,
						unsigned char red,
						unsigned char green,
						unsigned char blue);
void				bm_set_image_pixel(t_bitmap_image *image,
						t_bitmap_pixel color,
						int row,
						int column);

void				bm_save_bitmap(t_bitmap_image *image, char *filename);

void				bm_free_bitmap(t_bitmap_image *img);

int					bm_calculate_padding(int number);
int					bm_abs(int number);
void				bm_kill(t_bitmap_error code);

/******************************************************************************\
 * MLX
\******************************************************************************/

typedef struct s_mlx_image
{
	void	*img;
	char	*data;

	int		width;
	int		height;
	int		half_width;
	int		half_height;

	int		line_length;
	int		bits_per_pixel;
	int		endian;
}					t_mlx_image;

void				bm_draw_to_mlx_image(t_mlx_image *buffer, int x, int y,
						int color);
int					bm_get_mlx_image_pixel(t_mlx_image *buffer, int x, int y);

void				bm_save_mlx_image(t_mlx_image *mlx_img, char *filename);

#endif
