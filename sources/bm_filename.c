/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bm_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:43:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 19:07:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static char	*resolve_fractal(t_fractol *ctl)
{
	if (ctl->fractal_code == MANDELBROT_CODE)
		return (ft_strdup(BM_MBT));
	if (ctl->fractal_code == JULIA_CODE)
		return (ft_strdup(BM_JULIA));
	return (ft_strdup(""));
}

static char	*cat_double(char *filename, const char *label, double number)
{
	filename = ft_strjoin_free(filename, label);
	filename = ft_strjoin_free_free(filename, ft_dtoa(number));
	filename = ft_strjoin_free(filename, BM_SEPARATOR);
	return (filename);
}

static char	*cat_int(char *filename, const char *label, int number)
{
	filename = ft_strjoin_free(filename, label);
	filename = ft_strjoin_free_free(filename, ft_itoa(number));
	filename = ft_strjoin_free(filename, BM_SEPARATOR);
	return (filename);
}

static char	*resolve_colors(t_fractol *ctl, char *filename)
{
	if (ctl->color_code == BERNSTEIN_CODE)
		return (filename);
	if (ctl->color_code == ESCAPE_TIME_CODE)
		return (cat_int(filename, BM_DYE, ctl->dye));
	filename = cat_int(filename, BM_LERP_FROM, ctl->lerp_from);
	filename = cat_int(filename, BM_LERP_TO, ctl->lerp_to);
	return (filename);
}

char	*build_filename(t_fractol *ctl)
{
	char	*filename;

	filename = resolve_fractal(ctl);
	filename = cat_double(filename, BM_X, ctl->x_offset);
	filename = cat_double(filename, BM_Y, ctl->y_offset);
	filename = cat_double(filename, BM_ZOOM, ctl->zoom);
	filename = cat_int(filename, BM_ITERATIONS, ctl->max_iterations);
	filename = cat_double(filename, BM_INFINITY, ctl->infinity);
	filename = cat_int(filename, BM_COLOR_MODE, ctl->color_code);
	filename = resolve_colors(ctl, filename);
	filename = ft_strjoin_free(filename, BM_EXTENSION);
	return (filename);
}
