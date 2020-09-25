/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quadrant_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:34:25 by qdang             #+#    #+#             */
/*   Updated: 2020/09/24 20:34:45 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	calc_quadrant_4_i(t_info *s, double angle)
{
	int		temp_x;
	int		temp_y;
	char	c;
	int		i;

	i = 0;
	c = ' ';
	temp_y = s->grid.y + (int)(0.5 + (0.5 + i) * tan(angle));
	temp_x = s->grid.x + 1 + i;
	if (temp_y <= s->ms.y - 1 && temp_x <= s->ms.x - 1)
		c = s->map[temp_y][temp_x];
	while (c == '0' || c == s->start)
	{
		i++;
		temp_y = s->grid.y + (int)(0.5 + (0.5 + i) * tan(angle));
		temp_x = s->grid.x + 1 + i;
		if (temp_y <= s->ms.y - 1 && temp_x <= s->ms.x - 1)
			c = s->map[temp_y][temp_x];
		else
			break ;
	}
	return (i);
}

static int	calc_quadrant_4_j(t_info *s, double angle)
{
	int		temp_x;
	int		temp_y;
	char	c;
	int		j;

	j = 0;
	c = ' ';
	temp_y = s->grid.y + 1 + j;
	temp_x = s->grid.x + (int)(0.5 + (0.5 + j) / tan(angle));
	if (temp_y <= s->ms.y - 1 && temp_x <= s->ms.x - 1)
		c = s->map[temp_y][temp_x];
	while (c == '0' || c == s->start)
	{
		j++;
		temp_y = s->grid.y + 1 + j;
		temp_x = s->grid.x + (int)(0.5 + (0.5 + j) / tan(angle));
		if (temp_y <= s->ms.y - 1 && temp_x <= s->ms.x - 1)
			c = s->map[temp_y][temp_x];
		else
			break ;
	}
	return (j);
}

static void	calc_quadrant_4_0(t_info *s)
{
	char	c;
	int		i;

	i = 0;
	c = s->map[s->grid.y][s->grid.x + 1];
	while (c == '0' || c == s->start)
	{
		i++;
		c = s->map[s->grid.y][s->grid.x + 1 + i];
	}
	s->length = (0.5 + i) * SL;
	s->its.x = s->stand.x + s->length;
	s->its.y = s->stand.y;
	s->tex.x = 32;
	s->wall = 'E';
}

void		calc_quadrant_4(t_info *s, double angle, double dev)
{
	int		i;
	int		j;

	if (angle >= M_PI_2 - REDUND && angle <= M_PI_2 + REDUND)
		calc_quadrant_4_0(s);
	else
	{
		angle -= M_PI_2;
		i = calc_quadrant_4_i(s, angle);
		j = calc_quadrant_4_j(s, angle);
		if ((int)((0.5 + i) * SL) <= (int)((0.5 + j) * SL / tan(angle)))
		{
			s->its.x = s->stand.x + (int)((0.5 + i) * SL);
			s->its.y = s->stand.y + (int)((0.5 + i) * SL * tan(angle));
			s->length = (0.5 + i) * SL / cos(angle);
			s->tex.x = s->length * sin(angle) * 64 / SL + 32;
			while (s->tex.x >= 64)
				s->tex.x -= 64;
			s->length *= cos(dev);
			s->wall = 'E';
		}
		else
		{
			s->its.x = s->stand.x + (int)((0.5 + j) * SL / tan(angle));
			s->its.y = s->stand.y + (int)((0.5 + j) * SL);
			s->length = (0.5 + j) * SL / sin(angle);
			s->tex.x = -1 * s->length * cos(angle) * 64 / SL - 32;
			while (s->tex.x < 0)
				s->tex.x += 64;
			s->length *= cos(dev);
			s->wall = 'S';
		}
	}
}
