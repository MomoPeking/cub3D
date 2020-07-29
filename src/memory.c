/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:12:00 by qdang             #+#    #+#             */
/*   Updated: 2020/07/29 14:29:16 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_info(t_info *s)
{
	s->sig_info = 1;
	s->no = NULL;
	s->so = NULL;
	s->we = NULL;
	s->ea = NULL;
	s->s = NULL;
	s->map = NULL;
	s->mlx_ptr = NULL;
	s->win_ptr = NULL;
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
	if (s->map != NULL)
	{
		while (++i < s->map_y)
			free(s->map[i]);
		free(s->map);
	}
	free(s);
}
