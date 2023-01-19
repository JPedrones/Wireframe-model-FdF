/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedrones <jpedrones@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:26:53 by jpedrones         #+#    #+#             */
/*   Updated: 2022/12/13 20:27:01 by jpedrones        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	fdf;
	int		fd;

	errno = 0;
	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) == 0)
			terminate(ERR_INVALID_MAP);
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			terminate(ERR_MAP);
		init_fdf(&fdf);
		init_map(&(fdf.map), fd);
		mlx_hook(fdf.win, 17, 0, exit_button, &fdf);
		mlx_hook(fdf.win, 02, 1L << 0, key_press, &fdf);
		draw(&fdf, &(fdf.map));
		mlx_loop(fdf.mlx);
		close_window(&fdf, &(fdf.map));
	}
	else
		terminate(ERR_USAGE);
	return (0);
}
