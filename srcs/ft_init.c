/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:53:41 by uolle             #+#    #+#             */
/*   Updated: 2024/01/16 23:54:08 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Initialize Julia fractal
 *
 * @param t_mlx *fract - Struct containing all the data
 * @return void
 */
void ft_init_julia(t_mlx *fract) {
  fract->x_start = -1.0;
  fract->y_start = -1.0;
  fract->x_end = 3.0;
  fract->y_end = 3.0;
  fract->zoom = 1;
  fract->max_iter = 50;
  fract->c_r = 0.4;
  fract->c_i = 0.4;
  fract->color = 0x000000;
}

/**
 * @brief Function to initialize the mlx
 *
 * @param t_mlx *fract - Struct containing all the data
 * @return void
 */
void ft_init_mlx(t_mlx *fract) {
  fract->mlx = mlx_init();
  if (!fract->mlx)
    ft_exit(fract, 1);
  fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->title);
  if (!fract->win)
    ft_exit(fract, 1);
  fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
  if (!fract->img)
    ft_exit(fract, 1);
  fract->data = mlx_get_data_addr(fract->img, &fract->bpp, &fract->size_line,
                                  &fract->endian);
}
