# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 11:38:08 by qdang             #+#    #+#              #
#    Updated: 2020/07/28 21:59:13 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

SOURCE = main.c error.c memory.c interaction.c \
			draw.c draw_line.c \
			check_info.c check_map.c \
			store_info.c store_texture.c store_other.c \

LIB_PATH = ./libft
LIB_LINK = -I $(LIB_PATH) -L $(LIB_PATH) -lft

MLX_PATH = ./minilibx
MLX_LINK = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/,$(SOURCE))

OBJ = $(SOURCE:.c=.o)

HED = ./include/cub3d.h

$(NAME):
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	@gcc $(FLAGS) -c $(SRC) -I $(HED)
	@gcc $(MLX_LINK) $(LIB_LINK) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re