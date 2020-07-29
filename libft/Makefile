# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 17:38:51 by qdang             #+#    #+#              #
#    Updated: 2020/07/28 21:41:44 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HED = libft.h

SRC = ft_memset.c ft_bzero.c ft_memalloc.c \
		ft_abs.c ft_atoi.c ft_min.c\
		ft_strnew.c ft_strlen.c ft_strjoin.c ft_strdup.c ft_strchr.c \
		ft_strsub.c ft_strsplit.c ft_strchk.c ft_strcmp.c \
		ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c ft_putstr.c \
		get_next_line.c ft_mapnew.c

OBJ = $(SRC:.c=.o)

GCH = $(HED:.h=.h.gch)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(HED)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(GCH)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re