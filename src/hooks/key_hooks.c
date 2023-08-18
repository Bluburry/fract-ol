/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:32:30 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:35:03 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	alter_fractal(t_controller *ctrl, int key)
{
	if (ctrl->img != NULL)
		mlx_destroy_image(ctrl->mlx, ctrl->img);
	ctrl->img = mlx_new_image(ctrl->mlx, WIDTH, HEIGHT);
	ctrl->img_add = mlx_get_data_addr(ctrl->img, \
		&ctrl->bits_pxl, &ctrl->line_sz, &ctrl->endian);
	if (key == M_KEY)
		ctrl->fractal = 'm';
	else if (key == T_KEY)
		ctrl->fractal = 't';
	else if (key == F_KEY)
		ctrl->fractal = 'f';
	else if (key == J_KEY)
		ctrl->fractal = 'j';
	change_fractal(ctrl);
}

void	change_color_scheme(t_controller *ctrl, int key)
{
	if (ctrl->img != NULL)
		mlx_destroy_image(ctrl->mlx, ctrl->img);
	ctrl->img = mlx_new_image(ctrl->mlx, WIDTH, HEIGHT);
	ctrl->img_add = mlx_get_data_addr(ctrl->img, \
		&ctrl->bits_pxl, &ctrl->line_sz, &ctrl->endian);
	if (key == PLUS)
		ctrl->clr_method++;
	else if (key == MINUS)
		ctrl->clr_method--;
	if (ctrl->clr_method < 0)
		ctrl->clr_method = 10;
	else if (ctrl->clr_method > 10)
		ctrl->clr_method = 0;
	change_fractal(ctrl);
}

void	move_image(t_controller *ctrl, int key)
{
	if (ctrl->img != NULL)
		mlx_destroy_image(ctrl->mlx, ctrl->img);
	ctrl->img = mlx_new_image(ctrl->mlx, WIDTH, HEIGHT);
	ctrl->img_add = mlx_get_data_addr(ctrl->img, \
		&ctrl->bits_pxl, &ctrl->line_sz, &ctrl->endian);
	if (key == LEFT_ARROW)
		ctrl->win_params.move_x -= 90;
	else if (key == RIGHT_ARROW)
		ctrl->win_params.move_x += 90;
	else if (key == UP_ARROW)
		ctrl->win_params.move_y -= 90;
	else if (key == DOWN_ARROW)
		ctrl->win_params.move_y += 90;
	change_fractal(ctrl);
}

int	key_hooking(int key, t_controller *ctrl)
{
	if (key == ESC)
		hook_close_window(ctrl);
	else if (key == M_KEY || key == J_KEY || \
		key == T_KEY || key == F_KEY)
		alter_fractal(ctrl, key);
	else if (key == MINUS || key == PLUS)
		change_color_scheme(ctrl, key);
	else if (key == LEFT_ARROW || key == RIGHT_ARROW || \
		key == UP_ARROW || key == DOWN_ARROW)
		move_image(ctrl, key);
	else if (key == R_KEY)
		reset_all(ctrl);
	return (0);
}
