/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:32:03 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:35:30 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	zoom_handle(t_controller *ctrl, int key)
{
	if (ctrl->img != NULL)
		mlx_destroy_image(ctrl->mlx, ctrl->img);
	ctrl->img = mlx_new_image(ctrl->mlx, WIDTH, HEIGHT);
	ctrl->img_add = mlx_get_data_addr(ctrl->img, \
		&ctrl->bits_pxl, &ctrl->line_sz, &ctrl->endian);
	if (key == ZOOM_IN)
		ctrl->win_params.zoom *= 1.1;
	else if (key == ZOOM_OUT)
		ctrl->win_params.zoom /= 1.1;
	change_fractal(ctrl);
}

int	mouse_hooking(int key, int x, int y, t_controller *ctrl)
{
	ctrl->win_params.mouse_x = x;
	ctrl->win_params.mouse_y = y;
	if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom_handle(ctrl, key);
	return (0);
}
