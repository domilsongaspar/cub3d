/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_utils_for_directions_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:41:40 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/29 20:18:55 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	go_top(int x, int y, int height)
{
	t_mlx	*mlx;
	char	**map;

	if (y < 0 || y >= height)
		return ;
	mlx = get_mlx();
	map = mlx->scene->map->copy;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		put_error(ERR_NOT_SURROUNDED_BY_WALLS);
	if (map[y][x] == ' ')
		go_top(x, y - 1, height);
	if (map[y][x] == '1' || map[y][x] == DOOR_CHAR)
		return ;
}

void	go_down(int x, int y, int height)
{
	t_mlx	*mlx;
	char	**map;

	if (y < 0 || y >= height)
		return ;
	mlx = get_mlx();
	map = mlx->scene->map->copy;
	if (x >= mlx->scene->map->maxl_with_nl - 1)
		return ;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		put_error(ERR_NOT_SURROUNDED_BY_WALLS);
	if (map[y][x] == ' ')
		go_down(x, y + 1, height);
	if (map[y][x] == '1')
		return ;
}

void	go_left(int x, int y, int width, int height)
{
	t_mlx	*mlx;
	char	**map;

	if (x < 0 || x >= width)
		return ;
	mlx = get_mlx();
	map = mlx->scene->map->copy;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		put_error(ERR_NOT_SURROUNDED_BY_WALLS);
	go_top(x, y, height);
	go_down(x, y, height);
	if (map[y][x] == ' ')
		go_left(x - 1, y, width, height);
	if (map[y][x] == '1')
		return ;
}

void	go_right(int x, int y, int width, int height)
{
	t_mlx	*mlx;
	char	**map;

	if (x < 0 || x >= width)
		return ;
	mlx = get_mlx();
	map = mlx->scene->map->copy;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		put_error(ERR_NOT_SURROUNDED_BY_WALLS);
	go_top(x, y, height);
	go_down(x, y, height);
	if (map[y][x] == ' ')
		go_right(x + 1, y, width, height);
	if (map[y][x] == '1')
		return ;
}
