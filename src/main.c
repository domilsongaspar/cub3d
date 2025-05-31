/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:14:22 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/31 14:29:46 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_validations(char *map_src)
{
	if (!valid_file_existence(map_src))
		put_error(ERR_WITH_FILE);
	if (!valid_file_format(map_src))
		put_error(ERR_WITH_FILE_FORMAT);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
	{
		write(2, "Error\nShould pass one argument.\n", 33);
		return (EXIT_FAILURE);
	}
	mlx = get_mlx();
	initialize(mlx, av[1]);
	validate_scene(mlx->scene, av[1]);
	mlx->wnd = mlx_new_window(mlx->cnt, WIDTH, HEIGHT, "cub3D");
	paint_sky_and_floor(mlx->scene);
	ft_memset(mlx->keys, 0, sizeof(mlx->keys));
	mlx_hook(mlx->wnd, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->wnd, 3, 1L << 1, key_release, mlx);
	mlx_loop_hook(mlx->cnt, update, mlx);
	mlx_hook(mlx->wnd, DESTROY_NOTIFY, BUTTON_PRESS, close_game, NULL);
	mlx_loop(mlx->cnt);
	return (0);
}
