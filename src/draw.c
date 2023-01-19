/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:40:51 by jpedrones         #+#    #+#             */
/*   Updated: 2022/12/21 16:14:41 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	bres_define(t_bres *b, t_point *init, t_point *dest)
{
	b->dx = abs(dest->x - init->x);
	b->dy = abs(dest->y - init->y);
	b->p = b->dx - b->dy;
	b->x = init->x;
	b->y = init->y;
	if (init->x < dest->x)
		b->sign_x = 1;
	else
		b->sign_x = -1;
	if (init->y < dest->y)
		b->sign_y = 1;
	else
		b->sign_y = -1;
}

void	bresenham(t_image *img, t_point init, t_point dest)
{
	t_bres	bres;
	int		p;

	bres_define(&bres, &init, &dest);
	while (bres.x != dest.x || bres.y != dest.y)
	{
		bres.color = get_color(bres, init, dest);
		put_pixel_img(&img, bres.x, bres.y, bres.color);
		p = bres.p;
		if (p * 2 > -bres.dy)
		{
			bres.p -= bres.dy;
			bres.x += bres.sign_x;
		}
		if (p * 2 < bres.dx)
		{
			bres.p += bres.dx;
			bres.y += bres.sign_y;
		}
	}
}

void	draw_map(t_image *img, t_map *map)
{
	t_coord	*temp;	
	t_coord	*aux;
	int		x;
	int		y;

	temp = map->coord;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->length && temp != NULL)
		{
			if (x < map->length - 1)
				bresenham(img, define_point(map, new_point(temp, x, y)),
					define_point(map, new_point(temp->next, x + 1, y)));
			if (y < map->height - 1)
			{
				aux = coord_column(temp, map->length);
				bresenham(img, define_point(map, new_point(temp, x, y)),
					define_point(map, new_point(aux, x, y + 1)));
			}
			temp = temp->next;
		}
	}
}

void	draw(t_data *fdf, t_map *map)
{
	draw_background(&(fdf->img));
	draw_map(&(fdf->img), map);
	draw_menu_background(&(fdf->img));
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	draw_menu(fdf);
}

t_point	define_point(t_map *map, t_point p)
{
	if (p.color == 0)
		p.color = set_default_color(map->z_min, map->z_max, p.z);
	p.y *= map->cam.zoom;
	p.x *= map->cam.zoom;
	p.z *= map->cam.z_divisor;
	p.x -= (map->length * map->cam.zoom) / 2;
	p.y -= (map->height * map->cam.zoom) / 2;
	if (map->cam.iso % 2 == 0)
	{
		rotate_x(&p.y, &p.z, map->cam.alpha);
		rotate_y(&p.x, &p.z, map->cam.beta);
		rotate_z(&p.x, &p.y, map->cam.gamma);
		isometric(&p.x, &p.y, p.z);
	}
	p.x += (X_WIN - X_MENU) / 2 + map->cam.x_offset + X_MENU;
	p.y += (Y_WIN + (map->cam.zoom)) / 2 + map->cam.y_offset;
	return (p);
}
