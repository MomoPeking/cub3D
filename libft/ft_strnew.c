/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:25:13 by qdang             #+#    #+#             */
/*   Updated: 2020/07/17 15:06:13 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creat a new string with (size + 1) and initialized to 0.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * size + 1);
	ft_bzero(new, sizeof(char) * size + 1);
	return (new);
}
