/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:11 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 16:03:03 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Calculate the tricorn iteration
 *
 * @param t_mlx *fract - Struct with all the information
 * @param t_complex *c - Struct with the complex number
 * @return int
 */
static int ft_tricorn_iteration(t_mlx *fract, t_complex *c) {
  int i;
  t_complex z;
  double tmp_re;
  double tmp_im;

  i = 0;
  z.re = 0;
  z.im = 0;
  while (i < fract->max_iter) {
    tmp_re = z.re;
    tmp_im = z.im;
    z.re = tmp_re * tmp_re - tmp_im * tmp_im + c->re;
    z.im = -2 * tmp_re * tmp_im + c->im;
    if ((z.re * z.re + z.im * z.im) > 4)
      break;
    i++;
  }
  return (i);
}

/**
 * @brief Initialize the tricorn fractal.
 *
 * @param t_mlx *fract - Struct with all the information
 * @return void
 */
void ft_init_tricorn(t_mlx *fract) {
  fract->max.re = 2;
  fract->min.re = -2;
  fract->max.im = 2;
  fract->min.im = -2;
  fract->max_iter = 50;
  fract->rgb.r = 4;
  fract->rgb.g = 4;
  fract->rgb.b = 4;
}

/**
 * @brief Create the tricorn fractal.
 *
 * @param t_mlx *fract - Struct with all the information
 * @return void
 */
void ft_tricorn(t_mlx *fract) {
  int x;
  int y;
  t_complex c;

  x = 0;
  while (x < WIDTH) {
    y = 0;
    while (y < HEIGHT) {
      c.re = fract->min.re + x * (fract->max.re - fract->min.re) / WIDTH;
      c.im = fract->min.im + y * (fract->max.im - fract->min.im) / HEIGHT;
      fract->iter = ft_tricorn_iteration(fract, &c);
      ft_draw_pixel(fract, x, y, ft_create_rgb(fract->rgb, fract));
      y++;
    }
    x++;
  }
  mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
