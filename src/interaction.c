/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:41:38 by qdang             #+#    #+#             */
/*   Updated: 2020/08/12 14:12:41 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		close_scene(t_info *s)
{
	free_info(s);
	exit(0);
}

int		press_key(int key, t_info *s)
{
	key == ESC ? close_scene(s): 0;
	key == W && check_stand(s, 0, -1) == 1 ? s->move_y-- : 0;
	key == A && check_stand(s, -1, 0) == 1 ? s->move_x-- : 0;
	key == S && check_stand(s, 0, 1) == 1 ? s->move_y++ : 0;
	key == D && check_stand(s, 1, 0) == 1 ? s->move_x++ : 0;
	key == LEFT ? s->start_sight -= M_PI / 180 * TURN : 0;
	key == RIGHT ? s->start_sight += M_PI / 180 * TURN : 0;
	draw_2d_map(s);
	return (0);
}
