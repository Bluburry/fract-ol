/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:31:38 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:31:39 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

unsigned int	color_shift(unsigned int color, int iter)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	if ((iter % 3) == 1)
		return (b << 16 | r << 8 | g);
	else if ((iter % 3) == 2)
		return (g << 16 | b << 8 | r);
	else
		return (color);
}

unsigned int	color_and(unsigned int color, int iter)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	i;

	i = pow(iter, 4);
	r = (color >> 16) & 0xff & i;
	g = (color >> 8) & 0xff & i;
	b = color & 0xff & i;
	return (r << 16 | g << 8 | b);
}

unsigned int	color_or(unsigned int color, int iter)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = ((color >> 16) & 0xff) | iter;
	g = ((color >> 8) & 0xff) | iter;
	b = (color & 0xff) | iter;
	return (r << 16 | g << 8 | b);
}

unsigned int	color_or_pow(unsigned int color, int iter)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	i;

	i = pow(iter, 4);
	r = ((color >> 16) & 0xff) | i;
	g = ((color >> 8) & 0xff) | i;
	b = (color & 0xff) | i;
	return (r << 16 | g << 8 | b);
}
