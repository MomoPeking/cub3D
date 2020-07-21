/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:42:45 by qdang             #+#    #+#             */
/*   Updated: 2020/07/20 15:18:40 by qdang            ###   ########.fr       */
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
