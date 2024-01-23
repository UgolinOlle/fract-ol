/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:40:41 by uolle             #+#    #+#             */
/*   Updated: 2024/01/23 16:41:19 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Calculate Mandelbrot iteration.
 *
 * @param t_mlx *fract - The fractal struct
 * @param t_complex *c - The complex number
 */
static int	ft_mandelbrot_iteration(t_mlx *fract, t_complex *c)
{
	int			i;
	t_complex	z;
	double		tmp_re;
	double		tmp_im;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < fract->max_iter)
	{
		tmp_re = z.re;
		tmp_im = z.im;
		z.re = tmp_re * tmp_re - tmp_im * tmp_im + c->re;
		z.im = 2 * tmp_re * tmp_im + c->im;
		if ((z.re * z.re + z.im * z.im) > 4)
			break ;
		i++;
	}
	return (i);
}

/**
 * @brief Initialize the mandelbrot fractal
 *
 * @param t_mlx *fract - The fractal struct
 * */
void	ft_init_mandelbrot(t_mlx *fract)
{
	fract->title = "Mandelbrot";
	fract->max.re = 1.0;
	fract->min.re = -2.0;
	fract->max.im = 1.5;
	fract->min.im = -1.5;
	fract->rgb.r = 2;
	fract->rgb.g = 2;
	fract->rgb.b = 2;
}

/**
 * @brief Create the mandelbrot fractal
 *
 * @param t_mlx *fract - The fractal struct
 * @return void
 */
void	ft_mandelbrot(t_mlx *fract)
{
	int			x;
	int			y;
	t_complex	c;

	mlx_clear_window(fract->mlx, fract->win);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.re = fract->min.re + x * (fract->max.re - fract->min.re) / WIDTH;
			c.im = fract->min.im + y * (fract->max.im - fract->min.im) / HEIGHT;
			fract->iter = ft_mandelbrot_iteration(fract, &c);
			ft_draw_pixel(fract, x, y, ft_create_rgb(fract->rgb, fract));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
