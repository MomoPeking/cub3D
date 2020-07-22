/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:12:00 by qdang             #+#    #+#             */
/*   Updated: 2020/07/22 11:27:17 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_info	*init_info(t_info *s)
{
	s->sig_info = 1;
	s->no = NULL;
	s->so = NULL;
	s->we = NULL;
	s->ea = NULL;
	s->s = NULL;
	s->map = NULL;
	return (s);
}

void	free_split(char **str)
{
	int		i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	free_info(t_info *s)
{
	int		i;

	i = -1;
	free(s->no);
	free(s->so);
	free(s->we);
	free(s->ea);
	free(s->s);
	while (++i < s->map_y)
		free(s->map[i]);
	free(s->map);
	free(s);
}
