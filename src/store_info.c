/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:11:22 by qdang             #+#    #+#             */
/*   Updated: 2020/07/26 20:08:27 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	store_resolution(t_info *s, char **split)
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

static int	store_color_floor(t_info *s, char **split)
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

static int	store_color_ceiling(t_info *s, char **split)
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

static int	store_info_2(t_info *s, char *line)
{
	int		err;
	char	**split;

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
	else
		err = INFO_ERR;
	free_split(split);
	free(line);
	return (err);
}

/*
** Read from the file, store the resolution, color and texture info from it.
** Check the basic info of the map.
*/

int			store_info(t_info *s, int fd)
{
	int		i;
	int		err;
	char	*line;

	err = 0;
	while ((i = get_next_line(fd, &line)) != 0)
	{
		if (i < 0)
			return (READ_ERR);
		if (err == -1)
			return (check_map_2(line));
		if (line != NULL && s->sig_map != 1 &&
			ft_strchk(line, " ", 'B') != 1 && ft_strchk(line, "1", 'B') != 1)
			if ((err = store_info_2(s, line)) != 0)
				return (err);
		if (err != -1 && (err = check_map(line, s)) > 0)
			return (err);
	}
	if (s->sig_info != INFO_SIG)
		return (INFO_ERR);
	return (err);
}
