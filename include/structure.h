/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:51:15 by qdang             #+#    #+#             */
/*   Updated: 2020/08/18 23:07:32 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*
** ms(x, y) in grids is the map size of the map in rectangular, start from 1.
** sp(x, y) in grids are the coordinates of startpoint N/E/W/S, start from 0.
** move(x, y) in grids are the coordinates the player moved from the sp.
** grid(x, y) in grids are the coordinates where they player at now(sp + move).
** stand(x, y) are the coordinates where the player stands on the screen.
** its(x, y) are the coordinates a sight intersect with a wall or an object.
** sight_m is an angle in the middle of the FOV.
*/

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef	struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef	struct	s_info
{
	t_point	res;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	t_color	floor;
	t_color	ceiling;
	int		sig_info;
	char	sig_map;
	char	**map;
	t_point	ms;
	char	start;
	t_point	sp;
	t_point	move;
	t_point grid;
	t_point	stand;
	t_point its;
	double	sight_m;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_info;

#endif
