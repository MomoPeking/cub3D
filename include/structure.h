/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:51:15 by qdang             #+#    #+#             */
/*   Updated: 2020/07/27 15:17:17 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCUTURE_H
# define STRCUTURE_H

/*
** Start x/y are the coordinates of startpoint N/E/W/S, start from 0.
** Map x/y are the width and length of the map in rectangular, start from 1.
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
	int		ul;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_info;

#endif