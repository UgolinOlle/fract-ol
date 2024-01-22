/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:54:05 by uolle             #+#    #+#             */
/*   Updated: 2024/01/22 21:34:47 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Calculate Julia iteration.
 *
 * @param t_mlx *fract - Fractal struct.
 * @param t_complex z - Complex number.
 * @param double c_i - Imaginary part of complex number.
 * @param double c_r - Real part of complex number.
 * @return int
 */
static int ft_julia_iteration(t_mlx *fract, t_complex *c, double c_r,
                              double c_i) {
  double z_r;
  double z_i;
  int i;
  t_complex z_n;

  z_r = c->re;
  z_i = c->im;
  i = 0;
  while (i < fract->max_iter) {
    z_n.re = z_r * z_r - z_i * z_i + c_r;
    z_n.im = 2 * z_r * z_i + c_i;
    z_r = z_n.re;
    z_i = z_n.im;
    if (z_r * z_r + z_i * z_i > 4)
      return (i);
    i++;
  }
  return (fract->max_iter);
}

/**
 * @brief Initialize Julia fractal.
 *
 * @param fract t_mlx - Fractal struct.
 * @param char *argv - Set type of Julia.
 * @return void
 */
void ft_init_julia(t_mlx *fract, int set) {
  fract->min.re = -2.0;
  fract->max.re = 2.0;
  fract->min.im = -1.5;
  fract->max.im = 1.5;
  fract->rgb.b = 50;
  fract->rgb.g = 50;
  fract->rgb.r = 50;
  if (set == 1) {
    fract->julia.re = -0.4;
    fract->julia.im = 0.6;
  } else if (set == 2) {
    fract->julia.re = -0.8;
    fract->julia.im = 0.156;
  } else if (set == 3) {
    fract->julia.re = -0.835;
    fract->julia.im = -0.2321;
  }
  ft_print_fractol(fract);
}

/**
 * @brief Create Julia fractal.
 *
 * @param fract t_mlx - Fractal struct.
 * @return void
 */
void ft_julia(t_mlx *fract) {
  int x;
  int y;
  t_complex c;
  char *addr;

  mlx_clear_window(fract->mlx, fract->win);
  y = -1;
  while (++y < HEIGHT) {
    x = -1;
    while (++x < WIDTH) {
      c.re =
          fract->min.re + (fract->max.re - fract->min.re) * x / (WIDTH - 1.0);
      c.im =
          fract->min.im + (fract->max.im - fract->min.im) * y / (HEIGHT - 1.0);
      fract->iter =
          ft_julia_iteration(fract, &c, fract->julia.re, fract->julia.im);
      if (fract->iter == fract->max_iter) {
        fract->color = ft_create_trgb(fract->rgb, 1);
      } else {
        fract->color = ft_create_trgb(fract->rgb, 1) * fract->iter;
      }
      addr = fract->data + (y * fract->size_line + x * (fract->bpp / 8));
      *(unsigned int *)addr = fract->color;
    }
  }
  mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
