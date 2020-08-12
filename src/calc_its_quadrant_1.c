/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_its_quadrant_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:27:35 by qdang             #+#    #+#             */
/*   Updated: 2020/08/12 14:25:42 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	calc_its_quadrant_1_i(t_info *s, double radian)
{
	int		temp_x;
	int		temp_y;
	char	c;
	int		i;

	i = 0;
	c = ' ';
	temp_y = s->grid_y - 1 - i;
	temp_x = s->grid_x + (int)(0.5 + (0.5 + i) * tan(radian));
	if (temp_y >= 0 && temp_x <= s->map_x - 1)
		c = s->map[temp_y][temp_x];
	while (c == '0' || c == s->start)
	{
		i++;
		temp_y = s->grid_y - 1 - i;
		temp_x = s->grid_x + (int)(0.5 + (0.5 + i) * tan(radian));
		if (temp_y >= 0 && temp_x <= s->map_x - 1)
			c = s->map[temp_y][temp_x];
		else
			break ;
	}
	return (i);
}

static int	calc_its_quadrant_1_j(t_info *s, double radian)
{
	int		temp_x;
	int		temp_y;
	char	c;
	int		j;

	j = 0;
	c = ' ';
	temp_y = s->grid_y - (int)(0.5 + (0.5 + j) / tan(radian));
	temp_x = s->grid_x + 1 + j;
	if (temp_y >= 0 && temp_x <= s->map_x - 1)
		c = s->map[temp_y][temp_x];
	while (c == '0' || c == s->start)
	{
		j++;
		temp_y = s->grid_y - (int)(0.5 + (0.5 + j) / tan(radian));
		temp_x = s->grid_x + 1 + j;
		if (temp_y >= 0 && temp_x <= s->map_x - 1)
			c = s->map[temp_y][temp_x];
		else
			break ;
	}
	return (j);
}

static void	calc_its_quadrant_1_0(t_info *s)
{
	char	c;
	int		i;

	i = 0;
	c = s->map[s->grid_y - 1][s->grid_x];
	while (c == '0' || c == s->start)
	{
		i++;
		c = s->map[s->grid_y - 1 - i][s->grid_x];
	}
	s->its_x = s->stand_x;
	s->its_y = s->stand_y - (int)((0.5 + i) * UL);
}

void		calc_its_quadrant_1(t_info *s, double radian)
{
	int		i;
	int		j;

	if (radian >= REDUND * -1 && radian <= REDUND)
		calc_its_quadrant_1_0(s);
	else
	{
		i = calc_its_quadrant_1_i(s, radian);
		j = calc_its_quadrant_1_j(s, radian);
		if ((int)((0.5 + i) * UL) <= (int)((0.5 + j) * UL / tan(radian)))
		{
			s->its_x = s->stand_x + (int)((0.5 + i) * UL * tan(radian));
			s->its_y = s->stand_y - (int)((0.5 + i) * UL);
		}
		else
		{
			s->its_x = s->stand_x + (int)((0.5 + j) * UL);
			s->its_y = s->stand_y - (int)((0.5 + j) * UL / tan(radian));
		}
	}
}
