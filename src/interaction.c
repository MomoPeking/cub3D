/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:41:38 by qdang             #+#    #+#             */
/*   Updated: 2020/07/28 19:40:28 by qdang            ###   ########.fr       */
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
//	printf("x: %d, y: %d\n", s->start_x + s->move_x, s->start_y + s->move_y);
	printf("x: %d, y: %d\n", s->stand_x, s->stand_y);
	draw_2d_map(s);
//	printf("x: %d, y: %d\n", s->move_x, s->move_y);
	return (0);
}
