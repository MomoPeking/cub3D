/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 09:18:39 by qdang             #+#    #+#             */
/*   Updated: 2020/10/07 17:33:18 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			nb_sprite(t_info *s)
{
	int		i;
	int		j;
	int		ans;

	ans = 0;
	i = -1;
	while (++i < s->ms.y)
	{
		j = -1;
		while (++j < s->ms.x)
			if (s->map[i][j] == '2')
				ans++;
	}
	return (ans);
}

static void	store_sprite_2(t_info *s, t_sprite *sp, t_point loc, int i)
{
	double	ang_s;
	double	ang_e;

	sp[i].len_c =
		sqrt(pow(s->grid.x - loc.x, 2) + pow(s->grid.y - loc.y, 2)) * SL;
	loc.x == s->grid.x && loc.y > s->grid.y ? sp[i].ang = M_PI : 0;
	loc.x == s->grid.x && loc.y < s->grid.y ? sp[i].ang = 0 : 0;
	loc.x > s->grid.x && loc.y == s->grid.y ? sp[i].ang = M_PI_2 : 0;
	loc.x < s->grid.x && loc.y == s->grid.y ? sp[i].ang = M_PI_2 * 3 : 0;
	if (loc.x > s->grid.x && loc.y < s->grid.y)
		sp[i].ang = atan2(loc.x - s->grid.x, s->grid.y - loc.y);
	if (loc.x > s->grid.x && loc.y > s->grid.y)
		sp[i].ang = M_PI - atan2(loc.x - s->grid.x, loc.y - s->grid.y);
	if (loc.x < s->grid.x && loc.y > s->grid.y)
		sp[i].ang = M_PI + atan2(s->grid.x - loc.x, loc.y - s->grid.y);
	if (loc.x < s->grid.x && loc.y < s->grid.y)
		sp[i].ang = M_PI * 2 - atan2(s->grid.x - loc.x, s->grid.y - loc.y);
	sp[i].ang_rd = atan2(SL / 2, sp[i].len_c);
}

void		store_sprite(t_info *s, t_sprite *sp, int nb)
{
	t_point	loc;
	int		i;

	i = -1;
	loc.y = -1;
	while (++loc.y < s->ms.y)
	{
		loc.x = -1;
		while (++loc.x < s->ms.x)
		{
			if (s->map[loc.y][loc.x] == '2' && ++i < nb)
			{
				sp[i].loc.x = loc.x;
				sp[i].loc.y = loc.y;
				store_sprite_2(s, sp, loc, i);
			}
		}
	}
}

void		sort_sprite(t_sprite *sp, int nb)
{
	int			i;
	int			j;
	int			k;
	t_sprite	temp;

	i = -1;
	while (++i < nb)
	{
		temp = sp[i];
		j = i;
		k = -1;
		while (++j < nb)
		{
			if (sp[j].len_c > temp.len_c)
			{
				temp = sp[j];
				k = j;
			}
		}
		if (k != -1)
		{
			sp[k] = sp[i];
			sp[i] = temp;
		}
	}
}

void		draw_sprite(t_info *s, t_sprite *sp, int i, int j)
{
	int		k;
	t_wall	w;
	int		temp;
	int		sprite;

	w.up = s->res.y / 2 - s->wall_cf / sp[j].len_c / 2;
	w.down = s->res.y / 2 + s->wall_cf / sp[j].len_c / 2;
	w.h = w.down - w.up;
	w.up < 0 ? w.up = 0 : 0;
	w.down > s->res.y ? w.down = s->res.y : 0;
	k = w.up - 1;
	temp = k;
	while (++k < w.down - 1)
	{
		if (w.h <= s->res.y)
			sp[j].tex.y = (k - temp) * 64 / w.h;
		else
			sp[j].tex.y = (double)(k * 64 + (w.h - s->res.y) * 32) / w.h;
		if ((sprite = s->s_add[sp[j].tex.y * 64 + sp[j].tex.x]) != HOLLOW)
			s->img_add[k * s->sl + i] =
				s->s_add[sp[j].tex.y * 64 + sp[j].tex.x];
	}
}
