/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:36:44 by qdang             #+#    #+#             */
/*   Updated: 2020/07/21 18:25:09 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int ac, char **av)
{
	int		err;
	t_info	*s;
	int		fd;

	err = 0;
	s = (t_info	*)ft_memalloc(sizeof(t_info));
	s = init_info(s);
	if (ac == 2)
	{
		if (ft_strchk(av[1], ".cub", 'E') == 1)
		{
			if ((fd = open(av[1], O_RDONLY)) == -1)
				return (OPEN_ERR);
			else
				err = store_info(s, fd);
		}
		else
			err = END_ERR;
	}
	free_info(s);
	printf("x: %d, y: %d\n", s->map_x, s->map_y);
	printf("r: %d * %d\n", s->r_x, s->r_y);
	printf("r: %d, g: %d, b: %d\n", s->f_r, s->f_g, s->f_b);
	printf("r: %d, g: %d, b: %d\n", s->c_r, s->c_g, s->c_b);
//	system("leaks cub3D");
	err != 0 ? ft_error(err) : 0;
	return (0);
}
