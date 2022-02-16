/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 00:06:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WINDOW_NAME "lpaulo-m's fract-ol"

# define WELCOME_MSG "=== lpaulo-m presents: fract-ol ==="
# define EXIT_MSG "=== That's all folks! ==="
# define SUCCESS_MSG " DONE"

# define MLX_MSG " => Initializing minilibx..."
# define WINDOW_MSG " => Creating window..."
# define BUFFER_MSG " => Initializing image buffer..."
# define HOOKS_MSG " => Adding hooks..."

# define MBT_MSG " => Rendering Mandelbrot set..."
# define JULIA_MSG " => Rendering Julia set..."

/******************************************************************************\
 * PARAMS
\******************************************************************************/

# define MANDELBROT_CODE 0
# define JULIA_CODE 1

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

# define MAX_ITERATIONS 100
# define DIVERSION_LIMIT 30
# define ZOOM 200
# define X_OFFSET -100
# define Y_OFFSET 0
# define LERP_STEPS 256

# define GRADIENT1_FROM 0x00000000
# define GRADIENT1_TO 0x00FFFFFF
# define GRADIENT2_FROM 0x00f9cb9c
# define GRADIENT2_TO 0x0000ff7f

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

#endif
