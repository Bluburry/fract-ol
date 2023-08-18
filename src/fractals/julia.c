/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:05 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:30:07 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	julia_calc(t_controller *ctrl, int x, int y)
{
	double	a;
	double	b;
	double	temp;
	int		i;

	scale_complex_julia(ctrl, x, y);
	i = 0;
	a = 0;
	b = 0;
	a = ctrl->cmplx.cr;
	b = ctrl->cmplx.ci;
	while (++i < ITERATIONS && (a * a + b * b) < 9)
	{
		temp = a * a - b * b + ctrl->cmplx.julia_r;
		b = 2 * a * b + ctrl->cmplx.julia_i;
		a = temp;
	}
	return (i);
}

void	julia_start(t_controller *ctrl)
{
	int	x;
	int	y;

	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= HEIGHT)
		{
			handle_color(ctrl, julia_calc(ctrl, x, y), x, y);
		}
	}
	mlx_put_image_to_window(ctrl->mlx, ctrl->win,
		ctrl->img, 0, 0);
}
