/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:20:47 by qdang             #+#    #+#             */
/*   Updated: 2020/07/21 22:23:55 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new 2D map with certain width and length.
*/

#include "libft.h"

char	**ft_mapnew(int width, int length)
{
	char	**map;
	int		i;

	if (width < 1 || length < 1)
		return (NULL);
	i = 0;
	map = (char **)ft_memalloc(sizeof(char *) * length);
	while (i < length)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * width);
		i++;
	}
	return (map);
}