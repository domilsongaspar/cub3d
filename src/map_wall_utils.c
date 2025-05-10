/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:22:27 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/09 21:43:25 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_longest_line(char **matriz)
{
	int	y;
	int	len;
	int	longest;

	y = 0;
	longest = 0;
	while (matriz[y])
	{
		len = ft_strlen(matriz[y]);
		if (len > longest)
			longest = len;
		y++;
	}
	return (longest);
}

void	vertical_top_lines(int x, int y)
{
	t_mlx	*mlx;
	char	**map;
	int		height;

	mlx = get_mlx();
	map = mlx->scene->map->copy;
	height = mlx->scene->map->maxl_with_nl - 1;
	if ((x >= mlx->scene->map->maxc && y < height) || (!map[y]))
		return ;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		put_error(ERR_NOT_SURROUNDED_BY_WALLS);
	if (map[y][x] == ' ')
	{
		go_left(x, y, mlx->scene->map->maxc);
		go_right(x, y, mlx->scene->map->maxc);
		vertical_top_lines(x, y + 1);
	}
	if (map[y][x] == '1' || y + 1 > height)
		vertical_top_lines(x + 1, 0);
}

void	vertical_down_lines(int x, int y)
{
	t_mlx	*mlx;
	char	**map;
	int		height;

	mlx = get_mlx();
	map = mlx->scene->map->copy;
	height = mlx->scene->map->maxl_with_nl - 1;
	if (x + 1 > mlx->scene->map->maxc || y < 0)
		return ;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		put_error(ERR_NOT_SURROUNDED_BY_WALLS);
	if (map[y][x] == ' ')
	{
		go_left(x, y, mlx->scene->map->maxc);
		go_right(x, y, mlx->scene->map->maxc);
		vertical_down_lines(x, y - 1);
	}
	if (map[y][x] == '1')
		vertical_down_lines(x + 1, height);
}

void	horizontal_left_lines(int x, int y)
{
	t_mlx	*mlx;
	char	**map;
	int		height;

	mlx = get_mlx();
	map = mlx->scene->map->copy;
	height = mlx->scene->map->maxl_with_nl - 1;
	if (x >= mlx->scene->map->maxc || y >= height || !map[y])
		return ;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		put_error(ERR_NOT_SURROUNDED_BY_WALLS);
	if (map[y][x] == ' ' || map[y][x] == '\0')
	{
		go_top(x, y, height);
		go_down(x, y, height);
		horizontal_left_lines(x + 1, y);
	}
	if (map[y][x] == '1')
		horizontal_left_lines(0, y + 1);
}

void	horizontal_right_lines(int x, int y)
{
	t_mlx	*mlx;
	char	**map;
	int		height;

	mlx = get_mlx();
	map = mlx->scene->map->copy;
	height = mlx->scene->map->maxl_with_nl - 1;
	if (x < 0 || y >= height)
		return ;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		put_error(ERR_NOT_SURROUNDED_BY_WALLS);
	if (map[y][x] == ' ' || map[y][x] == '\0')
	{
		go_top(x, y, height);
		go_down(x, y, height);
		horizontal_right_lines(x - 1, y);
	}
	if (map[y][x] == '1')
		horizontal_right_lines(mlx->scene->map->maxc - 1, y + 1);
}
