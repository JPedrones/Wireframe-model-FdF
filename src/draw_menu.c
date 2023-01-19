/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:47:40 by jpedrones         #+#    #+#             */
/*   Updated: 2022/10/20 12:50:41 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_menu_background(t_image *img)
{
	int	x;
	int	y;

	x = -1;
	while (++x < X_MENU)
	{
		y = -1;
		while (++y <= Y_WIN)
			put_pixel_img(&img, x, y, MENU_BACKGROUND);
	}
}

void	draw_menu(t_data *fdf)
{
	int		y;

	y = 0;
	mlx_string_put(fdf->mlx, fdf->win, 55, y += 20,
		TEXT_COLOR, "How to use");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 35,
		TEXT_COLOR, "Zoom: +/- or M/N");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30,
		TEXT_COLOR, "Move: Arrows");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30,
		TEXT_COLOR, "Flatten: </>");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30,
		TEXT_COLOR, "Rotate:");
	mlx_string_put(fdf->mlx, fdf->win, 35, y += 25,
		TEXT_COLOR, "Y-Axis: W/S");
	mlx_string_put(fdf->mlx, fdf->win, 35, y += 25,
		TEXT_COLOR, "X-Axis: A/D");
	mlx_string_put(fdf->mlx, fdf->win, 35, y += 25,
		TEXT_COLOR, "Z-Axis: Q/E");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30,
		TEXT_COLOR, "Projection:");
	mlx_string_put(fdf->mlx, fdf->win, 35, y += 25,
		TEXT_COLOR, "ISO/PARALLEL: SPACE");
	mlx_string_put(fdf->mlx, fdf->win, 35, y += 25,
		TEXT_COLOR, "RESET: ENTER");
}
