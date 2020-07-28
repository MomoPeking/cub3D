/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:53:54 by qdang             #+#    #+#             */
/*   Updated: 2020/07/27 18:36:40 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    draw_2dblock(t_info *s, int x, int y, int color)
{
    int     i;
    int     j;

    i = -1;
    while (++i < s->ul) 
    {
        j = -1;
        while (++j < s->ul)
            mlx_pixel_put(s->mlx_ptr, s->win_ptr, x + i, y + j, color);
    }
}

/*
** (x, y) on the screen is in the reversed order of (x, y) stored in the map.
*/

void    draw_2dmap(t_info *s)
{
    int     i;
    int     j;

    int     begin_x = 40;
    int     begin_y = 40;

    i = -1;
//    mlx_pixel_put(s->mlx_ptr, s->win_ptr, begin_y + (s->start_y + 0.5) * s->ul, begin_x + (s->start_x + 0.5) * s->ul, RED); 
    while (++i < s->map_y)
    {
        j = -1;
        while (++j < s->map_x)
        {
            if (s->map[i][j] == '1')
                draw_2dblock(s, begin_y + j * s->ul, begin_x + i * s->ul, WHITE);
            if (s->map[i][j] == '2')
                draw_2dblock(s, begin_y + j * s->ul, begin_x + i * s->ul, YELLOW);
        }
    }
}