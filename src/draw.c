/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:53:54 by qdang             #+#    #+#             */
/*   Updated: 2020/07/29 16:36:55 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
*/

void	intersect(t_info *s, double radian)
{
    int     i;
    t_point up;
    t_point down;
    t_point left;
    t_point right;

    i = 1;
    up.x = s->start_y + s->move_y - i;
    up.y = s->start_x + s->move_x;
    down.x = s->start_y + s->move_y + i;
    down.y = s->start_x + s->move_x;
    left.x = s->start_y + s->move_y;
    left.y = s->start_x + s->move_x - i;    
    right.x = s->start_y + s->move_y;
    right.y = s->start_x + s->move_x + i;
    
    if (radian > 0 && radian < M_PI_2)
    {
        printf("up: %c\n", s->map[up.x][up.y]);
        printf("right: %c\n", s->map[right.x][right.y]);
    /*    
        if (s->map[up.x][up.y] == '0' && s->map[right.x][right.y] == '0')
        {
            i++;
            printf("i: %d\n", i);     
        }
    */
/*
        if (s->map[up.x][up.y] != '0')
            printf("UP: %d, %d\n", up.x, up.y);
        if (s->map[right.x][right.y] != '0')
            printf("Right: %d, %d\n", right.x, right.y);    
*/
    }
//	tan(radian);
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
    intersect(s, M_PI_4);
}
