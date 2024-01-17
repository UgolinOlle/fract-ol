/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:50:18 by uolle             #+#    #+#             */
/*   Updated: 2024/01/16 23:24:37 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Calculate the number of iterations for each pixel.
 *
 * @param x int X coordinate.
 * @param y int Y coordinate.
 * @param fract t_mlx Fractal struct.
 * @return int Number of iterations.
 */
static int ft_julia_iter(int x, int y, t_mlx *fract) {
  double tmp;
  double z_re;
  double z_im;
  int i;

  z_re = fract->x1 + x * (fract->x1 - fract->x) / WIDTH;
  z_im = fract->y1 + y * (fract->y1 - fract->y) / HEIGHT;
  i = 0;
  while (z_re * z_re + z_im * z_im < 4 && i < fract->max_iter) {
    tmp = z_re;
    z_re = z_re * z_re - z_im * z_im + fract->c_r;
    z_im = 2 * tmp * z_im + fract->c_i;
    i++;
  }
  return (i);
}

/**
 * @brief Put pixel to image.
 *
 * @param fract t_mlx Fractal struct.
 * @param x int X coordinate.
 * @param y int Y coordinate.
 * @param color int Color.
 */
void ft_put_pixel_to_img(t_mlx *fract, int x, int y, int color) {
  char *pixel;

  pixel = fract->data + (y * fract->size_line + x * (fract->bpp / 8));
  *(unsigned int *)pixel = color;
}

/**
 * @brief Get color.
 *
 * @param i int Number of iterations.
 * @param fract t_mlx Fractal struct.
 * @return int Color.
 */
static int ft_get_color(int i, t_mlx *fract) {
  int color;

  color = 0x000000;
  if (i < fract->max_iter)
    color = fract->color * i;
  return (color);
}

/**
 * @brief Draw the Julia fractal.
 *
 * @param fract t_mlx Fractal struct.
 */
void ft_julia(t_mlx *fract) {
  int x;
  int y;
  int i;

  y = 0;
  while (y < HEIGHT) {
    x = 0;
    while (x < WIDTH) {
      i = ft_julia_iter(x, y, fract);
      if (i == fract->max_iter)
        ft_put_pixel_to_img(fract, x, y, 0x000000);
      else
        ft_put_pixel_to_img(fract, x, y, ft_get_color(i, fract));
      x++;
    }
    y++;
  }
}
