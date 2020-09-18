/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:12:00 by qdang             #+#    #+#             */
/*   Updated: 2020/09/17 17:11:00 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(int err)
{
	if (err == OPEN_ERR)
		ft_putstr_fd("Error\nCannot open the map.\n", 2);
	else if (err == CLOSE_ERR)
		ft_putstr_fd("Error\nCannot close the map.\n", 2);
	else if (err == READ_ERR)
		ft_putstr_fd("Error\nCannot read the map.\n", 2);
	else if (err == END_ERR)
		ft_putstr_fd("Error\nA map must in *.cub format.\n", 2);
	else if (err == RES_ERR)
		ft_putstr_fd("Error\nThe resolution info is invalid.\n", 2);
	else if (err == TEX_ERR)
		ft_putstr_fd("Error\nThe texture info is invalid.\n", 2);
	else if (err == COL_ERR)
		ft_putstr_fd("Error\nThe color info is invalid.\n", 2);
	else if (err == INFO_ERR)
		ft_putstr_fd("Error\nThere are missing / extra information.\n", 2);
	else if (err == MAP_ERR)
		ft_putstr_fd("Error\nThe map is invalid.\n", 2);
	system("leaks cub3D");
	exit(EXIT_FAILURE);
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
		while (++i < s->ms.y)
			free(s->map[i]);
		free(s->map);
	}
	free(s);
}

int		close_scene(t_info *s)
{
	free_info(s);
	system("leaks cub3D");
	exit(0);
}
