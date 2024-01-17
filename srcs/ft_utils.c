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

/**
 * @brief Calculate the number of iterations for each pixel.
 *
 * @param x int X coordinate.
 * @param y int Y coordinate.
 * @param fract t_mlx Fractal struct.
 * @return int Number of iterations.
 */
void ft_draw_pixel(t_mlx *fract, int x, int y, int color) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
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

/**
 * @brief Print all element in the fractal struct.
 *
 * @param fract t_mlx Fractal struct.
 */
void ft_print_mlx(t_mlx *fract) {
  ft_putstr_fd("mlx: ", STDOUT_FILENO);
  ft_putendl_fd(fract->mlx, STDOUT_FILENO);
  ft_putstr_fd("win: ", STDOUT_FILENO);
  ft_putendl_fd(fract->win, STDOUT_FILENO);
  ft_putstr_fd("img: ", STDOUT_FILENO);
  ft_putendl_fd(fract->img, STDOUT_FILENO);
  ft_putstr_fd("data: ", STDOUT_FILENO);
  ft_putendl_fd(fract->data, STDOUT_FILENO);
  ft_putstr_fd("bpp: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->bpp, STDOUT_FILENO);
  ft_putstr_fd("\nsize_line: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->size_line, STDOUT_FILENO);
  ft_putstr_fd("\nendian: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->endian, STDOUT_FILENO);
  ft_putstr_fd("\nx: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->x, STDOUT_FILENO);
  ft_putstr_fd("\ny: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->y, STDOUT_FILENO);
  ft_putstr_fd("\nx1: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->x1, STDOUT_FILENO);
  ft_putstr_fd("\ny1: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->y1, STDOUT_FILENO);
  ft_putstr_fd("\nc_r: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->c_r, STDOUT_FILENO);
  ft_putstr_fd("\nc_i: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->c_i, STDOUT_FILENO);
  ft_putstr_fd("\nmax_iter: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->max_iter, STDOUT_FILENO);
  ft_putstr_fd("\nzoom: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->zoom, STDOUT_FILENO);
  ft_putstr_fd("\ncolor: ", STDOUT_FILENO);
  ft_putnbr_fd(fract->color, STDOUT_FILENO);
  ft_putstr_fd("\n", STDOUT_FILENO);
}
