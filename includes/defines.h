/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/17 13:43:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VERBOSE 1

/******************************************************************************\
 * WINDOW
\******************************************************************************/

# define WINDOW_NAME "lpaulo-m's fract-ol"

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

/******************************************************************************\
 * FRACTALS
\******************************************************************************/

typedef enum e_fractal_code
{
	MANDELBROT_CODE = 0,
	JULIA_CODE
}	t_fractal_code;

# define MAX_ITERATIONS 50
# define DIVERSION_LIMIT 4

/******************************************************************************\
 * QUIT
\******************************************************************************/

# define ESC_KEY 65307
# define Q_KEY 113

/******************************************************************************\
 * ZOOM
\******************************************************************************/

# define EQUALS_KEY 61
# define MINUS_KEY 45

# define ZOOM 200
# define ZOOM_MAGNIFICATION 1.2

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

# define X_OFFSET 0
# define Y_OFFSET 0
# define SCALE_FACTOR 0.1

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
 * SAVE TO BITMAP
\******************************************************************************/

# define S_KEY 115
# define B_KEY 98

/******************************************************************************\
 *
\******************************************************************************/

# define ACCENT_KEY 65105
# define P_KEY 112

/******************************************************************************\
 *
\******************************************************************************/

# define RSHIFT_KEY 65506
# define SEMICOLON_KEY 59

/******************************************************************************\
 * COLOR SHIFT
\******************************************************************************/

# define L_KEY 108
# define PERIOD_KEY 46

typedef enum e_color_code
{
	ESCAPE_TIME_CODE = 0,
	LERP_CODE,
	BERNSTEIN_CODE
}	t_color_code;

# define DYE_SHIFT 0x00F00000
# define LERP_SHIFT 0x00F00000

/******************************************************************************\
 * COLORS
\******************************************************************************/

# define T_MASK 0xFF000000
# define R_MASK 0x00FF0000
# define G_MASK 0x0000FF00
# define B_MASK 0x000000FF

# define DYE1 0x00FA1588
# define DYE2 0x00f9cb9c
# define DYE3 0x0000ff7f
# define DYE4 0x00f7943a
# define DYE5 0x008b39ef
# define DYE6 0x00d1f8ff

# define LERP_STEPS 256
# define LERP1_FROM 0x00000000
# define LERP1_TO 0x00FFFFFF
# define LERP2_FROM 0x00f9cb9c
# define LERP2_TO 0x0000ff7f
# define LERP3_FROM 0x00F14F32
# define LERP3_TO 0x0026A7E3
# define LERP4_FROM 0x00F49E8E
# define LERP4_TO 0x00515656

/******************************************************************************\
 * MESSAGES
\******************************************************************************/

# define WELCOME_MSG "=== lpaulo-m presents: fract-ol ==="
# define EXIT_MSG "=== That's all folks! ==="
# define SUCCESS_MSG " DONE"

# define MLX_MSG " => Initializing minilibx..."
# define WINDOW_MSG " => Creating window..."
# define BUFFER_MSG " => Initializing image buffer..."
# define HOOKS_MSG " => Adding hooks..."

# define MBT_MSG " => Rendering Mandelbrot set..."
# define JULIA_MSG " => Rendering Julia set..."

#endif
