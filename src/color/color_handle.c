/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:31:46 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:31:48 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

unsigned int	option_mix(unsigned int color, int iter, int op)
{
	unsigned int	clr;

	clr = color_shift(color, iter);
	if (op == 4)
		return (color_and(clr, iter) * iter);
	else if (op == 5)
		return (color_or(clr, iter) * iter);
	else if (op == 6)
		return (color_or_pow(clr, iter) * iter);
	else if (op == 7)
		clr = color_and(color, iter);
	else if (op == 8)
		clr = color_or(color, iter);
	else if (op == 9)
		clr = color_or_pow(color, iter);
	else
		return (color * iter);
	return (color_shift(clr, iter) * iter);
}

void	handle_color(t_controller *ctrl, int iter, int x, int y)
{
	char			*pxl;
	unsigned int	clr;

	pxl = ctrl->img_add + (y * ctrl->line_sz + x * (ctrl->bits_pxl / 8));
	if (iter >= ITERATIONS)
	{
		*(unsigned int *)pxl = BLACK;
		return ;
	}
	if (ctrl->clr_method == 0)
		clr = color_shift(ctrl->color, iter);
	else if (ctrl->clr_method == 1)
		clr = color_and(ctrl->color, iter);
	else if (ctrl->clr_method == 2)
		clr = color_or(ctrl->color, iter);
	else if (ctrl->clr_method == 3)
		clr = color_or_pow(ctrl->color, iter);
	else
		clr = option_mix(ctrl->color, iter, ctrl->clr_method);
	*(unsigned int *)pxl = clr;
}
