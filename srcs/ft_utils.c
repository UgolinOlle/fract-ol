/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:13:23 by uolle             #+#    #+#             */
/*   Updated: 2024/01/16 23:52:08 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void ft_draw_pixel(t_mlx *fract, int x, int y, int color) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    color = mlx_get_color_value(fract->mlx, color);
    ft_memcpy(fract->data + 4 * WIDTH * y + x * 4, &color, sizeof(int));
  }
}

void ft_exit(t_mlx *fract, int type) {
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
}
