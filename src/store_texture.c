/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:11:17 by qdang             #+#    #+#             */
/*   Updated: 2020/08/18 22:49:33 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		store_texture_no(t_info *s, char **split)
{
	if (count_split(split) != 2)
		return (TEX_ERR);
	s->no = ft_strdup(split[1]);
	if (open(s->no, O_RDONLY) == -1)
		return (TEX_ERR);
	s->sig_info *= NO_SIG;
	return (0);
}

int		store_texture_so(t_info *s, char **split)
{
	if (count_split(split) != 2)
		return (TEX_ERR);
	s->so = ft_strdup(split[1]);
	if (open(s->so, O_RDONLY) == -1)
		return (TEX_ERR);
	s->sig_info *= SO_SIG;
	return (0);
}

int		store_texture_we(t_info *s, char **split)
{
	if (count_split(split) != 2)
		return (TEX_ERR);
	s->we = ft_strdup(split[1]);
	if (open(s->we, O_RDONLY) == -1)
		return (TEX_ERR);
	s->sig_info *= WE_SIG;
	return (0);
}

int		store_texture_ea(t_info *s, char **split)
{
	if (count_split(split) != 2)
		return (TEX_ERR);
	s->ea = ft_strdup(split[1]);
	if (open(s->ea, O_RDONLY) == -1)
		return (TEX_ERR);
	s->sig_info *= EA_SIG;
	return (0);
}

int		store_texture_s(t_info *s, char **split)
{
	if (count_split(split) != 2)
		return (TEX_ERR);
	s->s = ft_strdup(split[1]);
	if (open(s->s, O_RDONLY) == -1)
		return (TEX_ERR);
	s->sig_info *= S_SIG;
	return (0);
}
