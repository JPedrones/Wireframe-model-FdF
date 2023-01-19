/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:16 by jpedrones         #+#    #+#             */
/*   Updated: 2022/12/20 16:14:54 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "fdf.h"

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x0f0f0f
# define MENU_BACKGROUND	0x14040E

//FF0000
# define COLOR_BASE			0x9A1F6A
# define NIGHT_GREEN		0x0b4a51
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

typedef struct s_bres	t_bres;
typedef struct s_point	t_point;

int	set_default_color(int z_min, int z_max, int z);
int	get_color(t_bres current, t_point init, t_point dest);

#endif //COLOR_H