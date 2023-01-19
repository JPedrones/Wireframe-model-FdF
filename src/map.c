/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:04:08 by jpedrones         #+#    #+#             */
/*   Updated: 2023/01/04 15:31:57 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_projection	init_projection(t_map *map)
{
	t_projection	camera;
	int				zoom1;
	int				zoom2;

	zoom1 = ((X_WIN - X_MENU) / map->length) / 2;
	zoom2 = (Y_WIN / map->height) / 2;
	if (zoom1 < X_WIN || zoom1 < Y_WIN)
		camera.zoom = zoom1;
	else
		camera.zoom = zoom2;
	camera.alpha = 0;
	camera.beta = 0;
	camera.gamma = 0;
	camera.x_offset = 0;
	camera.y_offset = 0;
	camera.z_divisor = 10;
	if (map->z_max > 100)
		camera.z_divisor = 0.8;
	return (camera);
}

int	map_checker(char **mat, t_map *map)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
	{
		if (!(ft_isdigit(*mat[i])) && *mat[i] != '-'
			&& *mat[i] != '\n')
			return (0);
		i++;
	}
	if (map->height == 0)
		map->length = i;
	if (i != map->length)
		return (0);
	return (1);
}

void	t_coord_new(char *point, t_coord **current)
{
	t_coord	*new;
	t_coord	*last;
	char	*temp;

	new = (t_coord *)malloc(sizeof(t_coord));
	if (!new)
		terminate(ERR_NEW_COORD);
	temp = ft_strnstr(point, "0x", 100);
	new->z = ft_atoi(point);
	new->color = 0;
	if (temp)
		new->color = strtol(temp, NULL, 16);
	new->pos = 1;
	new->next = NULL;
	if (*current)
	{
		last = *current;
		while (last->next != NULL)
			last = last->next;
		new->pos = last->pos + 1;
		last->next = new;
	}
	else
		*current = new;
}

void	read_map(t_map *map, int fd)
{
	char	*line;
	char	**temp_line;
	int		i;

	while (1)
	{
		i = -1;
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_line = ft_split(line, ' ');
		if (map_checker(temp_line, map) == 0)
			terminate(ERR_MAP_READING);
		while (++i < map->length)
		{
			if (map->z_max < ft_atoi(temp_line[i]))
				map->z_max = ft_atoi(temp_line[i]);
			t_coord_new(temp_line[i], &(map->coord));
			free(temp_line[i]);
		}
		free(temp_line[i]);
		free(temp_line);
		free(line);
		map->height++;
	}
}

void	init_map(t_map *map, int fd)
{
	map->length = 0;
	map->height = 0;
	map->z_max = 10;
	map->z_min = 0;
	map->coord = NULL;
	read_map(map, fd);
	map->cam = init_projection(map);
	close(fd);
}
