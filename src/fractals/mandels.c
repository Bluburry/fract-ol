/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandels.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:29:30 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:29:33 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	mandel_calc(t_controller *ctrl, int x, int y)
{
	scale_complex_mandel(ctrl, x, y);
	if (ctrl->fractal == 'm')
		return (mandel_mandel(ctrl->cmplx.cr, ctrl->cmplx.ci, ITERATIONS));
	else if (ctrl->fractal == 't')
		return (mandel_tri(ctrl->cmplx.cr, ctrl->cmplx.ci, ITERATIONS));
	else if (ctrl->fractal == 'f')
		return (mandel_fail(ctrl->cmplx.cr, ctrl->cmplx.ci, ITERATIONS));
	else
	{
		ft_printf("error in fractal selection.\n");
		hook_close_window(ctrl);
		return (0);
	}
}

void	mandel_starter(t_controller *ctrl)
{
	int	x;
	int	y;

	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= HEIGHT)
		{
			handle_color(ctrl, mandel_calc(ctrl, x, y), x, y);
		}
	}
	mlx_put_image_to_window(ctrl->mlx, ctrl->win,
		ctrl->img, 0, 0);
}

/*
	Z = a + b*i
	Mandelbrot function: Z(n+1) = Z(n)^2 + c
	Z(n)^2 = (a + b*i)^2 = a^2 + 2abi + (bi)^2
		= a^2 + b^2 * (sqr(-1)^2) + 2abi
		= a^2 - b^2 + abi
	Dividing between real and imaginary and adding C (Z(n+1))
	Zr = a^2 + b^2 + cr
	Zi = 2ab + ci
	n => iteration

	c -> pixel coordinate
	c = x + y*i
	
	at every iteration a complex modulus 
is also calculated
	|Z(n+1)| = sqr(x^2 + y^2)
	stopping if the above is ever > 2
	(will be using for, so I can avoid doing sqr)
	
	the iteration (n) is then used to define 
the color to be used for that pixel
	using a max interation value we can find
which pixels are within the mandelbrot fractal

*/
