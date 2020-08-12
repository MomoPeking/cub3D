/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:51:15 by qdang             #+#    #+#             */
/*   Updated: 2020/08/04 16:36:56 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCUTURE_H
# define STRCUTURE_H

/* 
** map_x/y in grids are the width and length of the map in rectangular, start from 1.
** start_x/y in grids are the coordinates of startpoint N/E/W/S, start from 0.
** move_x/y in grids are the coordinates how the player moved from the startpoint.
** grid_x/y in grids are the coordinates where they player at now.
** stand_x/y are the coordinates where the player stands.
** its_x/y are the coordinates where a sight intersect with a wall or an object.
*/

typedef	struct	s_info
{
	int		r_x;
	int		r_y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	int		sig_info;
	char	sig_map;
	char	**map;
	int		map_x;
	int		map_y;
	int		start_x;
	int		start_y;
	char	start;
	double	start_sight;	
	int		move_x;
	int		move_y;
	int		grid_x;
	int		grid_y;	
	int		stand_x;
	int		stand_y;
	int		its_x;
	int		its_y;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_info;

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;	

#endif