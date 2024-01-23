/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:13:23 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 15:43:58 by uolle            ###   ########.fr       */
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
  if (!ft_strcmp(content, ""))
    exit(EXIT_SUCCESS);
  else {
    ft_putstr_fd(content, STDERR_FILENO);
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief MLX Exit
 *
 * @param fract t_mlx - Fractal struct.
 * @return int
 */
int ft_mlx_exit(t_mlx *fract) {
  ft_exit(fract, "");
  return (0);
}

/**
 * @brief Create TRGB color.
 *
 * @param t_color color - Color struct.
 * @return int
 */
int ft_create_rgb(t_color rgb, t_mlx *fract) {
  if (fract->iter == fract->max_iter)
    return (0x000000);
  else {
    rgb.r = (fract->iter * 9) % 255;
    rgb.g = (fract->iter * 3) % 255;
    rgb.b = (fract->iter * 4) % 255;
    return (rgb.r << 16 | rgb.g << 8 | rgb.b);
  }
}

/**
 * @brief Draw pixel.
 *
 * @param fract t_mlx - Fractal struct.
 * @param x int - X coordinate.
 * @param y int - Y coordinate.
 * @param color int - Color.
 * @return void
 */
void ft_draw_pixel(t_mlx *fract, int x, int y, int color) {
  char *dst;

  dst = fract->data + (y * fract->size_line + x * (fract->bpp / 8));
  *(unsigned int *)dst = color;
}

/**
 * @brief Shift color.
 *
 * @param fract t_mlx - Fractal struct.
 * @return void
 */
void ft_color_shift(t_color *rgb) {
  rgb->r += 30;
  rgb->g += 30;
  rgb->b += 30;
}

/**
 * @brief Print all elements from fractol struct.
 *
 * @param fract t_mlx - Fractal struct.
 * @return void
 */
void ft_print_fractol(t_mlx *fract) {
  printf("title: %s\n", fract->title);
  printf("min.re: %f\n", fract->min.re);
  printf("max.re: %f\n", fract->max.re);
  printf("min.im: %f\n", fract->min.im);
  printf("max.im: %f\n", fract->max.im);
  printf("julia.re: %f\n", fract->julia.re);
  printf("julia.im: %f\n", fract->julia.im);
  printf("color.r: %d\n", fract->rgb.r);
  printf("color.g: %d\n", fract->rgb.g);
  printf("color.b: %d\n", fract->rgb.b);
  printf("max_iter: %d\n", fract->max_iter);
  printf("bpp: %d\n", fract->bpp);
  printf("size_line: %d\n", fract->size_line);
  printf("endian: %d\n", fract->endian);
}
