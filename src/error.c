/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:50:59 by qdang             #+#    #+#             */
/*   Updated: 2020/07/17 16:40:19 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(int err)
{
	(err == OPEN_ERR) ? ft_putstr_fd("Cannot open the map.\n", 2) : 0;
	(err == READ_ERR) ? ft_putstr_fd("Cannot read the map.\n", 2) : 0;
	exit(-1);
}