/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:47:19 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 16:17:31 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Check if the arguments are valid.
 *
 * @param argc int Number of arguments.
 * @param argv char** Array of arguments.
 * @param fract t_mlx Fractal struct.
 */
static void ft_check_args(int argc, char **argv, t_mlx *fract) {
  if (argc < 2)
    ft_handle_error("[ERROR] - Usage: ./fractol [fractal name]");
  if (ft_strcmp(argv[1], "mandelbrot") == 0) {
    fract->title = "Mandelbrot";
    ft_init_mandelbrot(fract);
  } else if (ft_strcmp(argv[1], "julia") == 0) {
    if (argc < 3)
      ft_handle_error("[ERROR] - Usage: ./fractol julia [1 or 2 or 3]");
    fract->title = "Julia";
    if (ft_atoi(argv[2]) == 1)
      ft_init_julia(fract, 1);
    else if (ft_atoi(argv[2]) == 2)
      ft_init_julia(fract, 2);
    else if (ft_atoi(argv[2]) == 3)
      ft_init_julia(fract, 3);
    else if (ft_atoi(argv[2]) == 0)
      ft_handle_error("[ERROR] - Usage: ./fractol julia [1 or 2 or 3]");
    else
      ft_handle_error("[ERROR] - Usage: ./fractol julia [1 or 2 or 3]");
  } else if (ft_strcmp(argv[1], "tricorn") == 0) {
    fract->title = "Tricorn";
    ft_init_tricorn(fract);
  } else {
    ft_handle_error("[ERROR] - Usage: ./fractol [fractal name]");
  }
}

/**
 * @brief Initialize the fractal data.
 *
 * @param fract t_mlx Fractal struct.
 * @return void
 */
int ft_exec_fract(t_mlx *fract) {
  if (!ft_strcmp(fract->title, "Mandelbrot"))
    ft_mandelbrot(fract);
  else if (!ft_strcmp(fract->title, "Julia"))
    ft_julia(fract);
  else if (!ft_strcmp(fract->title, "Tricorn"))
    ft_tricorn(fract);
  return (0);
}

/**
 * @brief Main function.
 *
 * @param argc int Number of arguments.
 * @param argv char** Array of arguments.
 * @return int 0 if success.
 */
int main(int argc, char **argv) {
  t_mlx fract;

  ft_check_args(argc, argv, &fract);
  ft_init_fractol(&fract);
  ft_exec_fract(&fract);
  mlx_mouse_hook(fract.win, ft_mouse_hook, &fract);
  mlx_key_hook(fract.win, ft_key_hook, &fract);
  mlx_hook(fract.win, 17, 0, ft_mlx_exit, &fract);
  mlx_loop_hook(fract.mlx, ft_exec_fract, &fract);
  mlx_loop(fract.mlx);
  return (0);
}
