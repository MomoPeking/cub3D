/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:08:21 by qdang             #+#    #+#             */
/*   Updated: 2020/09/30 17:57:21 by qdang            ###   ########.fr       */
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
	else if (angle >= M_PI_2 - REDUND && angle < M_PI - REDUND)
		calc_quadrant_4(s, angle, dev);
	else if (angle >= M_PI - REDUND && angle < M_PI_2 * 3 - REDUND)
		calc_quadrant_3(s, angle, dev);
	else
		calc_quadrant_2(s, angle, dev);
}

void	draw(t_info *s)
{
	int		i;
	double	angle;

	s->grid.x = s->sp.x + s->move.x;
	s->grid.y = s->sp.y + s->move.y;
	if (s->map[s->grid.y][s->grid.x] == '2')
		s->map[s->grid.y][s->grid.x] = '0';
	s->stand.x = (s->grid.x + 0.5) * SL;
	s->stand.y = (s->grid.y + 0.5) * SL;
	i = -1;
	while (++i < s->res.x)
	{
		angle = (double)(i + 1) / s->res.x * FOV;
		angle *= M_PI / 180;
		calculate(s, s->sight + angle);
		draw_3d_vline(s, i);
	}
	draw_2d_sight(s);
	draw_2d_frame(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
}
