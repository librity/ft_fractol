/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:43:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 15:19:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static char	*build_filename(t_fractol *ctl)
{
	ctl = ctl;
	return ("garmonbozia.bmp");
}

static void	initialize_bm(t_fractol *ctl, t_bitmap_image *image,
		char **filename)
{
	*filename = build_filename(ctl);
	bm_initialize_bitmap(image, ctl->buffer->width, ctl->buffer->height);
}

static void	buffer_to_bm(t_fractol *ctl, t_bitmap_image *image)
{
	int				x;
	int				y;
	int				color;
	t_bitmap_pixel	bm_color;

	x = ctl->buffer->width;
	while (x--)
	{
		y = ctl->buffer->height;
		while (y--)
		{
			color = get_buffer_pixel(ctl->buffer, x, y);
			bm_color = int_to_rgb(color);
			bm_set_pixel(
				&image->pixels[x][y],
				bm_color.red,
				bm_color.green,
				bm_color.blue);
		}
	}
}

static void	cleanup_bm(t_bitmap_image *image, char **free_me)
{
	bm_free_bitmap(image);
	free_me = free_me;
}

void	save_to_bitmap(t_fractol *ctl)
{
	t_bitmap_image	image;
	char			*filename;

	log_msg(BM_MSG);
	initialize_bm(ctl, &image, &filename);
	buffer_to_bm(ctl, &image);
	bm_save_bitmap(&image, filename);
	cleanup_bm(&image, &filename);
	log_endl(SUCCESS_MSG);
}
