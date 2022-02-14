/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bitmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:10:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/13 19:26:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static size_t	resolve_offset(t_bitmap_image *image, t_write_pixels *control)
{
	if (image->header.height > 0)
		return (0);
	return (control->height - 1);
}

static void	initialize_write_pixels(t_bitmap_image *image,
									t_write_pixels *control)
{
	control->height = bm_abs(image->header.height);
	control->offset = resolve_offset(image, control);
	control->row_width = sizeof(t_bitmap_pixel) * image->header.width;
	control->padding_width = sizeof(unsigned char)
		* bm_calculate_padding(image->header.width);
	control->padding[0] = '\0';
	control->padding[1] = '\0';
	control->padding[2] = '\0';
}

static void	write_pixels(t_bitmap_image *image, int file_descriptor)
{
	t_write_pixels	control;
	size_t			current_row;
	int				row_index;
	t_bitmap_pixel	*row_pixels;

	initialize_write_pixels(image, &control);
	current_row = 0;
	while (current_row < control.height)
	{
		row_index = bm_abs(control.offset - current_row);
		row_pixels = image->pixels[row_index];
		write(file_descriptor, row_pixels, control.row_width);
		write(file_descriptor, control.padding, control.padding_width);
		current_row++;
	}
}

static void	write_header(t_bitmap_header *header,
							int file_descriptor)
{
	if (header == NULL)
	{
		close(file_descriptor);
		bm_kill(HEADER_NOT_INITIALIZED);
	}
	write(file_descriptor, BITMAP_MAGIC_BITS, 2);
	write(file_descriptor, header, sizeof(*header));
}

void	bm_save_bitmap(t_bitmap_image *image, char *filename)
{
	int	file_descriptor;

	file_descriptor = open(filename, O_CREAT | O_RDWR, 0664);
	if (file_descriptor < 0)
		bm_kill(FILE_NOT_OPENED);
	write_header(&image->header, file_descriptor);
	write_pixels(image, file_descriptor);
	close(file_descriptor);
}
