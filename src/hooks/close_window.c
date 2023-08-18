/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:32:36 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:32:37 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	hook_close_window(t_controller *ctrl)
{
	mlx_destroy_image(ctrl->mlx, ctrl->img);
	mlx_destroy_window(ctrl->mlx, ctrl->win);
	mlx_loop_end(ctrl->mlx);
	mlx_destroy_display(ctrl->mlx);
	free(ctrl->mlx);
	free(ctrl);
	exit(0);
}
