/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:38:23 by qdang             #+#    #+#             */
/*   Updated: 2020/08/04 16:35:47 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		store_resolution(t_info *s, char **split)
{
	if (count_split(split) != 3)
		return (RES_ERR);
	if (check_unsigned_int(split[1]) == 0 || check_unsigned_int(split[2]) == 0)
		return (RES_ERR);
	s->r_x = ft_atoi(split[1]);
	s->r_y = ft_atoi(split[2]);
	if (s->r_x == 0 || s->r_y == 0)
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
	s->f_r = ft_atoi(color[0]);
	s->f_g = ft_atoi(color[1]);
	s->f_b = ft_atoi(color[2]);
	if (s->f_r > 255 || s->f_r < 0 || s->f_g > 255 ||
		s->f_g < 0 || s->f_b > 255 || s->f_b < 0)
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
	s->c_r = ft_atoi(color[0]);
	s->c_g = ft_atoi(color[1]);
	s->c_b = ft_atoi(color[2]);
	if (s->c_r > 255 || s->c_r < 0 || s->c_g > 255 ||
		s->c_g < 0 || s->c_b > 255 || s->c_b < 0)
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
	s->start_x = j;
	s->start_y = i;
	s->start = s->map[i][j];
	s->start == 'N' ? s->start_sight = (0 - (M_PI / 180 * FOV) / 2) : 0;
	s->start == 'W' ? s->start_sight = M_PI_2 - (M_PI / 180 * FOV) / 2 : 0;
	s->start == 'S' ? s->start_sight = M_PI - (M_PI / 180 * FOV) / 2 : 0;
	s->start == 'E' ? s->start_sight = M_PI_2 * 3 - (M_PI / 180 * FOV) / 2 : 0;
	return (1);
}
