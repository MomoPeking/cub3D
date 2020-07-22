/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:38:23 by qdang             #+#    #+#             */
/*   Updated: 2020/07/22 11:54:46 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
void	ft_mapput(char **map, int width, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < width)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
*/
int		store_map(t_info *s, int fd)
{
	char	*line;
	int		i;
	int		j;
	
	s->map = ft_mapnew(s->map_x, s->map_y);
	i = 0;
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
	return (check_map_2(s));
//	ft_mapput(s->map, s->map_x, s->map_y);
}