/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/20 19:33:24 by lpaulo-m         ###   ########.fr       */
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

# define QUICK_FRACTAL 1

typedef enum e_fractal_code
{
	MANDELBROT_CODE = 0,
	JULIA_CODE,
	NEWTON_CODE
}	t_fractal_code;

# define MANDELBROT_ARG "mandelbrot"
# define JULIA_ARG "julia"
# define NEWTON_ARG "newton"

# define NEWTON_ROOT_COLOR 1

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

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define ZOOM 200
# define ZOOM_MAGNIFICATION 1.2

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

# define MOUSE_LEFT_CLICK 1
# define MOUSE_MIDDLE_CLICK 2
# define MOUSE_RIGHT_CLICK 3

# define X_OFFSET 0
# define Y_OFFSET 0
# define SCALE_FACTOR 0.1
# define DEADZONE 50

/******************************************************************************\
 * MAX ITERATIONS
\******************************************************************************/

# define I_KEY 105
# define K_KEY 107

# define MAX_ITERATIONS 51
# define MAX_ITERATIONS_STEP 100

/******************************************************************************\
 * INFINITY
\******************************************************************************/

# define T_KEY 116
# define G_KEY 103

# define MY_INFINITY 4
# define INFINITY_STEP 10

/******************************************************************************\
 * SAVE TO BITMAP
\******************************************************************************/

# define S_KEY 115

# define BM_SEPARATOR "_"
# define BM_MBT "mbt_"
# define BM_JULIA "julia_"
# define BM_JULIA_REAL "real_"
# define BM_JULIA_IMAGINARY "imgry_"
# define BM_NEWTON "newton_"
# define BM_X "x_"
# define BM_Y "y_"
# define BM_ZOOM "zoom_"
# define BM_ITERATIONS "iter_"
# define BM_INFINITY "inf_"
# define BM_COLOR_MODE "cmode_"
# define BM_DYE "dye_"
# define BM_LERP_FROM "lerpfr_"
# define BM_LERP_TO "lerpto_"
# define BM_EXTENSION ".bmp"

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
 * COLOR MODE
\******************************************************************************/

# define C_KEY 99

typedef enum e_color_code
{
	ESCAPE_TIME_CODE = 0,
	LERP_CODE,
	BERNSTEIN_CODE,
}	t_color_code;
# define COLOR_MODES 3

# define ESCAPE_TIME_MODE "Escape Time"
# define LERP_MODE "Linear Interpolation"
# define BERNSTEIN_MODE "Bernstein Polynomials"

/******************************************************************************\
 * COLOR SHIFT
\******************************************************************************/

# define L_KEY 108
# define PERIOD_KEY 46

# define DYE_SHIFT 0x00F00000
# define LERP_SHIFT 0x00F00000

/******************************************************************************\
 * COLORS
\******************************************************************************/

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

# define HELP_MSG "Welcome to lpaulo-m's fract-ol!\n\
\n\
USAGE:\n\
	fractol [mandelbrot/julia] [params]\n\
\n\
EXAMPLES:\n\
	fractol mandelbrot		Mandelbrot fractal\n\
	fractol julia -0.391 -0.587	Julia fractal\n\
\n\
"

# define MLX_MSG " => Initializing minilibx..."
# define WINDOW_MSG " => Creating window..."
# define BUFFER_MSG " => Initializing image buffer..."
# define HOOKS_MSG " => Adding hooks..."

# define RED_MSG " => Rendering red screen (invalid fractal code)..."
# define MBT_MSG " => Rendering Mandelbrot set..."
# define JULIA_MSG " => Rendering Julia set..."
# define NEWTON_MSG " => Rendering Newton set for polynomial (z^3 - 1)..."

# define MIN_ITERATIONS_MSG " => Iterations must be greater than 0"
# define MIN_INFINITY_MSG " => Infinity must be greater than 0"

# define BM_MSG " => Saving viewport to bitmap file: "

#endif
