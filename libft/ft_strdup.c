/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:22:15 by qdang             #+#    #+#             */
/*   Updated: 2020/07/17 15:06:04 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	str = ft_strnew(ft_strlen(s1));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
