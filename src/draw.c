/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:53:54 by qdang             #+#    #+#             */
/*   Updated: 2020/09/17 17:09:40 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** The block include the upper and left edges but not the lower and right edges.
*/

static void	draw_2d_block(t_info *s, int x, int y, int color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < SL)
	{
		j = -1;
		while (++j < SL)
			s->img_add[(i + y) * s->res.x + x + j] = color;
	}
}

static void	draw_2d_frame(t_info *s)
{
	int		i;
	int		j;

	i = -1;
	while (++i < s->ms.y)
	{
		j = -1;
		while (++j < s->ms.x)
		{
			if (s->map[i][j] == '1')
				draw_2d_block(s, j * SL, i * SL, BLACK);
			else if (s->map[i][j] == '2')
				draw_2d_block(s, j * SL, i * SL, RED);
		}
	}
}

static void	draw_2d_sight(t_info *s)
{
	int		i;
	int		j;

	i = -1;
	while (++i < s->ms.y)
	{
		j = -1;
		while (++j < s->ms.x)
			if (s->map[i][j] != '1' && s->map[i][j] != '2'
				&& s->map[i][j] != ' ')
				draw_2d_block(s, j * SL, i * SL, WHITE);
	}
	calculate(s, s->sight);
	draw_line(s, s->stand, s->its, BLUE);
	calculate(s, s->sight + M_PI / 180 * FOV);
	draw_line(s, s->stand, s->its, BLUE);
}

static void	draw_vline(t_info *s, int i)
{
	int		k;
	int		wall_up;
	int		wall_down;

	wall_up = s->res.y / 2 - s->wall_cf / s->length / 2;
	wall_down = s->res.y / 2 + s->wall_cf / s->length / 2;
	wall_up < 0 ? wall_up = 0 : 0;
	wall_down > s->res.y ? wall_down = s->res.y : 0;
	k = -1;
	while (++k < wall_up)
		s->img_add[k * s->res.x + i] = s->color_c;
	k--;
	if (s->wall == 'N')
		while (++k < wall_down)
			s->img_add[k * s->res.x + i] = LIME;
	if (s->wall == 'E')
		while (++k < wall_down)
			s->img_add[k * s->res.x + i] = BLUE;
	if (s->wall == 'S')
		while (++k < wall_down)
			s->img_add[k * s->res.x + i] = PINK;
	if (s->wall == 'W')
		while (++k < wall_down)
			s->img_add[k * s->res.x + i] = ORANGE;
	k--;
	while (++k < s->res.y)
		s->img_add[k * s->res.x + i] = s->color_f;
}

void		draw(t_info *s)
{
	int		i;
	double	angle;

	s->grid.x = s->sp.x + s->move.x;
	s->grid.y = s->sp.y + s->move.y;
	s->stand.x = (s->grid.x + 0.5) * SL;
	s->stand.y = (s->grid.y + 0.5) * SL;
	i = -1;
	while (++i < s->res.x)
	{
		angle = (double)(i + 1) / s->res.x * FOV;
		angle *= M_PI / 180;
		calculate(s, s->sight + angle);
		draw_vline(s, i);
	}
	draw_2d_sight(s);
	draw_2d_frame(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
}
