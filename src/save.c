/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:22:47 by qdang             #+#    #+#             */
/*   Updated: 2020/10/12 11:07:34 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	save_data(t_info *s, int fd)
{
	int				i;
	int				j;
	int				k;
	unsigned char	buffer[4];

	i = s->sl * (s->res.y - 1);
	while (i >= 0)
	{
		j = -1;
		while (++j < s->res.x)
		{
			k = i + j;
			buffer[0] = s->img_add[k] % 256;
			buffer[1] = s->img_add[k] / 256 % 256;
			buffer[2] = s->img_add[k] / 256 / 256 % 256;
			buffer[3] = 0;
			write(fd, buffer, 4);
		}
		i -= s->sl;
	}
}

static void	save_info(t_info *s, int fd)
{
	int				i;
	unsigned char	header[40];

	i = -1;
	while (++i < 40)
		header[i] = 0;
	header[0] = 40;
	header[4] = s->res.x % 256;
	header[5] = s->res.x / 256 % 256;
	header[6] = s->res.x / 256 / 256 % 256;
	header[7] = s->res.x / 256 / 256 / 256;
	header[8] = s->res.y % 256;
	header[9] = s->res.y / 256 % 256;
	header[10] = s->res.y / 256 / 256 % 256;
	header[11] = s->res.y / 256 / 256 / 256;
	header[12] = 1;
	header[14] = 32;
	write(fd, header, 40);
}

static void	save_file(t_info *s, int fd)
{
	int				i;
	int				size;
	unsigned char	header[14];

	i = -1;
	while (++i < 14)
		header[i] = 0;
	header[0] = 'B';
	header[1] = 'M';
	size = s->res.x * s->res.y * 4 + 54;
	header[2] = size % 256;
	header[3] = size / 256 % 256;
	header[4] = size / 256 / 256 % 256;
	header[5] = size / 256 / 256 / 256;
	header[10] = 54;
	write(fd, header, 14);
}

void		save_scene(t_info *s)
{
	int		fd;

	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	save_file(s, fd);
	save_info(s, fd);
	save_data(s, fd);
	close(fd);
}
