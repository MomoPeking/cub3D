# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 11:38:08 by qdang             #+#    #+#              #
#    Updated: 2020/09/30 14:08:27 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

SOURCE = main.c accessory.c check_info.c check_map.c \
			store_info.c store_texture.c store_other.c \
			draw.c draw_line.c press_key.c calculate.c \
			calc_quadrant_1.c calc_quadrant_2.c \
			calc_quadrant_3.c calc_quadrant_4.c \

LIB_PATH = ./libft
LIB_LINK = -I $(LIB_PATH) -L $(LIB_PATH) -lft

MLX_PATH = ./minilibx
MLX_LINK = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -lz

SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/,$(SOURCE))

OBJ = $(SOURCE:.c=.o)

HED = ./include/cub3d.h

$(NAME):
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	@gcc -c  $(SRC) -I $(HED)
	@gcc $(MLX_LINK) $(LIB_LINK) $(OBJ) -o $(NAME)
	@mv ./minilibx/libmlx.dylib ./

all: $(NAME)

clean:
	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME) libmlx.dylib

re: fclean all

.PHONY: all clean fclean re
