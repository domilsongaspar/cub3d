/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:03:20 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/31 13:48:02 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_top(int x, int y, int height)
{
	t_mlx	*mlx;
	char	**map;

	if (y < 0 || y >= height)
		return ;
	mlx = get_mlx();
	map = mlx->scene->map->cifred;
	if (map[y][x] == ' ' || map[y][x] == '$')
	{
		map[y][x] = '$';
		fill_top(x, y - 1, height);
	}
	if (map[y][x] == '1')
		return ;
}

void	fill_down(int x, int y, int height)
{
	t_mlx	*mlx;
	char	**map;

	if (y < 0 || y >= height)
		return ;
	mlx = get_mlx();
	map = mlx->scene->map->cifred;
	if (x >= mlx->scene->map->maxl_with_nl - 1)
		return ;
	if (map[y][x] == ' ' || map[y][x] == '$')
	{
		map[y][x] = '$';
		fill_down(x, y + 1, height);
	}
	if (map[y][x] == '1')
		return ;
}

void	fill_left(int x, int y, int width, int height)
{
	t_mlx	*mlx;
	char	**map;

	if (x < 0 || x >= width)
		return ;
	mlx = get_mlx();
	map = mlx->scene->map->cifred;
	fill_top(x, y, height);
	fill_down(x, y, height);
	if (map[y][x] == ' ' || map[y][x] == '$')
	{
		map[y][x] = '$';
		fill_left(x - 1, y, width, height);
	}
	if (map[y][x] == '1')
		return ;
}

void	fill_right(int x, int y, int width, int height)
{
	t_mlx	*mlx;
	char	**map;

	if (x < 0 || x >= width)
		return ;
	mlx = get_mlx();
	map = mlx->scene->map->cifred;
	fill_top(x, y, height);
	fill_down(x, y, height);
	if (map[y][x] == ' ' || map[y][x] == '$')
	{
		map[y][x] = '$';
		fill_right(x + 1, y, width, height);
	}
	if (map[y][x] == '1')
		return ;
}
