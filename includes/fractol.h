/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:50:27 by uolle             #+#    #+#             */
/*   Updated: 2024/01/16 23:54:06 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../libs/libft/includes/libft.h"
#include "../libs/minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// -- Variables
#define WIDTH 800
#define HEIGHT 600

// -- Structure
typedef struct s_mlx {
  void *mlx;
  void *win;
  char *title;
  int iter;
  int max_iter;

  char *data;
  void *img;
  int bpp;
  int endian;
  int size_line;
  int color;

  int zoom;
  int x;
  int y;
  double x1;
  double y1;
  double c_r;
  double c_i;
  double z_r;
  double z_i;
  double tmp;
} t_mlx;

// -- Utils
void ft_draw_pixel(t_mlx *fract, int x, int y, int color);
void ft_exit(t_mlx *fract, int type);
void ft_print_mlx(t_mlx *fract);

// -- Init
void ft_init_mlx(t_mlx *fract);

// -- Julia
void ft_julia(t_mlx *fract);

// -- Mandelbrot

// -- Burning Ship

// -- Hook
int ft_key_hook(int keycode, t_mlx *fract);

#endif
