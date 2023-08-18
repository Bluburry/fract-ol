/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:32:55 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:32:56 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	change_fractal(t_controller *ctrl)
{
	ctrl->win_params.start_x = 0;
	ctrl->win_params.start_y = 0;
	if (ctrl->fractal == 'm' || ctrl->fractal == 'f')
		mandel_starter(ctrl);
	else if (ctrl->fractal == 't')
	{
		if (ctrl->win_params.zoom == 1)
			ctrl->win_params.zoom = 0.6;
		ctrl->win_params.start_x = 550;
		mandel_starter(ctrl);
	}
	else if (ctrl->fractal == 'j')
	{
		ctrl->fractal = 'j';
		julia_start(ctrl);
	}
}

void	reset_all(t_controller *ctrl)
{
	if (ctrl->img != NULL)
		mlx_destroy_image(ctrl->mlx, ctrl->img);
	ctrl->img = mlx_new_image(ctrl->mlx, WIDTH, HEIGHT);
	ctrl->img_add = mlx_get_data_addr(ctrl->img, \
		&ctrl->bits_pxl, &ctrl->line_sz, &ctrl->endian);
	ctrl->win_params.move_x = 0;
	ctrl->win_params.move_y = 0;
	ctrl->win_params.start_x = 0;
	ctrl->win_params.start_y = 0;
	ctrl->win_params.zoom = 1;
	ctrl->clr_method = 0;
	ctrl->fractal = 'm';
	ctrl->color = MISC1;
	change_fractal(ctrl);
}
