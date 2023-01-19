/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:08:54 by jpedrones         #+#    #+#             */
/*   Updated: 2022/12/13 20:27:34 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "fdf.h"
# include "color.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
	int	z;
}	t_point;

typedef struct s_bres
{
	int	x;
	int	y;
	int	sign_x;
	int	sign_y;
	int	dx;
	int	dy;
	int	color;
	int	p;
}	t_bres;

typedef struct s_image		t_image;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_coord		t_coord;

// draw.c
void	bresenham(t_image *img, t_point init, t_point dest);
void	draw_map(t_image *img, t_map *map);
void	draw(t_data *fdf, t_map *map);
t_point	define_point(t_map *map, t_point p);

// draw_utils.c
void	put_pixel_img(t_image **img, int x, int y, int color);
void	draw_background(t_image *img);
t_point	new_point(t_coord *coord, int x, int y);
t_coord	*coord_column(t_coord *coord, int length);

// draw_rotate.c
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
void	isometric(int *x, int *y, int z);

//draw_menu.c
void	draw_menu_background(t_image *img);
void	draw_menu(t_data *fdf);

#endif //DRAW_H