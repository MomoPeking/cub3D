/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:04:16 by qdang             #+#    #+#             */
/*   Updated: 2020/07/19 17:31:34 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if str1 begin with or end up with str2. B for begin and E for end.
** If yes, return 1. If no, return 0.
*/

#include "libft.h"

int		ft_strchk(char *str1, char *str2, char c)
{
	int		len1;
	int		len2;
	int		i;

	if (str1 == NULL || str2 == NULL)
		return (0);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	i = 0;
	if (len2 <= len1)
	{
		if (c == 'E')
			while (++i <= len2)
				if (str1[len1 - i] != str2[len2 - i])
					return (0);
		if (c == 'B')
			while (++i <= len2)
				if (str1[i - 1] != str2[i - 1])
					return (0);
		return (1);
	}
	return (0);
}
