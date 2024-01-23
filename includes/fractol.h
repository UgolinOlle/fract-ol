/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:50:27 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 15:44:04 by uolle            ###   ########.fr       */
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
#define WIDTH 600
#define HEIGHT 600

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
  t_color rgb;
  int color;
} t_mlx;

// -- Hooks
int ft_mouse_hook(int keycode, int x, int y, t_mlx *fract);
int ft_key_hook(int keycode, t_mlx *fract);

// -- Init
void ft_init_fractol(t_mlx *fract);

// -- Utils
void ft_exit(t_mlx *fract, char *content);
int ft_mlx_exit(t_mlx *fract);
int ft_create_rgb(t_color rgb, t_mlx *fract);
void ft_draw_pixel(t_mlx *fract, int x, int y, int color);
void ft_color_shift(t_color *rgb);
void ft_print_fractol(t_mlx *fract);

// -- Julia
void ft_init_julia(t_mlx *fract, int set);
void ft_julia(t_mlx *fract);
void ft_julia_movement(int keycode, t_mlx *fract);

// -- Main
int ft_exec_fract(t_mlx *fract);

// -- Mandelbrot
void ft_init_mandelbrot(t_mlx *fract);
void ft_mandelbrot(t_mlx *fract);

#endif
