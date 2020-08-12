/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:20:47 by qdang             #+#    #+#             */
/*   Updated: 2020/08/04 16:23:54 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new 2D map with certain width and length, then fill it with c.
*/

#include "libft.h"

char	**ft_mapnew(int width, int length, char c)
{
	char	**map;
	int		i;
	int		j;

	if (width < 1 || length < 1)
		return (NULL);
	i = 0;
	map = (char **)ft_memalloc(sizeof(char *) * length);
	while (i < length)
	{
		j = 0;
		map[i] = (char *)ft_memalloc(sizeof(char) * width);
		while (j < width)
		{
			map[i][j] = c;
			j++;
		}
		i++;
	}
	return (map);
}
