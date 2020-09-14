/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:41:38 by qdang             #+#    #+#             */
/*   Updated: 2020/09/13 21:12:08 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		close_scene(t_info *s)
{
	free_info(s);
//	system("leaks cub3D");	
	exit(0);
}

int		press_key(int key, t_info *s)
{
	double	turn;

	turn = 45 * M_PI / 180;
	key == ESC ? close_scene(s) : 0;
	key == LEFT ? s->sight -= turn : 0;
	key == RIGHT ? s->sight += turn : 0;
	key == W && check_stand(s, 0, -1) == 1 ? s->move.y-- : 0;
	key == A && check_stand(s, -1, 0) == 1 ? s->move.x-- : 0;
	key == S && check_stand(s, 0, 1) == 1 ? s->move.y++ : 0;
	key == D && check_stand(s, 1, 0) == 1 ? s->move.x++ : 0;

	draw(s);
	return (0);
}
