/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:11:22 by qdang             #+#    #+#             */
/*   Updated: 2020/07/20 18:34:38 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		store_resolution(t_info *s, char **split)
{
	if (count_split(split) != 3)
		return (R_ERR);
	if (check_unsigned_int(split[1]) == 0 || check_unsigned_int(split[2]) == 0)
		return (R_ERR);
	s->r_x = ft_atoi(split[1]);
	s->r_y = ft_atoi(split[2]);
	if (s->r_x == 0 || s->r_y == 0)
		return (R_ERR);
	s->signal *= R_SIG;
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
	s->signal *= F_SIG;
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
	s->signal *= C_SIG;
	return (0);	
}

int		store_info(t_info *s, int fd)
{
	int		i;
	int		err;	
	char	*line;
	char	**split;

	err = 0;
	while ((i = get_next_line(fd, &line)) != 0 )
	{
		if (i < 0)
			return (READ_ERR);
		split = ft_strsplit(line, ' ');
		if (split != NULL && ft_strcmp(split[0], "R") == 0)
			err = store_resolution(s, split);
		else if (split != NULL && ft_strcmp(split[0], "NO") == 0)
			err = store_texture_no(s, split);
		else if (split != NULL && ft_strcmp(split[0], "SO") == 0)
			err = store_texture_so(s, split);
		else if (split != NULL && ft_strcmp(split[0], "WE") == 0)
			err = store_texture_we(s, split);
		else if (split != NULL && ft_strcmp(split[0], "EA") == 0)
			err = store_texture_ea(s, split);
		else if (split != NULL && ft_strcmp(split[0], "S") == 0)
			err = store_texture_s(s, split);
		else if (split != NULL && ft_strcmp(split[0], "F") == 0)
			err = store_color_floor(s, split);
		else if (split != NULL && ft_strcmp(split[0], "C") == 0)
			err = store_color_ceiling(s, split);

//		更改所有的split

/*		read 函數的特點，一直往下走！
		解决储存 / 驗證地图的问题：地圖不能空行。
		1. 先過一邊，知道多少行多少列
		2. malloc地圖，並存儲
		3. 在邊緣的，
		如何描述：最外圍？
		如果有其他信息怎麼辦？	待會兒再說，先解決地圖！		
*/
		free_split(split);
		free(line);
		if (err != 0)
			return (err);
	}
	if (s->signal != INFO_SIG)
		return (INFO_ERR);
	return (err);
}