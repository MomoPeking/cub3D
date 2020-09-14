/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:36:44 by qdang             #+#    #+#             */
/*   Updated: 2020/09/13 19:02:23 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	create_scene(t_info *s)
{
	int		bpp;
	int		sl;
	int		endian;

	s->mlx_ptr = mlx_init();
	s->win_ptr = mlx_new_window(s->mlx_ptr, s->res.x, s->res.y, "cub3D");
	s->img_ptr = mlx_new_image(s->mlx_ptr, s->res.x, s->res.y);
	s->img_add = (int *)mlx_get_data_addr(s->img_ptr, &bpp, &sl, &endian);
	draw(s);
	mlx_hook(s->win_ptr, 2, 0, press_key, s);
	mlx_hook(s->win_ptr, 17, 0, close_scene, s);
	mlx_loop(s->mlx_ptr);
}

int			main(int ac, char **av)
{
	int		err;
	t_info	*s;

	err = 0;
	s = (t_info	*)ft_memalloc(sizeof(t_info));
	init_info(s);
	if (ac == 2)
		err = read_and_store(av[1], s);
	if (err != 0)
	{
		free_info(s);
		ft_error(err);
	}
	create_scene(s);
//	system("leaks cub3D");	
	return (0);
}
