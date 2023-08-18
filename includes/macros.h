/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:33:54 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:35:44 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// KEY INPUTS

# define ESC				65307
# define UP_ARROW 			65362
# define DOWN_ARROW			65364
# define LEFT_ARROW			65361
# define RIGHT_ARROW		65363
# define PLUS				65451
# define MINUS				65453
# define M_KEY				109
# define J_KEY				106
# define T_KEY				116
# define F_KEY				102
# define R_KEY				114
# define W_KEY				119
# define S_KEY				115
# define A_KEY				97
# define D_KEY				100
# define M_KEY_LEFT			1
# define M_KEY_RIGHT		3
# define M_KEY_MIDDLE		2
# define ZOOM_IN			4
# define ZOOM_OUT			5

// COLORS

# define CYAN	0x00ffff
# define PURPLE	0x800080
# define INDIGO 0x4B0082
# define ORANGE	0xffa500
# define RED	0xff0000
# define GREEN	0x00ff00
# define BLUE	0x0000ff
# define MISC1	0xc792ea
# define WILD	0xf0963C
# define BLACK	0x000000

// FRACTAL LIMITS

# define ITERATIONS						150
# define MANDEL_REAL_LOWER_LIMIT		-2
# define MANDEL_REAL_UPPER_LIMIT		0.47
# define MANDEL_IMAGINARY_LOWER_LIMIT	-1.12
# define MANDEL_IMAGINARY_UPPER_LIMIT	1.12
# define TRICORN_REAL_LOWER_LIMIT		-2.5
# define TRICORN_REAL_UPPER_LIMIT		1
# define TRICORN_IMAGINARY_LOWER_LIMIT	-1
# define TRICORN_IMAGINARY_UPPER_LIMIT	1
# define DEFAULT_JULIA_REAL				-0.7
# define DEFAULT_JULIA_IMAGINARY		0.27015

// WINDOW SETTINGS

# define WIDTH 900
# define HEIGHT 900

#endif
