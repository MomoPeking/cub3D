/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:38:23 by qdang             #+#    #+#             */
/*   Updated: 2020/09/14 14:40:34 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			store_resolution(t_info *s, char **split)
{
	if (count_split(split) != 3)
		return (RES_ERR);
	if (check_unsigned_int(split[1]) == 0 || check_unsigned_int(split[2]) == 0)
		return (RES_ERR);
	s->res.x = ft_atoi(split[1]);
	s->res.y = ft_atoi(split[2]);
	if (s->res.x == 0 || s->res.y == 0)
		return (RES_ERR);
	s->sig_info *= R_SIG;
	return (0);
}

static void	store_color_2(t_info *s, char c, int mix)
{
	if (c == 'C')
	{
		s->color_c = mix;
		s->sig_info *= C_SIG;
	}
	if (c == 'F')
	{
		s->color_f = mix;
		s->sig_info *= F_SIG;
	}
}

int			store_color(t_info *s, char **split, char c)
{
	char	**color;
	int		r;
	int		g;
	int		b;
	int		mix;

	if (count_split(split) != 2 || (ft_strchk(split[1], ",", 'E') == 1))
		return (COL_ERR);
	color = ft_strsplit(split[1], ',');
	if (check_color(color) == COL_ERR || (c != 'F' && c != 'C'))
		return (COL_ERR);
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		free_split(color);
		return (COL_ERR);
	}
	mix = r * 65536 + g * 256 + b;
	store_color_2(s, c, mix);
	free_split(color);
	return (0);
}

int			store_start(t_info *s, int i, int j)
{
	double	angle;

	angle = M_PI / 180 * FOV / 2;
	s->sp.x = j;
	s->sp.y = i;
	s->start = s->map[i][j];
	s->start == 'N' ? s->sight = 0 - angle : 0;
	s->start == 'E' ? s->sight = M_PI_2 - angle : 0;
	s->start == 'S' ? s->sight = M_PI - angle : 0;
	s->start == 'W' ? s->sight = M_PI_2 * 3 - angle : 0;
	return (1);
}
