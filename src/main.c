/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:36:44 by qdang             #+#    #+#             */
/*   Updated: 2020/07/27 09:48:05 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
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
*/

static void	create_scene(t_info *s)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, s->r_x, s->r_y, "cub3D");
	mlx_hook(win_ptr, 2, 0, press_key, s);	
	mlx_hook(win_ptr, 17, 0, close_scene, s);
	mlx_loop(mlx_ptr);
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
//		system("leaks cub3D");
		ft_error(err);		
	}
	create_scene(s);	
//	ft_show(s);
	return (0);
}
