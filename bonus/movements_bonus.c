/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:44:08 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/29 14:52:13 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	perfom_rotate(t_mlx *mlx)
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;

	if (mlx->keys[4] || mlx->keys[5])
	{
		angle = ROT_SPEED;
		if (mlx->keys[4])
			angle = -ROT_SPEED;
		old_dir_x = mlx->ply->dir.x;
		mlx->ply->dir.x = mlx->ply->dir.x * cos(angle) - mlx->ply->dir.y \
		* sin(angle);
		mlx->ply->dir.y = old_dir_x * sin(angle) + mlx->ply->dir.y \
		* cos(angle);
		old_plane_x = mlx->ply->plane.x;
		mlx->ply->plane.x = mlx->ply->plane.x \
		* cos(angle) - mlx->ply->plane.y * sin(angle);
		mlx->ply->plane.y = old_plane_x * sin(angle) + mlx->ply->plane.y \
		* cos(angle);
	}
}

void	move_up(t_ply *ply, t_map *map, bool key)
{
	double	new_x;
	double	new_y;

	if (key)
	{
		new_x = ply->pos.x + ply->dir.x * MOV_SPEED;
		new_y = ply->pos.y + ply->dir.y * MOV_SPEED;
		if (move_on(new_x, ply->pos.y) != '1'
			&& move_on(new_x, ply->pos.y) != DOOR_CHAR)
		{
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = '0';
			ply->pos.x = new_x;
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = map->ply_sybl;
		}
		if (move_on(ply->pos.x, new_y) != '1'
			&& move_on(ply->pos.x, new_y) != DOOR_CHAR)
		{
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = '0';
			ply->pos.y = new_y;
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = map->ply_sybl;
		}
	}
}

void	move_down(t_ply *ply, t_map *map, bool key)
{
	double	new_x;
	double	new_y;

	if (key)
	{
		new_x = ply->pos.x - ply->dir.x * MOV_SPEED;
		new_y = ply->pos.y - ply->dir.y * MOV_SPEED;
		if (move_on(new_x, ply->pos.y) != '1'
			&& move_on(new_x, ply->pos.y) != DOOR_CHAR)
		{
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = '0';
			ply->pos.x = new_x;
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = map->ply_sybl;
		}
		if (move_on(ply->pos.x, new_y) != '1'
			&& move_on(ply->pos.x, new_y) != DOOR_CHAR)
		{
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = '0';
			ply->pos.y = new_y;
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = map->ply_sybl;
		}
	}
}

void	move_left(t_ply *ply, t_map *map, t_vec perp, bool key)
{
	double	new_x;
	double	new_y;

	if (key)
	{
		new_x = ply->pos.x + perp.x * MOV_SPEED;
		new_y = ply->pos.y + perp.y * MOV_SPEED;
		if (move_on(new_x, ply->pos.y) != '1'
			&& move_on(new_x, ply->pos.y) != DOOR_CHAR)
		{
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = '0';
			ply->pos.x = new_x;
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = map->ply_sybl;
		}
		if (move_on(ply->pos.x, new_y) != '1'
			&& move_on(ply->pos.x, new_y) != DOOR_CHAR)
		{
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = '0';
			ply->pos.y = new_y;
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = map->ply_sybl;
		}
	}
}

void	move_right(t_ply *ply, t_map *map, t_vec perp, bool key)
{
	double	new_x;
	double	new_y;

	if (key)
	{
		new_x = ply->pos.x - perp.x * MOV_SPEED;
		new_y = ply->pos.y - perp.y * MOV_SPEED;
		if (move_on(new_x, ply->pos.y) != '1'
			&& move_on(new_x, ply->pos.y) != DOOR_CHAR)
		{
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = '0';
			ply->pos.x = new_x;
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = map->ply_sybl;
		}
		if (move_on(ply->pos.x, new_y) != '1'
			&& move_on(ply->pos.x, new_y) != DOOR_CHAR)
		{
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = '0';
			ply->pos.y = new_y;
			map->matriz[(int)ply->pos.y][(int)ply->pos.x] = map->ply_sybl;
		}
	}
}
