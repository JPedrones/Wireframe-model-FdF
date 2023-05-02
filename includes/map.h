/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:38:54 by jpedrones         #+#    #+#             */
/*   Updated: 2023/05/02 03:19:25 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fdf.h"

typedef struct s_coord
{
	int				z;
	int				pos;
	int				color;
	struct s_coord	*next;
}	t_coord;

typedef struct s_projection
{
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	int		iso;
	float	z_divisor;
	int		x_offset;
	int		y_offset;
}	t_projection;

typedef struct s_map
{
	int				length;
	int				height;
	int				z_min;
	int				z_max;
	t_coord			*coord;
	t_projection	cam;
}	t_map;

t_projection	init_projection(t_map *map);
void			t_coord_new(char *coord, t_coord **current);
void			read_map(t_map *map, int fd);
void			init_map(t_map *map, int fd);

#endif //MAP_H