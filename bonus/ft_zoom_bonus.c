/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:44:27 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/01/23 18:20:54 by uolle            ###   ########.fr       */
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
