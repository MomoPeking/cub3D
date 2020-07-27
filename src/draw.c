/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:53:54 by qdang             #+#    #+#             */
/*   Updated: 2020/07/27 15:39:59 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    draw_2dblock(t_info *s, int x, int y)
{
    int     i;
    int     j;

    i = -1;
    while (++i < s->ul) 
    {
        j = -1;
        while (++j < s->ul)
            mlx_pixel_put(s->mlx_ptr, s->win_ptr, x + i, y + j, RED);
    }
}

void    draw_2dmap(t_info *s)
{
    int     i;
    int     j;

    int     begin_x = 40;
    int     begin_y = 40;

    i = -1;
    while (++i < 5)
    {
        j = -1;
        while (++j < 10)
        {
            if (s->map[i][j])
                draw_2dblock(s, begin_x + i * s->ul, begin_y + i * s->ul);
        }
    }
}