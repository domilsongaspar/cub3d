# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 12:58:00 by dgaspar           #+#    #+#              #
#    Updated: 2025/05/31 13:49:35 by dgaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = cub3D
NAME_BONUS = cub3D_bonus

CC    = cc

INC_DIR = -I libft/ \
	      -I mlx/
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a \
		  $(MLX_DIR)/libmlx_Linux.a

FLAGS = -Wall -Wextra -Werror $(INC_DIR)
LIB_FLAGS = -L./libft -L./mlx -lft -lmlx -lXext -lX11 -lm

HEADER = src/cub3d.h
HEADER_BONUS = bonus/cub3d_bonus.h

SOURCES = src/draw.c \
		  src/debug.c \
		  src/free.c \
		  src/error.c \
		  src/get_map.c \
		  src/get_map_utils.c \
		  src/map_utils.c \
		  src/map_utils2.c \
		  src/map_wall_utils.c \
		  src/map_wall_utils_for_directions.c \
		  src/missing.c \
		  src/initialize.c \
		  src/movements.c \
		  src/movements_utils.c \
		  src/render.c \
		  src/utils.c \
		  src/utils2.c \
		  src/validate_colors.c \
		  src/validate_map.c \
		  src/validate_scene.c \
		  src/validate_textures.c \
		  src/main.c \
		  src/fill_spaces.c \
		  src/fill_spaces_utils.c \
		  src/handle_texture.c \
		  src/texture_utils.c 

SOURCES_BONUS = bonus/draw_bonus.c \
				bonus/debug_bonus.c \
				bonus/free_bonus.c \
				bonus/error_bonus.c \
				bonus/get_map_bonus.c \
				bonus/get_map_utils_bonus.c \
				bonus/map_utils_bonus.c \
				bonus/map_utils2_bonus.c \
				bonus/map_wall_utils_bonus.c \
				bonus/map_wall_utils_for_directions_bonus.c \
				bonus/missing_bonus.c \
				bonus/initialize_bonus.c \
				bonus/initialize_sprite_bonus.c \
				bonus/movements_bonus.c \
				bonus/movements_utils_bonus.c \
				bonus/render_bonus.c \
				bonus/render_sprite_bonus.c \
				bonus/utils_bonus.c \
				bonus/utils2_bonus.c \
				bonus/validate_colors_bonus.c \
				bonus/validate_map_bonus.c \
				bonus/validate_scene_bonus.c \
				bonus/validate_textures_bonus.c \
				bonus/main_bonus.c \
				bonus/handle_texture_bonus.c \
				bonus/texture_utils_bonus.c \
				bonus/minimap_bonus.c \
				bonus/mouse_handler_bonus.c \
				bonus/door_handler_bonus.c \
				bonus/door_utils_1_bonus.c \
				bonus/door_utils_2_bonus.c

OBJS    = $(SOURCES:.c=.o)
OBJS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(MLX_LIB) $(LIBFT_LIB) $(HEADER_BONUS) $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIB_FLAGS)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(HEADER) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB_FLAGS)

$(LIBFT_LIB):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
