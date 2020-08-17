/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_its.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:08:21 by qdang             #+#    #+#             */
/*   Updated: 2020/08/16 17:41:57 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Use stand_x/y and the radian to calculate the its_x/y.
*/

void	calc_its(t_info *s, double radian)
{
	while (radian < 0)
		radian += M_PI * 2;
	while (radian >= M_PI * 2)
		radian -= M_PI * 2;
	if (radian >= 0 - REDUND && radian < M_PI_2 - REDUND)
		calc_its_quadrant_1(s, radian);
	if (radian >= M_PI_2 - REDUND && radian < M_PI - REDUND)
		calc_its_quadrant_4(s, radian);
	if (radian >= M_PI - REDUND && radian < M_PI_2 * 3 - REDUND)
		calc_its_quadrant_3(s, radian);
	if (radian >= M_PI_2 * 3 - REDUND && radian < M_PI * 2 - REDUND)
		calc_its_quadrant_2(s, radian);
}
