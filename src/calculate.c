/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:08:21 by qdang             #+#    #+#             */
/*   Updated: 2020/09/13 20:14:00 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Use stand_x/y and the angle to calculate the its_x/y and the length from
** stand_x/y to its_x/y.
*/

void	calculate(t_info *s, double angle)
{
	double	dev;
	double	middle;

	middle = FOV / 2 * M_PI / 180;
	dev = angle - s->sight;
	if (dev <= middle)
		dev = middle - dev;
	else
		dev = dev - middle;
	while (angle < 0)
		angle += M_PI * 2;
	while (angle >= M_PI * 2)
		angle -= M_PI * 2;
	if (angle >= 0 && angle < M_PI_2 - REDUND)
		calc_quadrant_1(s, angle, dev);
	if (angle >= M_PI_2 - REDUND && angle < M_PI - REDUND)
		calc_quadrant_4(s, angle, dev);
	if (angle >= M_PI - REDUND && angle < M_PI_2 * 3 - REDUND)
		calc_quadrant_3(s, angle, dev);
	if (angle >= M_PI_2 * 3 - REDUND && angle < M_PI * 2)
		calc_quadrant_2(s, angle, dev);
}
