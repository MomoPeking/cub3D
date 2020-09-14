/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:41:38 by qdang             #+#    #+#             */
/*   Updated: 2020/09/14 15:22:05 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	press_arrow_quadrant_1(int key, t_info *s)
{
	if (s->sight >= 0 && s->sight < M_PI_2 * 0.5)
	{
		key == W && check_stand(s, 1, -1) == 1 ? s->move.x++ : 0;
		key == W && check_stand(s, 1, -1) == 1 ? s->move.y-- : 0;
		key == A && check_stand(s, -1, -1) == 1 ? s->move.x-- : 0;
		key == A && check_stand(s, -1, -1) == 1 ? s->move.y-- : 0;
		key == S && check_stand(s, -1, 1) == 1 ? s->move.x-- : 0;
		key == S && check_stand(s, -1, 1) == 1 ? s->move.y++ : 0;
		key == D && check_stand(s, 1, 1) == 1 ? s->move.x++ : 0;
		key == D && check_stand(s, 1, 1) == 1 ? s->move.y++ : 0;
	}
	if (s->sight >= M_PI_2 * 0.5 && s->sight < M_PI_2)
	{
		key == W && check_stand(s, 1, 0) == 1 ? s->move.x++ : 0;
		key == A && check_stand(s, 0, -1) == 1 ? s->move.y-- : 0;
		key == S && check_stand(s, -1, 0) == 1 ? s->move.x-- : 0;
		key == D && check_stand(s, 0, 1) == 1 ? s->move.y++ : 0;
	}
}

static void	press_arrow_quadrant_4(int key, t_info *s)
{
	if (s->sight >= M_PI_2 && s->sight < M_PI_2 * 1.5)
	{
		key == W && check_stand(s, 1, 1) == 1 ? s->move.x++ : 0;
		key == W && check_stand(s, 1, 1) == 1 ? s->move.y++ : 0;
		key == A && check_stand(s, 1, -1) == 1 ? s->move.x++ : 0;
		key == A && check_stand(s, 1, -1) == 1 ? s->move.y-- : 0;
		key == S && check_stand(s, -1, -1) == 1 ? s->move.x-- : 0;
		key == S && check_stand(s, -1, -1) == 1 ? s->move.y-- : 0;
		key == D && check_stand(s, -1, 1) == 1 ? s->move.x-- : 0;
		key == D && check_stand(s, -1, 1) == 1 ? s->move.y++ : 0;
	}
	if (s->sight >= M_PI_2 * 1.5 && s->sight < M_PI)
	{
		key == W && check_stand(s, 0, 1) == 1 ? s->move.y++ : 0;
		key == A && check_stand(s, 1, 0) == 1 ? s->move.x++ : 0;
		key == S && check_stand(s, 0, -1) == 1 ? s->move.y-- : 0;
		key == D && check_stand(s, -1, 0) == 1 ? s->move.x-- : 0;
	}
}

static void	press_arrow_quadrant_3(int key, t_info *s)
{
	if (s->sight >= M_PI && s->sight < M_PI_2 * 2.5)
	{
		key == W && check_stand(s, -1, 1) == 1 ? s->move.x-- : 0;
		key == W && check_stand(s, -1, 1) == 1 ? s->move.y++ : 0;
		key == A && check_stand(s, 1, 1) == 1 ? s->move.x++ : 0;
		key == A && check_stand(s, 1, 1) == 1 ? s->move.y++ : 0;
		key == S && check_stand(s, 1, -1) == 1 ? s->move.x++ : 0;
		key == S && check_stand(s, 1, -1) == 1 ? s->move.y-- : 0;
		key == D && check_stand(s, -1, -1) == 1 ? s->move.x-- : 0;
		key == D && check_stand(s, -1, -1) == 1 ? s->move.y-- : 0;
	}
	if (s->sight >= M_PI_2 * 2.5 && s->sight < M_PI_2 * 3)
	{
		key == W && check_stand(s, -1, 0) == 1 ? s->move.x-- : 0;
		key == A && check_stand(s, 0, 1) == 1 ? s->move.y++ : 0;
		key == S && check_stand(s, 1, 0) == 1 ? s->move.x++ : 0;
		key == D && check_stand(s, 0, -1) == 1 ? s->move.y-- : 0;
	}
}

static void	press_arrow_quadrant_2(int key, t_info *s)
{
	if (s->sight >= M_PI_2 * 3 && s->sight < M_PI_2 * 3.5)
	{
		key == W && check_stand(s, -1, -1) == 1 ? s->move.x-- : 0;
		key == W && check_stand(s, -1, -1) == 1 ? s->move.y-- : 0;
		key == A && check_stand(s, -1, 1) == 1 ? s->move.x-- : 0;
		key == A && check_stand(s, -1, 1) == 1 ? s->move.y++ : 0;
		key == S && check_stand(s, 1, 1) == 1 ? s->move.x++ : 0;
		key == S && check_stand(s, 1, 1) == 1 ? s->move.y++ : 0;
		key == D && check_stand(s, 1, -1) == 1 ? s->move.x++ : 0;
		key == D && check_stand(s, 1, -1) == 1 ? s->move.y-- : 0;
	}
	if (s->sight >= M_PI_2 * 3.5 && s->sight < M_PI * 2)
	{
		key == W && check_stand(s, 0, -1) == 1 ? s->move.y-- : 0;
		key == A && check_stand(s, -1, 0) == 1 ? s->move.x-- : 0;
		key == S && check_stand(s, 0, 1) == 1 ? s->move.y++ : 0;
		key == D && check_stand(s, 1, 0) == 1 ? s->move.x++ : 0;
	}
}

int			press_key(int key, t_info *s)
{
	double	turn;

	turn = TURN * M_PI / 180;
	key == ESC ? close_scene(s) : 0;
	key == LEFT ? s->sight -= turn : 0;
	key == RIGHT ? s->sight += turn : 0;
	while (s->sight < 0)
		s->sight += M_PI * 2;
	while (s->sight >= M_PI * 2)
		s->sight -= M_PI * 2;
	press_arrow_quadrant_1(key, s);
	press_arrow_quadrant_4(key, s);
	press_arrow_quadrant_3(key, s);
	press_arrow_quadrant_2(key, s);
	draw(s);
	return (0);
}
