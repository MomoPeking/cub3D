/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:53:54 by qdang             #+#    #+#             */
/*   Updated: 2020/08/03 12:21:33 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** The block include the upper and left edges but not the lower and right edges.
*/

void    draw_2d_block(t_info *s, int x, int y, int color)
{
    int     i;
    int     j;

    i = -1;
    while (++i < UL)
    {
        j = -1;
        while (++j < UL)
            mlx_pixel_put(s->mlx_ptr, s->win_ptr, x + i, y + j, color);
    }
}

/*
** Use stand_x/y and the radian to calculate the its_x/y.
** The sight touch the lower and right edges but not the upper and the left.
*/

void	intersect(t_info *s, double radian)
{
    int     i;
	int		j;
	char	c;
	int		grid_x;
	int		grid_y;
	
	i = 0;
	j = 0;
	grid_x = s->start_y + s->move_y;
	grid_y = s->start_x + s->move_x;

	if (radian == 0)
	{
		c = s->map[grid_x - 1][grid_y];
		while (c == '0' || c == s->start)
		{
			i++;
			c = s->map[grid_x - 1 - i][grid_y];
		}
		s->its_x = s->stand_x;
		s->its_y = s->stand_y - (int)((0.5 + i) * UL);
	}
	
	if (radian > 0 && radian < M_PI_2)
    {
		c = s->map[grid_x - 1][grid_y + (int)(0.5 + 0.5 * tan(radian))];
		while (c == '0' || c == s->start)
		{
			i++;
			c = s->map[grid_x - 1 - i][grid_y + (int)(0.5 + (0.5 + i) * tan(radian))];
		}
		c = s->map[grid_x - (int)(0.5 + 0.5 / tan(radian))][grid_y + 1];
		while (c == '0' || c == s->start)
		{
			j++;
			c = s->map[grid_x - (int)(0.5 + (0.5 + j) / tan(radian))][grid_y + 1 + j];
		}
		if ((int)((0.5 + i) * UL) <= (int)((0.5 + j) * UL / tan(radian)))
		{
			s->its_x = s->stand_x + (int)((0.5 + i) * UL * tan(radian));
			s->its_y = s->stand_y - (int)((0.5 + i) * UL);
		}
		else
		{
			s->its_x = s->stand_x + (int)((0.5 + j) * UL - 1);		
			s->its_y = s->stand_y - (int)((0.5 + j) * UL / tan(radian));
		}
	}

	if (radian == M_PI_2)
	{
		c = s->map[grid_x][grid_y + 1];
		while (c == '0' || c == s->start)
		{
			i++;
			c = s->map[grid_x][grid_y + 1 + i];
		}
		s->its_x = s->stand_x + (int)((0.5 + i) * UL - 1);
		s->its_y = s->stand_y;	
	}
/*	
	if (radian > M_PI_2 && radian < M_PI)
	{
		c = s->map[grid_x + (int)(0.5 - 0.5 / tan(radian))][grid_y + 1];
		while (c == '0' || c == s->start)
		{
			i++;
			c = s->map[grid_x + (int)(0.5 - (0.5 + i) / tan(radian))][grid_y + 1 + i];
		}
		c = s->map[grid_x + 1][grid_y + (int)(0.5 - 0.5 * tan(radian))];
		while (c == '0' || c == s->start)
		{
			j++;
			c = s->map[grid_x + 1 + j][grid_y + (int)(0.5 - (0.5 + j) * tan(radian))];
		}
		
		if ((int)((0.5 + i) * UL) <= (int)((0.5 + j) * UL / tan(radian)))
		{
			s->its_x = s->stand_x + (int)((0.5 + i) * UL * tan(radian));
			s->its_y = s->stand_y - (int)((0.5 + i) * UL);
		}
		else
		{
			s->its_x = s->stand_x + (int)((0.5 + j) * UL - 1);		
			s->its_y = s->stand_y - (int)((0.5 + j) * UL / tan(radian));
		}
*/		
}

/*
** (x, y) on the screen is in the reversed order of (x, y) stored in the map.
*/

void    draw_2d_map(t_info *s)
{
    int     i;
    int     j;

	mlx_clear_window(s->mlx_ptr, s->win_ptr);
    i = -1;
    while (++i < s->map_y)
    {
        j = -1;
        while (++j < s->map_x)
        {
            if (s->map[i][j] == '1')
                draw_2d_block(s, BEGIN_X + j * UL, BEGIN_Y + i * UL, WHITE);
            if (s->map[i][j] == '2')
                draw_2d_block(s, BEGIN_X + j * UL, BEGIN_Y + i * UL, YELLOW);
        }
    }
	s->stand_x = BEGIN_X + (s->start_x + s->move_x + 0.5) * UL;
	s->stand_y = BEGIN_Y + (s->start_y + s->move_y + 0.5) * UL;
	mlx_pixel_put(s->mlx_ptr, s->win_ptr, s->stand_x, s->stand_y, RED);
	i = -1;
//	while (++i <= 50)
//		draw_line(s, 250, 200 + i, RED);
	
	intersect(s, 1);
	draw_line(s, s->its_x, s->its_y, RED);

/*
	i = -1;
	while (++i <= 20)
	{
		intersect(s, (double)(0.05 * i));
		draw_line(s, s->its_x, s->its_y, RED);
	}
*/
}
