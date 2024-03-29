/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:57:35 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 22:50:28 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
 * @brief Zoom in
 *
 * @param fract t_mlx Fractal struct.
 * @param cre double Mouse real part.
 * @param cim double Mouse imaginary part.
 * @return void
 */
void	ft_zoom_in(t_mlx *fract, double cre, double cim)
{
	fract->min.re = cre + (fract->min.re - cre) * 0.9;
	fract->min.im = cim + (fract->min.im - cim) * 0.9;
	fract->max.re = cre + (fract->max.re - cre) * 0.9;
	fract->max.im = cim + (fract->max.im - cim) * 0.9;
}

/**
 * @brief Zoom out
 *
 * @param fract t_mlx Fractal struct.
 * @param cre double Mouse real part.
 * @param cim double Mouse imaginary part.
 * @return void
 */
void	ft_zoom_out(t_mlx *fract, double cre, double cim)
{
	fract->min.re = cre + (fract->min.re - cre) / 0.9;
	fract->min.im = cim + (fract->min.im - cim) / 0.9;
	fract->max.re = cre + (fract->max.re - cre) / 0.9;
	fract->max.im = cim + (fract->max.im - cim) / 0.9;
}

/**
 * @brief Handle mouse press
 *
 * @param button int Button code.
 * @param x int X coordinate.
 * @param y int Y coordinate.
 * @param fract t_mlx Fractal struct.
 */
int	ft_mouse_hook(int button, int x, int y, t_mlx *fract)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			ft_zoom_in(fract, 0, 0);
		else if (button == 5)
			ft_zoom_out(fract, 0, 0);
		ft_exec_fract(fract);
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
	else if (keycode == 24)
		ft_zoom_in(fract, c.re, c.im);
	else if (keycode == 27)
		ft_zoom_out(fract, c.re, c.im);
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
