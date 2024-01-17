/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:47:19 by uolle             #+#    #+#             */
/*   Updated: 2024/01/16 23:52:55 by uolle            ###   ########.fr       */
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
  if (argc != 2)
    ft_handle_error("[ERROR] - Usage: ./fractol [fractal name]");
  if (ft_strcmp(argv[1], "mandelbrot") == 0)
    fract->title = "Mandelbrot";
  else if (ft_strcmp(argv[1], "julia") == 0)
    fract->title = "Julia";
  else if (ft_strcmp(argv[1], "burningship") == 0)
    fract->title = "Burningship";
  else
    ft_handle_error("[ERROR] - Usage: ./fractol [fractal name]");
}

/**
 * @brief Select the fractal to be drawn.
 *
 * @param fract t_mlx Fractal struct.
 */
static void ft_menu(t_mlx *fract) {
  if (ft_strcmp(fract->title, "Mandelbrot") == 0)
    ft_putstr_fd("[INFO] - Mandelbrot asn't been implemented yet.",
                 STDOUT_FILENO);
  else if (ft_strcmp(fract->title, "Julia") == 0)
    ft_julia(fract);
  else if (ft_strcmp(fract->title, "Burningship") == 0)
    ft_putstr_fd("[INFO] - Mandelbrot asn't been implemented yet.",
                 STDOUT_FILENO);
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

  if (argc < 2)
    ft_handle_error("[ERROR] - Usage: ./fractol [fractal name]");
  ft_check_args(argc, argv, &fract);
  ft_init_mlx(&fract);
  ft_print_mlx(&fract);
  ft_menu(&fract);
  mlx_loop(fract.mlx);
  return (0);
}
