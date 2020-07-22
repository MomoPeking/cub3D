/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:42:45 by qdang             #+#    #+#             */
/*   Updated: 2020/07/22 11:56:38 by qdang            ###   ########.fr       */
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

int		check_map_2(t_info *s)
{
	int		i;
	int		j;
	int		sig;
	char	c;
	
	i = -1;
	sig = 0;
	while (++i < s->map_y)
	{
		j = -1;
		while (++j < s->map_x)
		{
			c = s->map[i][j];
			if (c != ' ' && c != '0' && c != '1' && c != '2' &&
				c != 'N' && c != 'S' && c != 'E' && c != 'W')
				return (MAP_ERR);
		}
	}
	return (0);
}

int		check_map(char *line, t_info *s)
{
	int		err;
	int		temp;

	err = 0;
	if (ft_strchk(line, " ", 'B') == 1 || ft_strchk(line, "1", 'B') == 1)
	{
		s->sig_map = 1;
		temp = ft_strlen(line);
		temp > s->map_x ? s->map_x = temp : 0;
		s->map_y++;
		free(line);
	}
	if (s->sig_map == 1 && line == NULL)
		err = MAP_ERR;
	if (s->sig_map == 1 &&
		ft_strchk(line, " ", 'B') != 1 && ft_strchk(line, "1", 'B') != 1)
		err = MAP_ERR;
	return (err);
}
