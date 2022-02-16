/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/16 09:33:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WINDOW_NAME "lpaulo-m's fract-ol"

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

/******************************************************************************\
 * INITIAL PARAMS
\******************************************************************************/

# define MANDELBROT_CODE 0
# define JULIA_CODE 1

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

# define MAX_ITERATIONS 50
# define DIVERSION_LIMIT 10
# define ZOOM 200
# define X_OFFSET 0
# define Y_OFFSET 0
# define LERP_STEPS 256

# define DYE1 0x00FA1588
# define DYE2 0x00f9cb9c
# define DYE3 0x0000ff7f

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

# define ZOOM_STEP 1000

/******************************************************************************\
 * ZOOM STEP
\******************************************************************************/

# define ACCENT_KEY 65105
# define P_KEY 112

# define ZOOM_STEP_STEP 50

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

# define NAVIGATION_FACTOR 100
# define NAVIGATION_STEP 1

/******************************************************************************\
 * NAVIGATION STEP
\******************************************************************************/

# define RSHIFT_KEY 65506
# define SEMICOLON_KEY 59

# define NAVIGATION_STEP_STEP 1

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

/******************************************************************************\
 * COLOR BITWISE
\******************************************************************************/

# define T_MASK 0xFF000000
# define R_MASK 0x00FF0000
# define G_MASK 0x0000FF00
# define B_MASK 0x000000FF

#endif
