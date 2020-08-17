/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:42:45 by qdang             #+#    #+#             */
/*   Updated: 2020/08/16 17:49:24 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		count_split(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		check_unsigned_int(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int		check_color(char **color)
{
	if (count_split(color) != 3)
	{
		free_split(color);
		return (COL_ERR);
	}
	if (check_unsigned_int(color[0]) == 0 || check_unsigned_int(color[1]) == 0
		|| check_unsigned_int(color[2]) == 0)
	{
		free_split(color);
		return (COL_ERR);
	}
	return (0);
}

/*
** Check if the player stands on right place of the map.
** i.e. where is "0" or "N/E/W/S".
*/

int		check_stand(t_info *s, int x, int y)
{
	if (s->map[s->grid_y + y][s->grid_x + x] == '0' ||
		s->map[s->grid_y + y][s->grid_x + x] == s->start)
		return (1);
	else
		return (0);
}
