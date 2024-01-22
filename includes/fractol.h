/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:50:27 by uolle             #+#    #+#             */
/*   Updated: 2024/01/22 11:24:12 by uolle            ###   ########.fr       */
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

typedef struct s_color {
  int r;
  int g;
  int b;
} t_color;

typedef struct s_complex {
  double re;
  double im;
} t_complex;

typedef struct s_mlx {
  void *mlx;
  void *win;
  char *title;
  char *data;
  void *img;
  int bpp;
  int size_line;
  int endian;

  t_complex min;
  t_complex max;
  t_complex julia;
  int iter;
  int max_iter;
  t_color color;
} t_mlx;

// -- Init
void ft_init_fractol(t_mlx *fract);

// -- Utils
void ft_exit(t_mlx *fract, char *content);
void ft_print_struct(t_mlx *fract);

// -- Main
void ft_exec_fract(t_mlx *fract);

#endif
