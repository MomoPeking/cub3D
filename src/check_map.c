/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:23:41 by qdang             #+#    #+#             */
/*   Updated: 2020/09/15 11:57:15 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** Check if the map is surround by "1".
** Namely, all " " are only next to " " or "1" and no " " is surround by "1".
*/

static int	check_map_5(t_info *s, int i, int j)
{
	if ((i - 1 >= 0 && s->map[i - 1][j] != ' ' && s->map[i - 1][j] != '1') ||
		(i + 1 < s->ms.y && s->map[i + 1][j] != ' ' && s->map[i + 1][j] != '1'))
		return (MAP_ERR);
	if ((j - 1 >= 0 && s->map[i][j - 1] != ' ' && s->map[i][j - 1] != '1') ||
		(j + 1 < s->ms.x && s->map[i][j + 1] != ' ' && s->map[i][j + 1] != '1'))
		return (MAP_ERR);
	if (i - 1 >= 0 && j - 1 >= 0 &&
		s->map[i - 1][j - 1] != ' ' && s->map[i - 1][j - 1] != '1')
		return (MAP_ERR);
	if (i - 1 >= 0 && j + 1 < s->ms.x &&
		s->map[i - 1][j + 1] != ' ' && s->map[i - 1][j + 1] != '1')
		return (MAP_ERR);
	if (i + 1 < s->ms.y && j - 1 >= 0 &&
		s->map[i + 1][j - 1] != ' ' && s->map[i + 1][j - 1] != '1')
		return (MAP_ERR);
	if (i + 1 < s->ms.y && j + 1 < s->ms.x &&
		s->map[i + 1][j + 1] != ' ' && s->map[i + 1][j + 1] != '1')
		return (MAP_ERR);
	if (i - 1 >= 0 && i + 1 < s->ms.y && j - 1 >= 0 && j + 1 < s->ms.x &&
		s->map[i - 1][j - 1] == '1' && s->map[i][j - 1] == '1' &&
		s->map[i + 1][j - 1] == '1' && s->map[i - 1][j] == '1' &&
		s->map[i + 1][j] == '1' && s->map[i - 1][j + 1] == '1' &&
		s->map[i][j + 1] == '1' && s->map[i + 1][j + 1] == '1')
		return (MAP_ERR);
	return (0);
}

/*
** Check if the map only has certain characters, and the edges are " " or "1".
*/

static int	check_map_4(t_info *s, int i, int j, char c)
{
	if (c != ' ' && c != '0' && c != '1' && c != '2' &&
		c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (MAP_ERR);
	if (i == 0 || j == 0 || i == s->ms.y - 1 || j == s->ms.x - 1)
		if (c != '1' && c != ' ')
			return (MAP_ERR);
	if (c == ' ' && check_map_5(s, i, j) != 0)
		return (MAP_ERR);
	return (0);
}

/*
** Check if the map has and only has one direction(N/E/W/S) symbol in it.
*/

int			check_map_3(t_info *s)
{
	int		i;
	int		j;
	int		sig;
	char	c;

	i = -1;
	sig = 0;
	while (++i < s->ms.y)
	{
		j = -1;
		while (++j < s->ms.x)
		{
			if (s->map[i][j])
			{
				c = s->map[i][j];
				if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
					sig += store_start(s, i, j);
				if (check_map_4(s, i, j, c) != 0)
					return (MAP_ERR);
			}
		}
	}
	if (sig != 1)
		return (MAP_ERR);
	return (0);
}

/*
** Check if the map ends with an empty line, or inserted with an empty line.
*/

int			check_map_2(char *line)
{
	if (line == NULL)
		return (0);
	else
	{
		free(line);
		return (MAP_ERR);
	}
}

/*
** Check if the map begins with " " or "1", and store the length and
** width of it.
*/

int			check_map(char *line, t_info *s)
{
	int		err;
	int		temp;

	err = 0;
	if (ft_strchk(line, " ", 'B') == 1 || ft_strchk(line, "1", 'B') == 1)
	{
		s->sig_map = '1';
		temp = ft_strlen(line);
		temp > s->ms.x ? s->ms.x = temp : 0;
		s->ms.y++;
		free(line);
	}
	if (s->sig_map == '1' &&
		ft_strchk(line, " ", 'B') != 1 && ft_strchk(line, "1", 'B') != 1)
		err = MAP_ERR;
	if (s->sig_map == '1' && line == NULL)
		err = -1;
	return (err);
}
