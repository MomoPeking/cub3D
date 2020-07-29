/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:41:38 by qdang             #+#    #+#             */
/*   Updated: 2020/07/29 15:26:25 by qdang            ###   ########.fr       */
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
	draw_2d_map(s);
//	printf("move_x: %d, move_y: %d\n", s->move_x, s->move_y);
//	printf("stand_x: %d, stand_y: %d\n", s->stand_x, s->stand_y);
//	printf("%d\n", (int)(s->stand_x + (0 + 0.5) * UL - BEGIN_X) / UL);	
	return (0);
}
