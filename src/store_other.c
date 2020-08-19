/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:38:23 by qdang             #+#    #+#             */
/*   Updated: 2020/08/18 22:40:24 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		store_resolution(t_info *s, char **split)
{
	if (count_split(split) != 3)
		return (RES_ERR);
	if (check_unsigned_int(split[1]) == 0 || check_unsigned_int(split[2]) == 0)
		return (RES_ERR);
	s->res.x = ft_atoi(split[1]);
	s->res.y = ft_atoi(split[2]);
	if (s->res.x == 0 || s->res.y == 0)
		return (RES_ERR);
	s->sig_info *= R_SIG;
	return (0);
}

int		store_color_floor(t_info *s, char **split)
{
	char	**color;

	if (count_split(split) != 2 || (ft_strchk(split[1], ",", 'E') == 1))
		return (COL_ERR);
	color = ft_strsplit(split[1], ',');
	if (check_color(color) == COL_ERR)
		return (COL_ERR);
	s->floor.r = ft_atoi(color[0]);
	s->floor.g = ft_atoi(color[1]);
	s->floor.b = ft_atoi(color[2]);
	if (s->floor.r > 255 || s->floor.r < 0 || s->floor.g > 255 ||
		s->floor.g < 0 || s->floor.b > 255 || s->floor.b < 0)
	{
		free_split(color);
		return (COL_ERR);
	}
	free_split(color);
	s->sig_info *= F_SIG;
	return (0);
}

int		store_color_ceiling(t_info *s, char **split)
{
	char	**color;

	if (count_split(split) != 2 || (ft_strchk(split[1], ",", 'E') == 1))
		return (COL_ERR);
	color = ft_strsplit(split[1], ',');
	if (check_color(color) == COL_ERR)
		return (COL_ERR);
	s->ceiling.r = ft_atoi(color[0]);
	s->ceiling.g = ft_atoi(color[1]);
	s->ceiling.b = ft_atoi(color[2]);
	if (s->ceiling.r > 255 || s->ceiling.r < 0 || s->ceiling.g > 255 ||
		s->ceiling.g < 0 || s->ceiling.b > 255 || s->ceiling.b < 0)
	{
		free_split(color);
		return (COL_ERR);
	}
	free_split(color);
	s->sig_info *= C_SIG;
	return (0);
}

int		store_start(t_info *s, int i, int j)
{
	s->sp.x = j;
	s->sp.y = i;
	s->start = s->map[i][j];
	s->start == 'N' ? s->sight_m = 0 : 0;
	s->start == 'E' ? s->sight_m = M_PI_2 : 0;
	s->start == 'S' ? s->sight_m = M_PI : 0;
	s->start == 'W' ? s->sight_m = M_PI_2 * 3 : 0;
	return (1);
}
