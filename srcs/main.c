/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:47:19 by uolle             #+#    #+#             */
/*   Updated: 2024/01/22 21:23:27 by uolle            ###   ########.fr       */
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
    ft_exit(fract, "[ERROR] - Usage: ./fractol [fractal name]");
  if (ft_strcmp(argv[1], "mandelbrot") == 0)
    fract->title = "Mandelbrot";
  else if (ft_strcmp(argv[1], "julia") == 0 && argv[2]) {
    fract->title = "Julia";
    if (ft_atoi(argv[2]) == 1)
      ft_init_julia(fract, 1);
    else if (ft_atoi(argv[2]) == 2)
      ft_init_julia(fract, 2);
    else if (ft_atoi(argv[2]) == 3)
      ft_init_julia(fract, 3);
    else
      ft_exit(fract, "[ERROR] - Usage: ./fractol julia [1 or 2]");
  } else
    ft_exit(fract, "[ERROR] - Usage: ./fractol julia [real] [imaginary]");
}

/**
 * @brief Initialize the fractal data.
 *
 * @param fract t_mlx Fractal struct.
 * @return void
 */
void ft_exec_fract(t_mlx *fract) {
  if (!ft_strcmp(fract->title, "Mandelbrot"))
    ft_exit(fract, "[INFO] - Mandelbrot hasn't been implemented yet.");
  else if (!ft_strcmp(fract->title, "Julia"))
    ft_julia(fract);
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
  ft_print_fractol(&fract);
  ft_exec_fract(&fract);
  mlx_loop(fract.mlx);
  return (0);
}
