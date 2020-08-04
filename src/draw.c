/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:53:54 by qdang             #+#    #+#             */
/*   Updated: 2020/08/03 18:12:44 by qdang            ###   ########.fr       */
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
	
	int		temp_x;
	int		temp_y;
	
	i = 0;
	j = 0;
	
	grid_x = s->start_x + s->move_x;	
	grid_y = s->start_y + s->move_y;
	
	if (radian == 0)
	{
		c = s->map[grid_y - 1][grid_x];
		while (c == '0' || c == s->start)
		{
			i++;
			c = s->map[grid_y - 1 - i][grid_x];
		}
		s->its_x = s->stand_x;
		s->its_y = s->stand_y - (int)((0.5 + i) * UL);
	}
	
	if (radian > 0 && radian < M_PI_2)
    {
		temp_y = grid_y - 1 - i;
		temp_x = grid_x + (int)(0.5 + (0.5 + i) * tan(radian));
		if (temp_y >= 0 && temp_x <= s->map_x - 1)
			c = s->map[temp_y][temp_x];
		while (c == '0' || c == s->start)
		{
			i++;
			temp_y = grid_y - 1 - i;
			temp_x = grid_x + (int)(0.5 + (0.5 + i) * tan(radian));
			if (temp_y >= 0 && temp_x <= s->map_x - 1)
				c = s->map[temp_y][temp_x];
			else
				break;				
		}
		temp_y = grid_y - (int)(0.5 + (0.5 + j) / tan(radian));
		temp_x = grid_x + 1 + j;
		if (temp_y >= 0 && temp_x <= s->map_x - 1)
			c = s->map[temp_y][temp_x];	
		while (c == '0' || c == s->start)
		{
			j++;
			temp_y = grid_y - (int)(0.5 + (0.5 + j) / tan(radian));
			temp_x = grid_x + 1 + j;
			if (temp_y >= 0 && temp_x <= s->map_x - 1)
				c = s->map[temp_y][temp_x];			
			else
				break;
		}
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

	if (radian == M_PI_2)
	{
		c = s->map[grid_y][grid_x + 1];
		while (c == '0' || c == s->start)
		{
			i++;
			c = s->map[grid_y][grid_x + 1 + i];
		}
		s->its_x = s->stand_x + (int)((0.5 + i) * UL - 1);
		s->its_y = s->stand_y;	
	}


	if (radian > M_PI_2 && radian < M_PI)
	{
		radian -= M_PI_2;

		temp_y = grid_y + (int)(0.5 + (0.5 + i) * tan(radian));
		temp_x = grid_x + 1 + i;
		if (temp_y <= s->map_y - 1 && temp_x <= s->map_x - 1)
			c = s->map[temp_y][temp_x];
		while (c == '0' || c == s->start)
		{
			i++;
			temp_y = grid_y + (int)(0.5 + (0.5 + i) * tan(radian));
			temp_x = grid_x + 1 + i;
			if (temp_y <= s->map_y - 1 && temp_x <= s->map_x - 1)
				c = s->map[temp_y][temp_x];
			else
				break;			
		}

		temp_y = grid_y + 1 + j;
		temp_x = grid_x + (int)(0.5 + (0.5 + j) / tan(radian));
		if (temp_y <= s->map_y - 1 && temp_x <= s->map_x - 1)
			c = s->map[temp_y][temp_x];
		while (c == '0' || c == s->start)
		{
			j++;
			temp_y = grid_y + 1 + j;
			temp_x = grid_x + (int)(0.5 + (0.5 + j) / tan(radian));
			if (temp_y <= s->map_y - 1 && temp_x <= s->map_x - 1)
				c = s->map[temp_y][temp_x];
			else
				break;
		}

		
		if ((int)((0.5 + i) * UL) <= (int)((0.5 + j) * UL / tan(radian)))
		{
			s->its_x = s->stand_x + (int)((0.5 + i) * UL) ;
			s->its_y = s->stand_y + (int)((0.5 + i) * UL * tan(radian));
		}
		else
		{
			s->its_x = s->stand_x + (int)((0.5 + j) * UL / tan(radian));		
			s->its_y = s->stand_y + (int)((0.5 + j) * UL);
		}
	}
}

/*
** (x, y) on the screen is in the reversed order of (x, y) stored in the map.
*/

void    draw_2d_map(t_info *s)
{
    int     i;
    int     j;

	mlx_clear_window(s->mlx_ptr, s->win_ptr);

	s->stand_x = BEGIN_X + (s->start_x + s->move_x + 0.5) * UL;
	s->stand_y = BEGIN_Y + (s->start_y + s->move_y + 0.5) * UL;
/*
	i = -1;
	while (++i <= 1000)
	{
		intersect(s, (double)(0.001 * i));
		draw_line(s, s->its_x, s->its_y, RED);
	}
*/

	intersect(s, 1);
	draw_line(s, s->its_x, s->its_y, RED);
	intersect(s, 1.5);
	draw_line(s, s->its_x, s->its_y, RED);
	intersect(s, 2);
	draw_line(s, s->its_x, s->its_y, RED);
	intersect(s, 2.5);
	draw_line(s, s->its_x, s->its_y, RED);	


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

	
//	intersect(s, 0.15);
//	draw_line(s, s->its_x, s->its_y, RED);

}
