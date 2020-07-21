/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:04:06 by qdang             #+#    #+#             */
/*   Updated: 2020/07/20 18:27:42 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>

# include <stdio.h> // 記得刪除

# define OPEN_ERR	1
# define READ_ERR	2
# define END_ERR	3
# define R_ERR		4
# define TEX_ERR	5
# define COL_ERR	6
# define INFO_ERR	7

# define R_SIG		2
# define NO_SIG		3
# define SO_SIG		5
# define WE_SIG		7
# define EA_SIG		11
# define S_SIG		13
# define F_SIG		17
# define C_SIG		19
# define INFO_SIG	9699690

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
	int		signal;
}				t_info;

int		count_split(char **str);
int		check_unsigned_int(char *str);
int		check_color(char **color);

t_info	*init_info(t_info *s);
void	free_split(char **str);
void	free_info(t_info *s);

void	ft_error(int err);

int		store_resolution(t_info *s, char **split);
int		store_texture_no(t_info *s, char **split);
int		store_texture_so(t_info *s, char **split);
int		store_texture_we(t_info *s, char **split);
int		store_texture_ea(t_info *s, char **split);
int		store_texture_s(t_info *s, char **split);
int		store_color_floor(t_info *s, char **split);
int		store_color_ceiling(t_info *s, char **split);
int		store_info(t_info *s, int fd);

#endif
