/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 09:18:39 by qdang             #+#    #+#             */
/*   Updated: 2020/10/05 11:21:31 by qdang            ###   ########.fr       */
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

static void	store_sprite_2(t_info *s, t_sprite *sp, t_point loc, int k)
{
	double	ang_s;
	double	ang_e;

	sp[k].len =
		sqrt(pow(s->grid.x - loc.x, 2) + pow(s->grid.y - loc.y, 2)) * SL;
	loc.x == s->grid.x && loc.y > s->grid.y ? sp[k].ang = M_PI : 0;
	loc.x == s->grid.x && loc.y < s->grid.y ? sp[k].ang = 0 : 0;
	loc.x > s->grid.x && loc.y == s->grid.y ? sp[k].ang = M_PI_2 : 0;
	loc.x < s->grid.x && loc.y == s->grid.y ? sp[k].ang = M_PI_2 * 3 : 0;
	if (loc.x > s->grid.x && loc.y < s->grid.y)
		sp[k].ang = atan2(loc.x - s->grid.x, s->grid.y - loc.y);
	if (loc.x > s->grid.x && loc.y > s->grid.y)
		sp[k].ang = M_PI - atan2(loc.x - s->grid.x, loc.y - s->grid.y);
	if (loc.x < s->grid.x && loc.y > s->grid.y)
		sp[k].ang = M_PI + atan2(s->grid.x - loc.x, loc.y - s->grid.y);
	if (loc.x < s->grid.x && loc.y < s->grid.y)
		sp[k].ang = M_PI * 2 - atan2(s->grid.x - loc.x, s->grid.y - loc.y);
	sp[k].ang_rd = atan2(SL / 2, sp[k].len);
	ang_s = s->sight - sp[k].ang_rd;
	ang_e = s->sight + M_PI / 180 * FOV + sp[k].ang_rd;
	ang_e > M_PI * 2 ? ang_e -= M_PI * 2 : 0;
	if ((ang_e > ang_s && sp[k].ang >= ang_s && sp[k].ang <= ang_e) ||
		(ang_e < ang_s && (sp[k].ang >= ang_s || sp[k].ang <= ang_e)))
		sp[k].ex = 1;
}

void		store_sprite(t_info *s, t_sprite *sp, int nb)
{
	t_point	loc;
	int		k;

	k = -1;
	loc.y = -1;
	while (++loc.y < s->ms.y)
	{
		loc.x = -1;
		while (++loc.x < s->ms.x)
		{
			if (s->map[loc.y][loc.x] == '2' && ++k < nb)
			{
				sp[k].loc.x = loc.x;
				sp[k].loc.y = loc.y;
				store_sprite_2(s, sp, loc, k);
			}
		}
	}
}
