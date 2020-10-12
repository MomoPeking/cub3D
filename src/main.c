/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:36:44 by qdang             #+#    #+#             */
/*   Updated: 2020/10/12 11:12:29 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	create_scene(t_info *s, int sig)
{
	int		tmp[4];

	s->mlx_ptr = mlx_init();
	mlx_get_screen_size(s->mlx_ptr, &tmp[0], &tmp[1]);
	s->res.x > tmp[0] ? s->res.x = tmp[0] : 0;
	s->res.y > tmp[1] ? s->res.y = tmp[1] : 0;
	s->wall_cf = s->res.x * SL / 2 / tan(FOV / 2 * M_PI / 180);
	s->win_ptr = mlx_new_window(s->mlx_ptr, s->res.x, s->res.y, "cub3D");
	s->img_ptr = mlx_new_image(s->mlx_ptr, s->res.x, s->res.y);
	s->img_add =
		(int *)mlx_get_data_addr(s->img_ptr, &tmp[0], &tmp[1], &tmp[2]);
	s->sl = tmp[1] / 4;
	(tmp[3] = store_tex_add(s)) != 0 ? ft_error(s, tmp[3]) : 0;
	draw(s);
	sig == 2 ? save_scene(s) : 0;
	mlx_hook(s->win_ptr, 2, 0, press_key, s);
	mlx_hook(s->win_ptr, 17, 0, close_scene, s);
	mlx_loop(s->mlx_ptr);
}

int			main(int ac, char **av)
{
	int		err;
	int		sig;
	t_info	*s;

	err = 0;
	sig = 0;
	s = (t_info	*)ft_memalloc(sizeof(t_info));
	s->sig_info = 1;
	if (ac == 2)
	{
		err = read_and_store(av[1], s);
		sig = 1;
	}
	else if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
	{
		err = read_and_store(av[1], s);
		sig = 2;
	}
	else
		err = AUG_ERR;
	err != 0 ? ft_error(s, err) : 0;
	sig != 0 ? create_scene(s, sig) : 0;
	return (0);
}

//	斜線的問題！
