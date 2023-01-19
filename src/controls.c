/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:42:52 by jpedrones         #+#    #+#             */
/*   Updated: 2022/12/20 14:45:44 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"

static void	zoom(int key, t_data *fdf)
{
	if (key == PLUS_NPAD || key == M_KEY)
		fdf->map.cam.zoom += 1;
	if (key == MINUS_NPAD || key == N_KEY)
		fdf->map.cam.zoom -= 1;
	if (fdf->map.cam.zoom < 1)
		fdf->map.cam.zoom = 1;
}

static void	flatten(int key, t_data *fdf)
{
	if (key == LESS_KEY)
		fdf->map.cam.z_divisor -= 0.1;
	if (key == MORE_KEY)
		fdf->map.cam.z_divisor += 0.1;
	if (fdf->map.cam.z_divisor < 0.1)
		fdf->map.cam.z_divisor = 0.1;
}

static void	move(int key, t_data *fdf)
{
	if (key == UP_KEY)
		fdf->map.cam.y_offset -= 10;
	if (key == DOWN_KEY)
		fdf->map.cam.y_offset += 10;
	if (key == RIGHT_KEY)
		fdf->map.cam.x_offset += 10;
	if (key == LEFT_KEY)
		fdf->map.cam.x_offset -= 10;
}

static void	rotate(int key, t_data *fdf)
{
	if (key == W_KEY)
		fdf->map.cam.alpha -= 0.1;
	if (key == S_KEY)
		fdf->map.cam.alpha += 0.1;
	if (key == D_KEY)
		fdf->map.cam.beta += 0.1;
	if (key == A_KEY)
		fdf->map.cam.beta -= 0.1;
	if (key == Q_KEY)
		fdf->map.cam.gamma -= 0.1;
	if (key == E_KEY)
		fdf->map.cam.gamma += 0.1;
}

int	key_press(int key, t_data *fdf)
{
	if (key == SPACE_KEY)
		fdf->map.cam.iso += 1;
	if (key == ENTER_KEY)
		fdf->map.cam = init_projection(&(fdf->map));
	if (key == W_KEY || key == S_KEY
		|| key == A_KEY || key == D_KEY
		|| key == Q_KEY || key == E_KEY)
		rotate(key, fdf);
	if (key == UP_KEY || key == DOWN_KEY
		|| key == RIGHT_KEY || key == LEFT_KEY)
		move(key, fdf);
	if (key == LESS_KEY || key == MORE_KEY)
		flatten (key, fdf);
	if (key == PLUS_NPAD || key == M_KEY
		|| key == MINUS_NPAD || key == N_KEY)
		zoom(key, fdf);
	if (key == ESC_KEY)
		exit_button(fdf);
	draw(fdf, &(fdf->map));
	return (0);
}
