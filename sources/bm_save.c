/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bm_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:43:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 20:47:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	save_to_bitmap(t_fractol *ctl)
{
	char	*filename;

	filename = build_filename(ctl);
	log_msg(BM_MSG);
	bm_save_mlx_image(ctl->buffer, filename);
	log_msg(filename);
	free(filename);
	log_endl(SUCCESS_MSG);
}
