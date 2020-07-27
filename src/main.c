/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:36:44 by qdang             #+#    #+#             */
/*   Updated: 2020/07/26 20:08:00 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_mapput(char **map, int width, int length)
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

static void	ft_show(t_info *s)
{
	printf("R: x: %d, y: %d\n", s->r_x, s->r_y);
	printf("NO: %s\n", s->no);
	printf("SO: %s\n", s->so);
	printf("WE: %s\n", s->we);
	printf("EA: %s\n", s->ea);
	printf("S: %s\n", s->s);
	printf("Floor Color: R: %d, G: %d, B: %d\n", s->f_r, s->f_g, s->f_b);
	printf("Ceiling Color: R: %d, G: %d, B: %d\n", s->c_r, s->c_g, s->c_b);
	printf("Map: x: %d, y: %d", s->map_x, s->map_y);
	printf("\n\n");
	ft_mapput(s->map, s->map_x, s->map_y);	
}

int			main(int ac, char **av)
{
	int		err;
	t_info	*s;
	int		fd;

	err = 0;
	s = (t_info	*)ft_memalloc(sizeof(t_info));
	init_info(s);
	if (ac == 2)
	{
		if (ft_strchk(av[1], ".cub", 'E') == 1)
		{
			if ((fd = open(av[1], O_RDONLY)) == -1)
				return (OPEN_ERR);
			else
			{
				err = store_info(s, fd);
				if (close(fd) == -1)
					return (CLOSE_ERR);
				if (err == 0)
				{
					fd = open(av[1], O_RDONLY);
					err = store_map(s, fd);
				}
			}
		}
		else
			err = END_ERR;
	}
	if (err != 0)
	{
		free_info(s);
		system("leaks cub3D");
		ft_error(err);		
	}
	ft_show(s);
	free_info(s);	
	system("leaks cub3D");
	return (0);
}
