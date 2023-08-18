/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:02:17 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/01 22:02:18 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_entry_vals(int argc, char **argv)
{
	if (argc == 1)
		entry_message();
	else if (!(ft_strncmp(argv[1], "Julia", 5)))
	{
		if (argc > 4 || argc == 3)
			entry_message();
		else if (argc == 4)
		{
			validate_julia_params(argv[2]);
			validate_julia_params(argv[3]);
		}
	}
	else if (!(ft_strncmp(argv[1], "Mandelbrot", 10)) || \
		!(ft_strncmp(argv[1], "Tricorn", 7)) || \
		!(ft_strncmp(argv[1], "Failbrot", 8)))
	{
		if (argc != 2)
			entry_message();
	}
	else
		entry_message();
}

t_controller	*init_ctrl(int argc, char **argv)
{
	t_controller	*ctrl;

	ctrl = (t_controller *) malloc(sizeof(t_controller));
	ctrl->mlx = mlx_init();
	ctrl->win = mlx_new_window((*ctrl).mlx, WIDTH,
			HEIGHT, "fract-ol");
	ctrl->img = mlx_new_image(ctrl->mlx,
			WIDTH, HEIGHT);
	ctrl->img_add = mlx_get_data_addr(ctrl->img, &ctrl->bits_pxl,
			&ctrl->line_sz, &ctrl->endian);
	define_start_vals(ctrl, argc, argv);
	return (ctrl);
}

int	main(int argc, char **argv)
{
	t_controller	*ctrl;

	check_entry_vals(argc, argv);
	ctrl = init_ctrl(argc, argv);
	mlx_key_hook(ctrl->win, key_hooking, ctrl);
	mlx_mouse_hook(ctrl->win, mouse_hooking, ctrl);
	mlx_hook(ctrl->win, 17, 1L << 17, hook_close_window, ctrl);
	if (ctrl->fractal == 'j')
		julia_start(ctrl);
	else
		mandel_starter(ctrl);
	mlx_loop(ctrl->mlx);
}
