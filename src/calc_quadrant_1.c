/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quadrant_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:27:35 by qdang             #+#    #+#             */
/*   Updated: 2020/09/18 06:20:15 by qdang            ###   ########.fr       */
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
	while (c == '0' || c == s->start)
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
	while (c == '0' || c == s->start)
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
	while (c == '0' || c == s->start)
	{
		i++;
		c = s->map[s->grid.y - 1 - i][s->grid.x];
	}
	s->length = (0.5 + i) * SL;
	s->its.x = s->stand.x;
	s->its.y = s->stand.y - s->length;
	s->wall = 'N';
}

void		calc_quadrant_1(t_info *s, double angle, double dev)
{
	int		i;
	int		j;

	if (angle >= 0 && angle <= REDUND)
		calc_quadrant_1_0(s);
	else
	{
		i = calc_quadrant_1_i(s, angle);
		j = calc_quadrant_1_j(s, angle);
		if ((int)((0.5 + i) * SL) <= (int)((0.5 + j) * SL / tan(angle)))
		{
			s->its.x = s->stand.x + (int)((0.5 + i) * SL * tan(angle));
			s->its.y = s->stand.y - (int)((0.5 + i) * SL);
			s->length = (int)((0.5 + i) * SL) / cos(angle) * cos(dev);
			s->wall = 'N';
		}
		else
		{
			s->its.x = s->stand.x + (int)((0.5 + j) * SL);
			s->its.y = s->stand.y - (int)((0.5 + j) * SL / tan(angle));
			s->length = (int)((0.5 + j) * SL) / sin(angle) * cos(dev);
			s->wall = 'E';
		}
	}
}
