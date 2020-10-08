/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:11:22 by qdang             #+#    #+#             */
/*   Updated: 2020/10/07 17:22:33 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	store_map(t_info *s, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	s->map = ft_mapnew(s->ms.x, s->ms.y, ' ');
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_strchk(line, " ", 'B') == 1 || ft_strchk(line, "1", 'B') == 1)
		{
			j = 0;
			while (line[j])
			{
				s->map[i][j] = line[j];
				j++;
			}
			i++;
		}
		free(line);
	}
	return (check_map_3(s));
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
		err = store_color(s, split, 'F');
	else if (split != NULL && ft_strcmp(split[0], "C") == 0)
		err = store_color(s, split, 'C');
	else
		err = INFO_ERR;
	free_split(split);
	free(line);
	return (err);
}

static int	store_info(t_info *s, int fd)
{
	int		i;
	int		err;
	char	*line;

	err = 0;
	while ((i = get_next_line(fd, &line)) != 0)
	{
		if (i < 0)
			return (READ_ERR);
		if (err == -1 && (err = check_map_2(line)) != 0)
			return (err);
		if (line != NULL && s->sig_map != '1' &&
			ft_strchk(line, " ", 'B') != 1 && ft_strchk(line, "1", 'B') != 1)
			if ((err = store_info_2(s, line)) != 0)
				return (err);
		if (err != -1 && (err = check_map(line, s)) > 0)
			return (err);
	}
	s->wall_cf = s->res.x * SL / 2 / tan(FOV / 2 * M_PI / 180);
	s->sig_info != INFO_SIG ? err = INFO_ERR : 0;
	s->ms.x <= 0 || s->ms.y <= 0 ? err = MAP_ERR : 0;
	return (err);
}

int			read_and_store(char *file, t_info *s)
{
	int		err;
	int		fd;

	if (ft_strchk(file, ".cub", 'E') == 1)
	{
		if ((fd = open(file, O_RDONLY)) == -1)
			err = OPEN_ERR;
		else
		{
			err = store_info(s, fd);
			close(fd) == -1 ? err = CLOSE_ERR : 0;
			if (err == 0 || err == -1)
			{
				fd = open(file, O_RDONLY);
				err = store_map(s, fd);
				err == 0 && close(fd) == -1 ? err = CLOSE_ERR : 0;
			}
		}
	}
	else
		err = END_ERR;
	return (err);
}
