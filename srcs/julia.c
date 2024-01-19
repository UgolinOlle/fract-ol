/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:09:12 by uolle             #+#    #+#             */
/*   Updated: 2024/01/19 14:20:27 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Function to put pixel to the image
 *
 * @param t_mlx *fract - Struct containing all the data
 * @param int x - x coordinate
 * @param int y - y coordinate
 * @param int color - color of the pixel
 * @return void
 */
void ft_draw_pixel(t_mlx *fract, int x, int y, int color) {
  char *pixel = fract->data + (y * fract->size_line + x * (fract->bpp / 8));
  *(unsigned int *)pixel = color;
}

/**
 * @brief Calculate Julia fractal
 *
 * @param t_mlx *fract - Struct containing all the data
 * @return void
 */
static int ft_julia_iteration(t_mlx *fract) {
  fract->z_r = fract->x / fract->zoom + fract->x_start;
  fract->z_i = fract->y / fract->zoom + fract->y_start;
  fract->iter = 0;
  while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4 &&
         fract->iter < fract->max_iter) {
    fract->tmp = fract->z_r;
    fract->z_r = fract->z_r * fract->z_r - fract->z_i * fract->z_i - 0.8 +
                 (fract->c_r / WIDTH);
    fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i / WIDTH;
    fract->iter++;
  }
  if (fract->iter == fract->max_iter)
    return (0x000000);
  else
    return (0xFFFFFF);
}

/**
 * @brief Function to draw the Julia fractal
 *
 * @param t_mlx *fract - Struct containing all the data
 * @return void
 */
void ft_julia(t_mlx *fract) {
  int xpixel;
  int ypixel;

  xpixel = 0;
  while (xpixel < WIDTH) {
    fract->x =
        fract->x_start + (fract->x_end - fract->x_start) / (WIDTH - 1) * xpixel;
    ypixel = 0;
    while (ypixel < HEIGHT) {
      fract->y = fract->y_end +
                 (fract->y_start - fract->y_end) / (HEIGHT - 1) * ypixel;
      fract->color = ft_julia_iteration(fract);
      ft_draw_pixel(fract, xpixel, ypixel, fract->color);
      ypixel++;
    }
    xpixel++;
  }
  mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
