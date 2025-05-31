/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spaces_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:48:18 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/31 13:48:27 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_top_lines(int x, int y)
{
	t_mlx	*mlx;
	char	**map;
	int		height;

	mlx = get_mlx();
	map = mlx->scene->map->cifred;
	height = mlx->scene->map->maxl_with_nl - 1;
	if ((x >= mlx->scene->map->maxc && y < height) || (!map[y]))
		return ;
	if (map[y][x] == ' ' || map[y][x] == '$')
	{
		fill_left(x, y, mlx->scene->map->maxc, height);
		fill_right(x, y, mlx->scene->map->maxc, height);
		map[y][x] = '$';
		fill_top_lines(x, y + 1);
	}
	if (map[y][x] == '1' || y + 1 > height)
		fill_top_lines(x + 1, 0);
}

void	fill_down_lines(int x, int y)
{
	t_mlx	*mlx;
	char	**map;
	int		height;

	mlx = get_mlx();
	map = mlx->scene->map->cifred;
	height = mlx->scene->map->maxl_with_nl - 1;
	if (x + 1 > mlx->scene->map->maxc || y < 0)
		return ;
	if (map[y][x] == ' '|| map[y][x] == '$')
	{
		fill_left(x, y, mlx->scene->map->maxc, height);
		fill_right(x, y, mlx->scene->map->maxc, height);
		map[y][x] = '$';
		fill_down_lines(x, y - 1);
	}
	if (map[y][x] == '1')
		fill_down_lines(x + 1, height);
}

void	fill_left_lines(int x, int y)
{
	t_mlx	*mlx;
	char	**map;
	int		height;

	mlx = get_mlx();
	map = mlx->scene->map->cifred;
	height = mlx->scene->map->maxl_with_nl - 1;
	if (y >= height || !map[y])
		return ;
	if (x >= mlx->scene->map->maxc)
	{
		x = 0;
		y++;
	}
	if (map[y][x] == ' ' || map[y][x] == '$' || map[y][x] == '\0')
	{
		fill_top(x, y, height);
		fill_down(x, y, height);
		map[y][x] = '$';
		fill_left_lines(x + 1, y);
	}
	if (map[y][x] == '1')
		fill_left_lines(0, y + 1);
}

void	fill_right_lines(int x, int y)
{
	t_mlx	*mlx;
	char	**map;
	int		height;

	mlx = get_mlx();
	map = mlx->scene->map->cifred;
	height = mlx->scene->map->maxl_with_nl - 1;
	if (y >= height)
		return ;
	if (x < 0)
	{
		x = mlx->scene->map->maxc - 1;
		y++;
	}
	if (map[y][x] == ' ' || map[y][x] == '$' || map[y][x] == '\0')
	{
		fill_top(x, y, height);
		fill_down(x, y, height);
		map[y][x] = '$';
		fill_right_lines(x - 1, y);
	}
	if (map[y][x] == '1')
		fill_right_lines(mlx->scene->map->maxc - 1, y + 1);
}
