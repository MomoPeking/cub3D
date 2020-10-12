/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quadrant_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:27:35 by qdang             #+#    #+#             */
/*   Updated: 2020/10/12 13:12:21 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	calc_quadrant_1_i(t_info *s, double angle)
{
	int		temp_x;
	int		temp_y;
	char	c;
	int		i;

	i = 0;
	c = ' ';
	temp_y = s->grid.y - 1 - i;
	temp_x = s->grid.x + (int)(0.5 + (0.5 + i) * tan(angle));
	if (temp_y >= 0 && temp_x <= s->ms.x - 1)
		c = s->map[temp_y][temp_x];
	while (c != '1')
	{
		i++;
		temp_y = s->grid.y - 1 - i;
		temp_x = s->grid.x + (int)(0.5 + (0.5 + i) * tan(angle));
		if (temp_y >= 0 && temp_x <= s->ms.x - 1)
			c = s->map[temp_y][temp_x];
		else
			break ;
	}
	return (i);
}

static int	calc_quadrant_1_j(t_info *s, double angle)
{
	int		temp_x;
	int		temp_y;
	char	c;
	int		j;

	j = 0;
	c = ' ';
	temp_y = s->grid.y - (int)(0.5 + (0.5 + j) / tan(angle));
	temp_x = s->grid.x + 1 + j;
	if (temp_y >= 0 && temp_x <= s->ms.x - 1)
		c = s->map[temp_y][temp_x];
	while (c != '1')
	{
		j++;
		temp_y = s->grid.y - (int)(0.5 + (0.5 + j) / tan(angle));
		temp_x = s->grid.x + 1 + j;
		if (temp_y >= 0 && temp_x <= s->ms.x - 1)
			c = s->map[temp_y][temp_x];
		else
			break ;
	}
	return (j);
}

static void	calc_quadrant_1_0(t_info *s)
{
	char	c;
	int		i;

	i = 0;
	c = s->map[s->grid.y - 1][s->grid.x];
	while (c != '1')
	{
		i++;
		c = s->map[s->grid.y - 1 - i][s->grid.x];
	}
	s->length = (0.5 + i) * SL;
	s->its.x = s->stand.x;
	s->its.y = s->stand.y - s->length;
	s->tex.x = 32;
	s->wall = 'N';
}

static void	calc_quadrant_1_1(t_info *s, int i, double angle, double dev)
{
	s->its.x = s->stand.x + (int)((0.5 + i) * SL * tan(angle));
	s->its.y = s->stand.y - (int)((0.5 + i) * SL);
	s->length = (int)((0.5 + i) * SL) / cos(angle);
	s->tex.x = s->length * sin(angle) * 64 / SL + 32;
	while (s->tex.x >= 64)
		s->tex.x -= 64;
	s->length *= cos(dev);
	s->wall = 'N';
	if (tan(angle) > 1 - REDUND && tan(angle) < 1 + REDUND)
		check_stand(s, 1, 0) == 0 ? s->wall = 'E' : 0;
}

void		calc_quadrant_1(t_info *s, double angle, double dev)
{
	t_point		p;

	if (angle >= 0 && angle <= REDUND)
		calc_quadrant_1_0(s);
	else
	{
		p.x = calc_quadrant_1_i(s, angle);
		p.y = calc_quadrant_1_j(s, angle);
		if ((int)((0.5 + p.x) * SL) <= (int)((0.5 + p.y) * SL / tan(angle)))
			calc_quadrant_1_1(s, p.x, angle, dev);
		else
		{
			s->its.x = s->stand.x + (int)((0.5 + p.y) * SL);
			s->its.y = s->stand.y - (int)((0.5 + p.y) * SL / tan(angle));
			s->length = (0.5 + p.y) * SL / sin(angle);
			s->tex.x = -1 * s->length * cos(angle) * 64 / SL - 32;
			while (s->tex.x < 0)
				s->tex.x += 64;
			s->length *= cos(dev);
			s->wall = 'E';
			if (tan(angle) > 1 - REDUND && tan(angle) < 1 + REDUND)
				check_stand(s, 0, -1) == 0 ? s->wall = 'N' : 0;
		}
	}
}
