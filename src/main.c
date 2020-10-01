/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:36:44 by qdang             #+#    #+#             */
/*   Updated: 2020/09/30 17:57:32 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	create_scene(t_info *s)
{
	int		tmp[4];

	s->mlx_ptr = mlx_init();
	mlx_get_screen_size(s->mlx_ptr, &tmp[0], &tmp[1]);
	s->res.x > tmp[0] ? s->res.x = tmp[0] : 0;
	s->res.y > tmp[1] ? s->res.y = tmp[1] : 0;
	s->win_ptr = mlx_new_window(s->mlx_ptr, s->res.x, s->res.y, "cub3D");
	s->img_ptr = mlx_new_image(s->mlx_ptr, s->res.x, s->res.y);
	s->img_add =
		(int *)mlx_get_data_addr(s->img_ptr, &tmp[0], &tmp[1], &tmp[2]);
	s->sl = tmp[1] / 4;
	(tmp[3] = store_tex_add(s)) != 0 ? ft_error(s, tmp[3]) : 0;
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
	s->sig_info = 1;
	if (ac == 2)
		err = read_and_store(av[1], s);
	if (err != 0)
		ft_error(s, err);
	create_scene(s);
	return (0);
}

//	main中的邏輯問題(存bmp)？
//	小精靈
//	png作為texture？兩個識別系統？
