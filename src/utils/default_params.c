/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:33:00 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:33:01 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

double	parse_julia_params(char *str)
{
	double	val;
	int		iter;
	int		negative;
	int		i;

	i = 0;
	val = 0;
	negative = 1;
	iter = 1;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		val *= 10;
		val += str[i] - 48;
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (str[i])
		val += (str[i++] - 48) / pow(10, iter++);
	return (val * negative);
}

void	start_julia(t_controller *ctrl, int argc, char **argv)
{
	ctrl->clr_method = 3;
	ctrl->color = INDIGO;
	if (argc != 2)
	{
		ctrl->cmplx.julia_r = parse_julia_params(argv[2]);
		ctrl->cmplx.julia_i = parse_julia_params(argv[3]);
	}
}

void	start_mandels(t_controller *ctrl)
{
	if (ctrl->fractal == 't')
	{
		ctrl->win_params.zoom = 0.6;
		ctrl->win_params.start_x = 550;
	}
}

void	define_start_vals(t_controller *ctrl, int argc, char **argv)
{
	ctrl->win_params.move_x = 0;
	ctrl->win_params.move_y = 0;
	ctrl->win_params.start_x = 0;
	ctrl->win_params.start_y = 0;
	ctrl->win_params.zoom = 1;
	ctrl->cmplx.lower_limit_real = MANDEL_REAL_LOWER_LIMIT;
	ctrl->cmplx.upper_limit_real = MANDEL_REAL_UPPER_LIMIT;
	ctrl->cmplx.lower_limit_imag = MANDEL_IMAGINARY_LOWER_LIMIT;
	ctrl->cmplx.upper_limit_imag = MANDEL_IMAGINARY_UPPER_LIMIT;
	ctrl->cmplx.julia_r = DEFAULT_JULIA_REAL;
	ctrl->cmplx.julia_i = DEFAULT_JULIA_IMAGINARY;
	ctrl->cmplx.radius = 2;
	ctrl->clr_method = 0;
	ctrl->color = MISC1;
	ctrl->fractal = argv[1][0] + 32;
	if (argv[1][0] == 'M' || argv[1][0] == 'T' || argv[1][0] == 'F')
		start_mandels(ctrl);
	else if (argv[1][0] == 'J')
		start_julia(ctrl, argc, argv);
}
