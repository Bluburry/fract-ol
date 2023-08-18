/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:29:45 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:29:47 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	mandel_mandel(double cr, double ci, int iters)
{
	double	a;
	double	b;
	double	temp;
	int		i;

	i = -1;
	a = 0;
	b = 0;
	while (++i < iters && (a * a + b * b) <= 4)
	{
		temp = a * a - b * b + cr;
		b = 2 * a * b + ci;
		a = temp;
	}
	return (i);
}

int	mandel_tri(double cr, double ci, int iters)
{
	double	a;
	double	b;
	double	temp;
	int		i;

	i = -1;
	a = 0;
	b = 0;
	while (++i < iters && (a * a + b * b) <= 4)
	{
		temp = a * a - b * b + cr;
		b = - (2 * a * b) + ci;
		a = temp;
	}
	return (i);
}

int	mandel_fail(double cr, double ci, int iters)
{
	double	a;
	double	b;
	double	temp;
	int		i;

	i = -1;
	a = 0;
	b = 0;
	while (++i < iters && (a * a + b * b) <= 4)
	{
		temp = a * a - b * b + cr;
		b = a * b + ci;
		a = temp;
	}
	return (i);
}
