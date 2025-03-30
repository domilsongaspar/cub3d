
EXECUTABLE = cc -Wall -Wextra -Werror -g -I ./libft -I ./mlx -o cub3D main.c libft/libft.a -L ./libft -lft -L ./mlx -lmlx -lX11 -lXext -lXrandr -lXrender -lm -lXfixes -lbsd

all:
	make -C libft bonus
	make -C mlx
	$(EXECUTABLE)

clean:
	make -C libft fclean
	rm -f *.o
fclean: clean
	rm -f cub3D
re: fclean all