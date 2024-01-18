/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:55:39 by uolle             #+#    #+#             */
/*   Updated: 2024/01/17 23:06:35 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Handle zoom and dezoom
 *
 * @param type int type of zoom (1 for zoom, 2 for dezoom)
 * @param x int x coordinate of mouse
 * @param y int y coordinate of mouse
 * @param f t_mlx fractal struct
 * @return void
 */
static void ft_zoom(int type, int x, int y, t_mlx *fract) {
  if (type == 1) {
    fract->x1 = fract->x1 + (x - WIDTH / 2) * fract->zoom / WIDTH;
    fract->y1 = fract->y1 + (y - HEIGHT / 2) * fract->zoom / HEIGHT;
    fract->zoom *= 0.9;
  } else if (type == 2) {
    fract->x1 = fract->x1 - (x - WIDTH / 2) * fract->zoom / WIDTH;
    fract->y1 = fract->y1 - (y - HEIGHT / 2) * fract->zoom / HEIGHT;
    fract->zoom /= 0.9;
  } else
    return;
}

/**
 * @brief Handle mouse events
 *
 * @param button int mouse button
 * @param x int x coordinate of mouse
 * @param y int y coordinate of mouse
 * @param fract t_mlx fractal struct
 * @return int
 */
int ft_handle_mouse(int button, int x, int y, t_mlx *fract) {
  if (button == 4 || button == 1)
    ft_zoom(1, x, y, fract);
  else if (button == 5)
    ft_zoom(2, x, y, fract);
  ft_menu(fract);
  mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
  return (0);
}
