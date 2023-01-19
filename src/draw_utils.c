/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:50:39 by jpedrones         #+#    #+#             */
/*   Updated: 2022/12/20 15:00:24 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_image **img, int x, int y, int color)
{
	char	*dst;

	if (x > X_WIN || y > Y_WIN || x < 0 || y < 0)
		return ;
	dst = (*img)->addr + (y * (*img)->l_length + x * ((*img)->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_image *img)
{
	int	x;
	int	y;

	x = X_MENU - 1;
	while (++x < X_WIN)
	{
		y = -1;
		while (++y <= Y_WIN)
			put_pixel_img(&img, x, y, BACKGROUND);
	}
}

t_point	new_point(t_coord *coord, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = coord->z;
	point.color = 0;
	if (coord->color != 0)
		point.color = coord->color;
	return (point);
}

t_coord	*coord_column(t_coord *coord, int length)
{
	t_coord	*aux;
	int		index;

	aux = coord;
	index = -1;
	while (++index < length && aux->next != NULL)
		aux = aux->next;
	return (aux);
}
