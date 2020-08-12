/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_its.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:08:21 by qdang             #+#    #+#             */
/*   Updated: 2020/08/12 14:14:45 by qdang            ###   ########.fr       */
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
	printf("radian: %.20f\n", radian);	
	if (radian >= 0 && radian < M_PI_2)
		calc_its_quadrant_1(s, radian);
	if (radian >= M_PI_2 && radian < M_PI)
		calc_its_quadrant_4(s, radian);
	if (radian >= M_PI && radian < M_PI_2 * 3)
		calc_its_quadrant_3(s, radian);
	if (radian >= M_PI_2 * 3 && radian < M_PI * 2)
		calc_its_quadrant_2(s, radian);
}