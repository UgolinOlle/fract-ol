/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:50:27 by uolle             #+#    #+#             */
/*   Updated: 2024/01/17 23:31:18 by uolle            ###   ########.fr       */
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
#define WIDTH 700
#define HEIGHT 700

// -- Structure
typedef struct s_mlx {
  void *mlx;
  void *win;
  char *title;
  char *data;
  void *img;

  int iter;
  int max_iter;
  int color;
  int zoom;

  int bpp;
  int size_line;
  int endian;

  double x;
  double y;
  double x_start;
  double y_start;
  double x_end;
  double y_end;
  double c_r;
  double c_i;
  double z_r;
  double z_i;
  double tmp;
} t_mlx;

// -- Utils
void ft_draw_pixel(t_mlx *fract, int x, int y, int color);
int ft_exit(t_mlx *fract, int type);
int ft_get_color(int iter, int max_iter, int base);

// -- Init
void ft_init_julia(t_mlx *fract);
void ft_init_mlx(t_mlx *fract);

// -- Julia
void ft_julia(t_mlx *fract);

// -- Main
void ft_fractal(t_mlx *fract);

#endif
