/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:38:41 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/29 15:41:19 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_door_status(t_door *door, double time, int state, char symbol)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	door->anim_time = time;
	door->state = state;
	mlx->scene->map->matriz[door->y][door->x] = symbol;
}

void	update_door_status(t_mlx *mlx, t_door *door)
{
	if (door->state == DOOR_OPENING)
	{
		door->anim_time += 0.05;
		if (door->anim_time >= 1.0)
			set_door_status(door, 0.0, DOOR_OPEN, DOOR_OPEN_CHAR);
	}
	else if (door->state == DOOR_OPEN)
	{
		door->anim_time += 0.05;
		if (door->anim_time >= 1)
		{
			door->anim_time = 0.0;
			door->state = DOOR_CLOSING;
		}
	}
	else if (door->state == DOOR_CLOSING)
	{
		door->anim_time += 0.05;
		if (door->anim_time >= 1.0 && (door->x != (int)mlx->ply->pos.x
				&& door->y != (int)mlx->ply->pos.y))
			set_door_status(door, 0.0, DOOR_CLOSED, DOOR_CHAR);
	}
}

void	update_doors(t_mlx *mlx)
{
	int		i;
	t_door	*door;

	i = 0;
	while (i < mlx->scene->door_count)
	{
		door = &mlx->scene->doors[i];
		update_door_status(mlx, door);
		i++;
	}
}
