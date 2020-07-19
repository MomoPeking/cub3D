/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:36:44 by qdang             #+#    #+#             */
/*   Updated: 2020/07/18 23:21:48 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL; 
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		(fd == -1) ? ft_error(OPEN_ERR) : 0;
		while ((i = get_next_line(fd, &line)) > 0)
		{
			ft_putstr(line);
			ft_putchar('\n');
			free(line);
		}
		if (line != NULL)
			free(line);
		(i < 0) ? ft_error(READ_ERR) : 0;
	}
	system("leaks cub3D");
	return (0);
}
