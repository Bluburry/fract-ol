/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:01:32 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:38:15 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "macros.h"
# include "../lib/libft.h"
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>

// STRUCTURES

typedef struct imaginary
{
	double	cr;
	double	ci;
	double	lower_limit_real;
	double	upper_limit_real;
	double	lower_limit_imag;
	double	upper_limit_imag;
	double	julia_r;
	double	julia_i;
	double	radius;
}	t_complex;

typedef struct window_control
{
	int		mouse_x;
	int		mouse_y;
	int		start_x;
	int		start_y;
	int		move_x;
	int		move_y;
	double	zoom;
}	t_win_params;

typedef struct mastermind
{
	t_complex		cmplx;
	t_win_params	win_params;
	char			fractal;
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_add;
	int				bits_pxl;
	int				line_sz;
	int				endian;
	int				clr_method;
	unsigned int	color;
}		t_controller;

int				hook_close_window(t_controller *ctrl);
int				key_hooking(int keycode, t_controller *ctrl);
int				mouse_hooking(int keycode, int x, int y, t_controller *ctrl);
int				mandel_mandel(double cr, double ci, int iters);
int				mandel_tri(double cr, double ci, int iters);
int				mandel_fail(double cr, double ci, int iters);
unsigned int	color_shift(unsigned int color, int iter);
unsigned int	color_and(unsigned int color, int iter);
unsigned int	color_or(unsigned int color, int iter);
unsigned int	color_or_pow(unsigned int color, int iter);
void			entry_message(void);
void			define_start_vals(t_controller *ctrl, int argc, char **argv);
void			validate_julia_params(char *str);
void			handle_color(t_controller *ctrl, int iter, int x, int y);
void			mandel_starter(t_controller *ctrl);
void			julia_start(t_controller *ctrl);
void			scale_complex_julia(t_controller *ctrl, int x, int y);
void			scale_complex_mandel(t_controller *ctrl, int x, int y);
void			change_fractal(t_controller *ctrl);
void			zoom_handle(t_controller *ctrl, int key);
void			reset_all(t_controller *ctrl);

#endif
