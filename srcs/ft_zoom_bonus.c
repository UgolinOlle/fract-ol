/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:44:27 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/01/23 17:18:27 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Handle zoom with mouse
 *
 * @param keycode int Key code.
 * @param x int X coordinate.
 * @param y int Y coordinate.
 * @param fract t_mlx Fractal struct.
 * @return int
 */
int	ft_zoom(int keycode, int x, int y, t_mlx *fract)
{
	t_complex	mouse;

	mouse.re = fract->min.re + (fract->max.re - fract->min.re) * (double)x
		/ WIDTH;
	mouse.im = fract->min.im + (fract->max.im - fract->min.im) * (double)y
		/ HEIGHT;
	if (keycode == 5)
		ft_zoom_in(fract, mouse.re, mouse.im);
	else if (keycode == 4)
		ft_zoom_out(fract, mouse.re, mouse.im);
	return (0);
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
