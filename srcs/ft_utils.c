/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:13:23 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 18:04:18 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Handle errors.
 *
 * @param error char* Error message.
 */
void	ft_exit(t_mlx *fract, char *content)
{
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->mlx)
		free(fract->mlx);
	if (!ft_strcmp(content, ""))
		exit(EXIT_SUCCESS);
	else
	{
		ft_putstr_fd(content, STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
}

/**
 * @brief MLX Exit
 *
 * @param fract t_mlx - Fractal struct.
 * @return int
 */
int	ft_mlx_exit(t_mlx *fract)
{
	ft_exit(fract, "");
	return (0);
}

/**
 * @brief Create TRGB color.
 *
 * @param t_color color - Color struct.
 * @return int
 */
int	ft_create_rgb(t_color rgb, t_mlx *fract)
{
	if (fract->iter == fract->max_iter)
		return (0x000000);
	else
	{
		rgb.r = (fract->iter * 8) % 255;
		rgb.g = (fract->iter * 2) % 255;
		rgb.b = (fract->iter * 3) % 255;
		return (rgb.r << 16 | rgb.g << 8 | rgb.b);
	}
}

/**
 * @brief Draw pixel.
 *
 * @param fract t_mlx - Fractal struct.
 * @param x int - X coordinate.
 * @param y int - Y coordinate.
 * @param color int - Color.
 * @return void
 */
void	ft_draw_pixel(t_mlx *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->data + (y * fract->size_line + x * (fract->bpp / 8));
	*(unsigned int *)dst = color;
}
