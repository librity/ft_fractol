/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/02/22 13:52:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <fractol.h>
#include <fractol.h>
#include "minunit.h"

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(mandelbrot_integration)
{
	t_fractol	ctl;
	t_mlx_image	buffer;

	initialize_params(&ctl, &buffer);
	ctl.fractal_code = MANDELBROT_CODE;
	ctl.render_fractal = render_mandelbrot;
	ft_putendl(WELCOME_MSG);
	initialize_mlx(&ctl);

	move_up(&ctl);
	move_left(&ctl);
	save_to_bitmap(&ctl);
	switch_color_mode(&ctl);
	save_to_bitmap(&ctl);
	increase_max_iterations(&ctl);
	zoom_in(&ctl);
	switch_color_mode(&ctl);
	save_to_bitmap(&ctl);
	increase_max_iterations(&ctl);
	zoom_in(&ctl);
	save_to_bitmap(&ctl);
	warp(&ctl, 0, 0);
	increase_infinity(&ctl);
	save_to_bitmap(&ctl);
	mouse_zoom_in(&ctl, 0, 0);
	save_to_bitmap(&ctl);

	clean(&ctl);
}

MU_TEST(julia_integration)
{
	t_fractol	ctl;
	t_mlx_image	buffer;

	initialize_params(&ctl, &buffer);
	ctl.fractal_code = JULIA_CODE;
	ctl.render_fractal = render_julia;
	ft_putendl(WELCOME_MSG);
	initialize_mlx(&ctl);

	move_up(&ctl);
	move_left(&ctl);
	save_to_bitmap(&ctl);
	switch_color_mode(&ctl);
	save_to_bitmap(&ctl);
	increase_max_iterations(&ctl);
	zoom_in(&ctl);
	switch_color_mode(&ctl);
	save_to_bitmap(&ctl);
	increase_max_iterations(&ctl);
	zoom_in(&ctl);
	save_to_bitmap(&ctl);
	warp(&ctl, 0, 0);
	increase_infinity(&ctl);
	save_to_bitmap(&ctl);
	mouse_zoom_in(&ctl, 0, 0);
	save_to_bitmap(&ctl);

	clean(&ctl);
}

MU_TEST(newton_integration)
{
	t_fractol	ctl;
	t_mlx_image	buffer;

	initialize_params(&ctl, &buffer);
	ctl.fractal_code = NEWTON_CODE;
	ctl.render_fractal = render_newton;
	ft_putendl(WELCOME_MSG);
	initialize_mlx(&ctl);

	move_up(&ctl);
	move_left(&ctl);
	save_to_bitmap(&ctl);
	switch_color_mode(&ctl);
	save_to_bitmap(&ctl);
	increase_max_iterations(&ctl);
	zoom_in(&ctl);
	switch_color_mode(&ctl);
	save_to_bitmap(&ctl);
	increase_max_iterations(&ctl);
	zoom_in(&ctl);
	save_to_bitmap(&ctl);
	warp(&ctl, 0, 0);
	increase_infinity(&ctl);
	save_to_bitmap(&ctl);
	mouse_zoom_in(&ctl, 0, 0);
	save_to_bitmap(&ctl);

	clean(&ctl);
}

MU_TEST_SUITE(test_suite_tokens)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);
	MU_RUN_TEST(mandelbrot_integration);
	MU_RUN_TEST(julia_integration);
	MU_RUN_TEST(newton_integration);
}

int	main(void)
{
	MU_RUN_SUITE(test_suite_tokens);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
