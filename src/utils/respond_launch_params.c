/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respond_launch_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:33:05 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/08/18 16:33:06 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	entry_message(void)
{
	ft_printf("This fractol program accepts the following launch arguments:");
	ft_printf("\n\t- Mandelbrot\n\t- Julia\n\t- Tricorn\n\t- Failbrot\n\n");
	ft_printf("Additionally you can define the starting real and ");
	ft_printf("imaginary values for the Julia fractal.\n");
	ft_printf("Simply pass 2 extra arguments ");
	ft_printf("the first for the real part, second for the imaginary.\n\n");
	ft_printf("Additionally, while the programm is running ");
	ft_printf("you can press various keys to alter it.\n");
	ft_printf("\n\t> + and - to shift through color schemes");
	ft_printf("\n\t> the initials of the fractals to change them (m, j, t, f)");
	ft_printf("\n\t> mouse wheel to zoom in or out");
	ft_printf("\n\t> arrow keys to move the view\n");
	exit(0);
}

void	validate_julia_params(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] != '.' && str[i] != ',')
		entry_message();
	else if (!str[i])
		return ;
	i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (i != (int) ft_strlen(str))
		entry_message();
}
