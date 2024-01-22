/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:13:23 by uolle             #+#    #+#             */
/*   Updated: 2024/01/22 11:23:52 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Handle errors.
 *
 * @param error char* Error message.
 */
void ft_exit(t_mlx *fract, char *content) {
  if (fract->win)
    mlx_destroy_window(fract->mlx, fract->win);
  if (fract->img)
    mlx_destroy_image(fract->mlx, fract->img);
  if (fract->mlx)
    free(fract->mlx);
  ft_putstr_fd(content, STDERR_FILENO);
  exit(EXIT_SUCCESS);
}

/**
 * @brief Print all elements in the fractal struct.
 *
 * @param fract t_mlx Fractal struct.
 * @return void
 */
void ft_print_struct(t_mlx *fract) {
  printf("title: %s\n", fract->title);
  printf("mlx: %p\n", fract->mlx);
  printf("win: %p\n", fract->win);
  printf("img: %p\n", fract->img);
  printf("data: %p\n", fract->data);
  printf("bpp: %d\n", fract->bpp);
  printf("size_line: %d\n", fract->size_line);
  printf("endian: %d\n", fract->endian);
  printf("x: %f\n", fract->x);
  printf("y: %f\n", fract->y);
  printf("z_re: %f\n", fract->z_re);
  printf("z_im: %f\n", fract->z_im);
  printf("c_re: %f\n", fract->c_re);
  printf("c_im: %f\n", fract->c_im);
  printf("tmp: %f\n", fract->tmp);
  printf("iter: %d\n", fract->iter);
  printf("max_iter: %d\n", fract->max_iter);
  printf("zoom: %d\n", fract->zoom);
  printf("color: %d\n", fract->color);
}
