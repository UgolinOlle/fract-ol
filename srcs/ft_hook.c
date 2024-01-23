/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:57:35 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 16:38:59 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Zoom in and out depending on the mouse.
 *
 * @param keycode int Key code.
 * @param fract t_mlx Fractal struct.
 * @return void
 */
static void	ft_zoom(int keycode, t_mlx *fract)
{
	double	x;
	double	y;

	x = fract->min.re + (fract->max.re - fract->min.re) * (WIDTH / 2) / (WIDTH
			- 1.0);
	y = fract->min.im + (fract->max.im - fract->min.im) * (HEIGHT / 2) / (HEIGHT
			- 1.0);
	if (keycode == 27 || keycode == 4)
	{
		fract->min.re = x + (fract->min.re - x) * 1.01;
		fract->min.im = y + (fract->min.im - y) * 1.01;
		fract->max.re = x + (fract->max.re - x) * 1.01;
		fract->max.im = y + (fract->max.im - y) * 1.01;
	}
	else if (keycode == 24 || keycode == 5)
	{
		fract->min.re = x + (fract->min.re - x) / 1.01;
		fract->min.im = y + (fract->min.im - y) / 1.01;
		fract->max.re = x + (fract->max.re - x) / 1.01;
		fract->max.im = y + (fract->max.im - y) / 1.01;
	}
}

/**
 * @brief Handle movement with arrow
 *
 * @param keycode int Key code.
 * @param fract t_mlx Fractal struct.
 * @return void
 */
static void	ft_move(int keycode, t_mlx *fract)
{
	if (keycode == 123 || keycode == 0)
	{
		fract->min.re -= (fract->max.re - fract->min.re) / 10;
		fract->max.re -= (fract->max.re - fract->min.re) / 10;
	}
	else if (keycode == 124 || keycode == 2)
	{
		fract->min.re += (fract->max.re - fract->min.re) / 10;
		fract->max.re += (fract->max.re - fract->min.re) / 10;
	}
	else if (keycode == 125 || keycode == 1)
	{
		fract->min.im += (fract->max.im - fract->min.im) / 10;
		fract->max.im += (fract->max.im - fract->min.im) / 10;
	}
	else if (keycode == 126 || keycode == 13)
	{
		fract->min.im -= (fract->max.im - fract->min.im) / 10;
		fract->max.im -= (fract->max.im - fract->min.im) / 10;
	}
}

/**
 * @brief Handle mouse movement
 *
 * @param keycode int Key code.
 * @param x int X coordinate.
 * @param y int Y coordinate.
 * @param fract t_mlx Fractal struct.
 * @return int
 */
int	ft_mouse_hook(int keycode, int x, int y, t_mlx *fract)
{
	if (keycode == 4)
	{
		fract->min.re = fract->min.re + (x - WIDTH / 2) * 0.1;
		fract->max.re = fract->max.re + (x - WIDTH / 2) * 0.1;
		fract->min.im = fract->min.im + (y - HEIGHT / 2) * 0.1;
		fract->max.im = fract->max.im + (y - HEIGHT / 2) * 0.1;
	}
	else if (keycode == 5)
	{
		fract->min.re = fract->min.re - (x - WIDTH / 2) * 0.1;
		fract->max.re = fract->max.re - (x - WIDTH / 2) * 0.1;
		fract->min.im = fract->min.im - (y - HEIGHT / 2) * 0.1;
		fract->max.im = fract->max.im - (y - HEIGHT / 2) * 0.1;
	}
	return (0);
}

/**
 * @brief Handle key press
 *
 * @param int keycode - key code
 * @param t_mlx *fract - fractol struct
 * @return int
 */
int	ft_key_hook(int keycode, t_mlx *fract)
{
	t_complex	c;

	c.re = fract->min.re + (fract->max.re - fract->min.re) * (WIDTH / 2)
		/ (WIDTH - 1.0);
	c.im = fract->min.im + (fract->max.im - fract->min.im) * (HEIGHT / 2)
		/ (HEIGHT - 1.0);
	if (keycode == 53)
		ft_exit(fract, "");
	else if (keycode == 24 || keycode == 27)
		ft_zoom(keycode, fract);
	else if ((keycode == 123 || keycode == 0) || (keycode == 126
			|| keycode == 13) || (keycode == 124 || keycode == 2)
		|| (keycode == 125 || keycode == 1))
		ft_move(keycode, fract);
	else if (ft_strcmp(fract->title, "Julia") == 0 && (keycode == 6
			|| keycode == 7 || keycode == 8 || keycode == 9))
		ft_julia_movement(keycode, fract);
	ft_exec_fract(fract);
	return (0);
}
