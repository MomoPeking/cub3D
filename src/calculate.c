/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:08:21 by qdang             #+#    #+#             */
/*   Updated: 2020/10/07 16:48:27 by qdang            ###   ########.fr       */
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
	double		angle;
	double		dev;
	double		len;
	int			nb;
	t_sprite	*sp;
	int			i;
	int			j;

	s->grid.x = s->sp.x + s->move.x;
	s->grid.y = s->sp.y + s->move.y;
	if (s->map[s->grid.y][s->grid.x] == '2')
		s->map[s->grid.y][s->grid.x] = '0';
	s->stand.x = (s->grid.x + 0.5) * SL;
	s->stand.y = (s->grid.y + 0.5) * SL;
	nb = nb_sprite(s);
	nb > 0 ? sp = (t_sprite *)ft_memalloc(sizeof(t_sprite) * nb) : 0;
	nb > 0 ? store_sprite(s, sp, nb) : 0;
	sort_sprite(sp, nb);
	i = -1;
	while (++i < s->res.x)
	{
		angle = s->sight + (double)(i + 1) / s->res.x * FOV * M_PI / 180;
		calculate(s, angle);
		while (angle < 0)
			angle += M_PI * 2;
		while (angle >= M_PI * 2)
			angle -= M_PI * 2;
		j = -1;
		while (++j < nb)
		{
			dev = -1;
			(sp[j].ang > angle && sp[j].ang - angle < sp[j].ang_rd) ||
				(sp[j].ang <= angle && angle - sp[j].ang < sp[j].ang_rd)
					? dev = angle - sp[j].ang : 0;
			sp[j].ang > angle && angle + M_PI * 2 - sp[j].ang < sp[j].ang_rd
				? dev = angle + M_PI * 2 - sp[j].ang : 0;
			sp[j].ang <= angle && sp[j].ang + M_PI * 2 - angle < sp[j].ang_rd
				? dev = angle - sp[j].ang - M_PI * 2 : 0;
			if (dev != -1)
			{
				len = sp[j].len_c * cos(dev);
				len < s->length ? sp[j].ex = 1 : 0;
				len > s->length ? sp[j].ex = 0 : 0;
			}
			dev != -1 ? sp[j].tex.x = tan(dev) * sp[j].len_c * 64 / SL + 32 : 0;
		}
		draw_3d_vline(s, i);
		j = -1;
		while (++j < nb)
			if (sp[j].ex == 1)
				draw_sprite(s, sp, i, j);
	}
	draw_2d_sight(s);
	draw_2d_frame(s);
	nb > 0 ? free(sp) : 0;
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
}
