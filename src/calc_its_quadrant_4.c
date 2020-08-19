/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_its_quadrant_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:34:25 by qdang             #+#    #+#             */
/*   Updated: 2020/08/18 22:51:54 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	calc_its_quadrant_4_i(t_info *s, double radian)
{
	int		temp_x;
	int		temp_y;
	char	c;
	int		i;

	i = 0;
	c = ' ';
	temp_y = s->grid.y + (int)(0.5 + (0.5 + i) * tan(radian));
	temp_x = s->grid.x + 1 + i;
	if (temp_y <= s->ms.y - 1 && temp_x <= s->ms.x - 1)
		c = s->map[temp_y][temp_x];
	while (c == '0' || c == s->start)
	{
		i++;
		temp_y = s->grid.y + (int)(0.5 + (0.5 + i) * tan(radian));
		temp_x = s->grid.x + 1 + i;
		if (temp_y <= s->ms.y - 1 && temp_x <= s->ms.x - 1)
			c = s->map[temp_y][temp_x];
		else
			break ;
	}
	return (i);
}

static int	calc_its_quadrant_4_j(t_info *s, double radian)
{
	int		temp_x;
	int		temp_y;
	char	c;
	int		j;

	j = 0;
	c = ' ';
	temp_y = s->grid.y + 1 + j;
	temp_x = s->grid.x + (int)(0.5 + (0.5 + j) / tan(radian));
	if (temp_y <= s->ms.y - 1 && temp_x <= s->ms.x - 1)
		c = s->map[temp_y][temp_x];
	while (c == '0' || c == s->start)
	{
		j++;
		temp_y = s->grid.y + 1 + j;
		temp_x = s->grid.x + (int)(0.5 + (0.5 + j) / tan(radian));
		if (temp_y <= s->ms.y - 1 && temp_x <= s->ms.x - 1)
			c = s->map[temp_y][temp_x];
		else
			break ;
	}
	return (j);
}

static void	calc_its_quadrant_4_0(t_info *s)
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
	s->its.x = s->stand.x + (int)((0.5 + i) * UL);
	s->its.y = s->stand.y;
}

void		calc_its_quadrant_4(t_info *s, double radian)
{
	int		i;
	int		j;

	if (radian >= M_PI_2 - REDUND && radian <= M_PI_2 + REDUND)
		calc_its_quadrant_4_0(s);
	else
	{
		radian -= M_PI_2;
		i = calc_its_quadrant_4_i(s, radian);
		j = calc_its_quadrant_4_j(s, radian);
		if ((int)((0.5 + i) * UL) <= (int)((0.5 + j) * UL / tan(radian)))
		{
			s->its.x = s->stand.x + (int)((0.5 + i) * UL);
			s->its.y = s->stand.y + (int)((0.5 + i) * UL * tan(radian));
		}
		else
		{
			s->its.x = s->stand.x + (int)((0.5 + j) * UL / tan(radian));
			s->its.y = s->stand.y + (int)((0.5 + j) * UL);
		}
	}
}
