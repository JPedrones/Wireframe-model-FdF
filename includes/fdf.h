/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:29:22 by jpedrones         #+#    #+#             */
/*   Updated: 2023/05/02 03:18:36 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "map.h"
# include "draw.h"
# include "error_message.h"

# include <mlx.h>
# include <math.h>	//sin, cos and abs
# include <fcntl.h>	//open and close
# include <errno.h>	//errno
# include <stdio.h>	//perror

# define X_WIN  1280
# define Y_WIN  720
# define X_MENU 160

typedef struct s_map	t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_image	img;
	t_map	*map;
}	t_data;

// fdf_utils.c
void	terminate(char *s);
void	init_fdf(t_data *fdf);
void	close_window(t_data *fdf, t_map *map);
int		exit_button(t_data *fdf);

// controls.c
int		key_press(int keycode, t_data *fdf);

#endif //FDF_H