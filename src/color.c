/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:18:48 by jpedrones         #+#    #+#             */
/*   Updated: 2022/12/20 16:15:36 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	set_default_color(int z_min, int z_max, int z)
{
	double	percentage;

	percentage = percent(z_min, z_max, abs(z));
	if (percentage < 0.1)
		return (COLOR_BASE);
	if (percentage < 0.3)
		return (NIGHT_GREEN);
	else if (percentage < 0.5)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.7)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.9)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

static int	get_light(int init, int dest, double percentage)
{
	return ((int)((1 - percentage) * init + percentage * dest));
}

int	get_color(t_bres current, t_point init, t_point dest)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == dest.color)
		return (current.color);
	if ((dest.x - init.x) > (dest.y - init.y))
		percentage = percent(init.x, dest.x, current.x);
	else
		percentage = percent(init.y, dest.y, current.y);
	red = get_light((init.color >> 16) & 0xFF,
			(dest.color >> 16) & 0xFF, percentage);
	green = get_light((init.color >> 8) & 0xFF,
			(dest.color >> 8) & 0xFF, percentage);
	blue = get_light(init.color & 0xFF,
			dest.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
