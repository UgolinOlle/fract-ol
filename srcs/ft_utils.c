/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:13:23 by uolle             #+#    #+#             */
/*   Updated: 2024/01/17 23:31:11 by uolle            ###   ########.fr       */
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
void ft_draw_pixel(t_mlx *fract, int x, int y, int color) {
  if (fract->x < WIDTH && fract->y < HEIGHT) {
    color = mlx_get_color_value(fract->mlx, color);
    ft_memcpy(fract->data + 4 * WIDTH * y + x * 4, &color, sizeof(int));
  }
}

/**
 * @brief Handle errors.
 *
 * @param error char* Error message.
 * @param type int Type of error.
 */
int ft_exit(t_mlx *fract, int type) {
  if (type == 0) {
    mlx_destroy_image(fract->mlx, fract->img);
    mlx_destroy_window(fract->mlx, fract->win);
    fract->win = NULL;
    ft_putstr_fd("[INFO] - Exiting program.\n", STDOUT_FILENO);
  } else if (type == 1) {
    if (fract->win)
      mlx_destroy_window(fract->mlx, fract->win);
    if (fract->img)
      mlx_destroy_image(fract->mlx, fract->img);
    if (fract->mlx)
      free(fract->mlx);
  }
  exit(EXIT_SUCCESS);
  return (0);
}
