# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 12:58:00 by dgaspar           #+#    #+#              #
#    Updated: 2025/05/10 08:25:33 by dgaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = cub3D
CC    = cc

INC_DIR = -I libft/ \
	      -I mlx/
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a \
		  $(MLX_DIR)/libmlx_Linux.a

FLAGS = -Wall -Wextra -Werror $(INC_DIR) -L./libft -lft

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
		  src/handle_texture.c \
		  src/texture_utils.c

BONUS_SOURCES = bonus/draw_bonus.c \
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
				bonus/movements_bonus.c \
				bonus/movements_utils_bonus.c \
				bonus/render_bonus.c \
				bonus/utils_bonus.c \
				bonus/utils2_bonus.c \
				bonus/validate_colors_bonus.c \
				bonus/validate_map_bonus.c \
				bonus/validate_scene_bonus.c \
				bonus/validate_textures_bonus.c \
				bonus/main_bonus.c \
				bonus/handle_texture_bonus.c \
				bonus/texture_utils_bonus.c \
				bonus/minimap_bonus.c

OBJS    = $(SOURCES:.c=.o)
BONUS_OBJS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

bonus: $(LIBFT_LIB) $(MLX_LIB) $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(FLAGS) -o $(NAME) -L./mlx -lmlx -lXext -lX11 -lm

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(FLAGS) -o $@ -L./mlx -lmlx -lXext -lX11 -lm

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
	rm -rf $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
