/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:26:40 by jpedrones         #+#    #+#             */
/*   Updated: 2022/10/03 12:05:23 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	terminate(char *s)
{
	if (errno == -1)
		perror(s);
	else
		ft_putendl_fd(s, 2);
	exit(1);
}

void	init_fdf(t_data *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, X_WIN, Y_WIN, "FdF");
	fdf->img.img = mlx_new_image(fdf->mlx, X_WIN, Y_WIN);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &(fdf->img.bpp),
			&(fdf->img.l_length), &(fdf->img.endian));
}

void	close_window(t_data *fdf, t_map *map)
{
	t_coord	*aux;

	while (map->coord->next != NULL)
	{
		aux = map->coord->next;
		free(map->coord);
		map->coord = aux;
	}
	free(map->coord);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
}

int	exit_button(t_data *fdf)
{
	mlx_loop_end(fdf->mlx);
	return (0);
}
