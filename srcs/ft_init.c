/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:53:41 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 16:39:23 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Function to initialize the mlx
 *
 * @param t_mlx *fract - Struct containing all the data
 * @return void
 */
static void	ft_init_mlx(t_mlx *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		ft_exit(fract, "[ERROR] - Failed to initialize mlx");
	fract->win = mlx_new_window(fract->mlx, HEIGHT, WIDTH, fract->title);
	if (!fract->win)
		ft_exit(fract, "[ERROR] - Failed to create window");
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img)
		ft_exit(fract, "[ERROR] - Failed to create image");
	fract->data = mlx_get_data_addr(fract->img, &fract->bpp, &fract->size_line,
			&fract->endian);
}

/**
 * @brief Initialize the fractal data.
 *
 * @param fract t_mlx Fractal struct.
 * @return void
 */
void	ft_init_fractol(t_mlx *fract)
{
	fract->max_iter = 100;
	ft_init_mlx(fract);
}
