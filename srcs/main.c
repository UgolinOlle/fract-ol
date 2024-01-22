/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:47:19 by uolle             #+#    #+#             */
/*   Updated: 2024/01/22 11:24:22 by uolle            ###   ########.fr       */
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
  if (argc == 2) {
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
      fract->title = "Mandelbrot";
    else if (ft_strcmp(argv[1], "julia") == 0) {
      fract->title = "Julia";
    } else
      ft_exit(fract, "[ERROR] - Usage: ./fractol [fractal name]");
  } else if (argc == 3) {
    if (ft_strcmp(argv[2], "1") == 0) {
      ;
    } else if (ft_strcmp(argv[2], "2") == 0) {
      ;
    } else if (ft_strcmp(argv[2], "3") == 0) {
      ;
    } else
      ft_exit(fract, "[ERROR] - Usage: ./fractol [fractal name]");
  } else
    ft_exit(fract, "[ERROR] - Usage: ./fractol [fractal name]");
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
    ft_exit(fract, "[INFO] - Julia hasn't been implemented yet.");
  mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
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

  ft_init_fractol(&fract);
  ft_check_args(argc, argv, &fract);
  ft_exec_fract(&fract);
  mlx_loop(fract.mlx);
  return (0);
}
