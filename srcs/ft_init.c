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

static void ft_init_fractal(t_mlx *fract) {
  fract->mlx = NULL;
  fract->win = NULL;
  fract->iter = 0;
  fract->max_iter = 50;
  fract->data = NULL;
  fract->img = NULL;
  fract->bpp = 0;
  fract->size_line = 0;
  fract->endian = 0;
  fract->color = 265;
  fract->zoom = 1;
  fract->x = 0;
  fract->y = 0;
  fract->x1 = 0;
  fract->y1 = 0;
  fract->c_r = 0;
  fract->c_i = 0;
  fract->z_r = 0;
  fract->z_i = 0;
  fract->tmp = 0;
}

void ft_init_mlx(t_mlx *fract) {
  ft_init_fractal(fract);
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
