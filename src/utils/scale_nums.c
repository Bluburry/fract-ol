/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:33:10 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:33:11 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	scale_complex_julia(t_controller *ctrl, int x, int y)
{
	ctrl->cmplx.cr = (((x * (ctrl->cmplx.radius * 2) + \
		ctrl->win_params.move_x + ctrl->win_params.start_x) / WIDTH) - \
		ctrl->cmplx.radius) / ctrl->win_params.zoom;
	ctrl->cmplx.ci = (((y * (ctrl->cmplx.radius * 2) + \
		ctrl->win_params.move_y + ctrl->win_params.start_y) / WIDTH) - \
		ctrl->cmplx.radius) / ctrl->win_params.zoom;
}

void	scale_complex_mandel(t_controller *ctrl, int x, int y)
{
	ctrl->cmplx.cr = (((x * (ctrl->cmplx.upper_limit_real - \
		ctrl->cmplx.lower_limit_real) + ctrl->win_params.move_x + \
		ctrl->win_params.start_x) / WIDTH) + ctrl->cmplx.lower_limit_real) \
		/ ctrl->win_params.zoom;
	ctrl->cmplx.ci = (((y * (ctrl->cmplx.upper_limit_imag - \
		ctrl->cmplx.lower_limit_imag) + ctrl->win_params.move_y + \
		ctrl->win_params.start_y) / HEIGHT) + ctrl->cmplx.lower_limit_imag) \
		/ ctrl->win_params.zoom;
}

/* 
	to get to these calculations I used two sets of rule of 3

	(using x and width as an example, the same calculations apply to y)
	the first one turns the value of x into a percentage of 
where it places in the scale from 0 to max width (just the width value)
	
	100% -> width
	p_x -> x
	p_x = (x * 100) / width


	then I do the same thing to find where the percentage value of x (p_x)
fits into the scale of the complex value for the given fractal
	(using mandelbrot as an example, the real part of c
	has to be between [-2.00; 0.47])
	since the scale isn't perfect (doesn't start from 0, and may
	have negative values) I chose to subtract the limits
	and create a new range from that
	=> [0; (upper_limit - lower_limit)]
(lm = upper_limit - lower_limit)

	lm -> 100
	c_x -> p_x

	c_x = (p_x * lm) / 100


	which means:
	c_x = ((x * 100) / width) * lm / 100

	which simplified comes out to
	c_x = (x * lm) / width
	

	then adding the lower limit so it fits into
the [lower_limit; upper_limit] scale instead of [0; lm]
	c_x = ((x * (upper_limit - lower_limit)) / width) + lower_limit
	and
	c_x = ((y * (upper_limit - lower_limit)) / height) + lower_limit
	
	but this doesn't account for movement or zoom
	for that I added them to the equation as such:
	c_x = (((x * (upper_limit - lower_limit) + mov_x)
		/ width) + lower_limit) / zoom
	c_x = (((y * (upper_limit - lower_limit) + mov_y)
		/ height) + lower_limit) / zoom

	this method however only works for square displays
	for now that restriction is enforced,
	as the subject doesn't ask for various resolutions to be handled
 */
