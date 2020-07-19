/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:12:16 by qdang             #+#    #+#             */
/*   Updated: 2020/07/18 22:38:06 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE	100
# define FD_SIZE	256

/*
** Memory
*/

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

/*
** String
*/

char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** Output
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *c);

/*
** Other
*/

int		get_next_line(const int fd, char **line);

#endif