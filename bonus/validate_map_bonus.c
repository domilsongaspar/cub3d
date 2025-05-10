/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:11:10 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 07:05:56 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	valid_symbols(t_scene *scene)
{
	int		x;
	int		y;
	char	**mtx;

	y = 0;
	mtx = scene->map->matriz;
	while (mtx[y])
	{
		x = 0;
		while (mtx[y][x])
		{
			if (mtx[y][x] != '0' && mtx[y][x] != '1' && mtx[y][x] != 'N'
				&& mtx[y][x] != 'E' && mtx[y][x] != 'S' && mtx[y][x] != 'W'
				&& mtx[y][x] != ' ' && mtx[y][x] != '\n')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

int	count_ply_symbol(t_scene *scene)
{
	int		x;
	int		y;
	int		counter;
	char	**mtx;

	y = 0;
	counter = 0;
	mtx = scene->map->matriz;
	while (mtx[y])
	{
		x = 0;
		while (mtx[y][x])
		{
			if (mtx[y][x] == 'N' || mtx[y][x] == 'E' || mtx[y][x] == 'S'
				|| mtx[y][x] == 'W')
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

bool	has_blank_line(t_scene *scene)
{
	int		y;
	char	**mtx;
	bool	newline;

	y = 0;
	mtx = scene->map->matriz;
	newline = false;
	while (mtx[y])
	{
		if (ft_strcmp(mtx[y], "\n") == 0)
			newline = true;
		if (!is_invisible_line(mtx[y]) != 0 && newline)
			return (true);
		y++;
	}
	return (false);
}

void	is_surrounded_by_walls(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	vertical_top_lines(0, 0);
	vertical_down_lines(0, mlx->scene->map->maxl_with_nl - 1);
	horizontal_left_lines(0, 0);
	horizontal_right_lines(mlx->scene->map->maxc - 1, 0);
}

void	validate_map(t_scene *scene)
{
	if (!valid_symbols(scene))
		put_error(ERR_MAP_SYMBOL);
	if (count_ply_symbol(scene) == 0)
		put_error(ERR_FEW_PLAYERS);
	if (count_ply_symbol(scene) > 1)
		put_error(ERR_MANY_PLAYERS);
	if (has_blank_line(scene))
		put_error(ERR_MAP_WITH_BLANK_LINE);
	is_surrounded_by_walls();
}
