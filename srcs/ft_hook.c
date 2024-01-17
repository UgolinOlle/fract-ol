/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:35:49 by uolle             #+#    #+#             */
/*   Updated: 2024/01/16 22:40:56 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int ft_key_hook(int keycode, t_mlx *fract) {
  if (keycode == 53)
    ft_exit(fract);
  else if (keycode == 123)
    fract->x1 *= 1.1;
  else if (keycode == 124)
    fract->x1 *= 0.9;
  else if (keycode == 125)
    fract->y1 *= 1.1;
  else if (keycode == 126)
    fract->y1 *= 0.9;
  else if (keycode == 24)
    fract->zoom *= 1.1;
  return (0);
}
