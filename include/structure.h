/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:51:15 by qdang             #+#    #+#             */
/*   Updated: 2020/09/17 17:45:21 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*
** wall_cf is a coefficient to make sure the wall is shown as a square.
** ms(x, y) in grids is the map size of the map in rectangular, start from 1.
** sp(x, y) in grids are the coordinates of startpoint N/E/W/S, start from 0.
** move(x, y) in grids are the coordinates the player moved from the sp.
** grid(x, y) in grids are the coordinates where they player at now(sp + move).
** stand(x, y) are the coordinates where the player stands on the screen.
** its(x, y) are the coordinates a sight intersect with a wall or an object.
** wall is the "N/E/S/W" face of the wall where the sight hits;
** sight is an angle where the casting start.
** length is the distance from stand(x, y) to its(x, y). Then we use length to
** calculate the height of the wall.
*/

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef	struct	s_info
{
	t_point	res;
	char	*no;
	int		*no_add;
	char	*so;
	int		*so_add;
	char	*we;
	int		*we_add;
	char	*ea;
	int		*ea_add;
	char	*s;
	int		*s_add;
	int		color_c;
	int		color_f;
	int		sig_info;
	char	sig_map;
	char	**map;
	char	start;
	int		wall_cf;
	t_point	ms;
	t_point	sp;
	t_point	move;
	t_point grid;
	t_point	stand;
	t_point its;
	char	wall;
	double	sight;
	double	length;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_add;
}				t_info;

#endif
