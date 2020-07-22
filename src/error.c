/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:50:59 by qdang             #+#    #+#             */
/*   Updated: 2020/07/21 18:20:29 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(int err)
{
	if (err == OPEN_ERR)
		ft_putstr_fd("Error\nCannot open the map.\n", 2);
	else if (err == READ_ERR)
		ft_putstr_fd("Error\nCannot read the map.\n", 2);
	else if (err == END_ERR)
		ft_putstr_fd("Error\nA map must in *.cub format.\n", 2);
	else if (err == R_ERR)
		ft_putstr_fd("Error\nThe resolution info is invalid.\n", 2);
	else if (err == TEX_ERR)
		ft_putstr_fd("Error\nThe texture info is invalid.\n", 2);
	else if (err == COL_ERR)
		ft_putstr_fd("Error\nThe color info is invalid.\n", 2);
	else if (err == INFO_ERR)
		ft_putstr_fd("Error\nThere are missing / extra information.\n", 2);
	else if (err == MAP_ERR)
		ft_putstr_fd("Error\nThe map is invalid.\n", 2);
	exit(EXIT_FAILURE);
}
