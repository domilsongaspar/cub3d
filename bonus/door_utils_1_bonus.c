/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:33:12 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/29 15:37:56 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	count_doors(t_mlx *mlx)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (mlx->scene->map->matriz[y])
	{
		x = 0;
		while (mlx->scene->map->matriz[y][x])
		{
			if (mlx->scene->map->matriz[y][x] == DOOR_CHAR)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	fill_doors_data(t_mlx *mlx)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (mlx->scene->map->matriz[y])
	{
		x = 0;
		while (mlx->scene->map->matriz[y][x])
		{
			if (mlx->scene->map->matriz[y][x] == DOOR_CHAR)
			{
				mlx->scene->doors[count].x = x;
				mlx->scene->doors[count].y = y;
				mlx->scene->doors[count].state = DOOR_CLOSED;
				mlx->scene->doors[count].anim_time = 0.0;
				count++;
			}
			x++;
		}
		y++;
	}
}

void	init_doors(t_mlx *mlx)
{
	mlx->scene->door_count = count_doors(mlx);
	if (mlx->scene->door_count == 0)
	{
		mlx->scene->doors = NULL;
		return ;
	}
	mlx->scene->doors = malloc(sizeof(t_door) * (mlx->scene->door_count + 1));
	if (!mlx->scene->doors)
		put_error("Error\nMemory allocation failed for doors\n");
	fill_doors_data(mlx);
}

void	toggle_door(t_mlx *mlx, int x, int y)
{
	t_door	*door;

	door = find_door(mlx, x, y);
	if (!door)
		return ;
	if (door->state == DOOR_CLOSED)
		door->state = DOOR_OPENING;
	else if (door->state == DOOR_OPEN)
	{
		door->anim_time = 0.0;
		door->state = DOOR_CLOSING;
	}
}

void	check_door_interaction(t_mlx *mlx)
{
	int	check_x;
	int	check_y;

	check_x = (int)(mlx->ply->pos.x + mlx->ply->dir.x);
	check_y = (int)(mlx->ply->pos.y + mlx->ply->dir.y);
	if (mlx->keys[6] && (mlx->scene->map->matriz[check_y][check_x] == DOOR_CHAR
		|| mlx->scene->map->matriz[check_y][check_x] == DOOR_OPEN_CHAR))
	{
		toggle_door(mlx, check_x, check_y);
		mlx->keys[6] = false;
	}
}
