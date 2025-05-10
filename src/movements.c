/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:44:08 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 06:40:06 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	move_up_down(t_mlx *mlx)
{
	double	new_x;
	double	new_y;

	if (mlx->keys[0])
	{
		new_x = mlx->ply->pos.x + mlx->ply->dir.x * MOV_SPEED;
		new_y = mlx->ply->pos.y + mlx->ply->dir.y * MOV_SPEED;
		if (move_on(new_x + COLLISION_MARGIN, mlx->ply->pos.y) != '1'
			&& move_on(new_x - COLLISION_MARGIN, mlx->ply->pos.y) != '1')
			mlx->ply->pos.x = new_x;
		if (move_on(mlx->ply->pos.x, new_y + COLLISION_MARGIN) != '1'
			&& move_on(mlx->ply->pos.x, new_y - COLLISION_MARGIN) != '1')
			mlx->ply->pos.y = new_y;
	}
	if (mlx->keys[1])
	{
		new_x = mlx->ply->pos.x - mlx->ply->dir.x * MOV_SPEED;
		new_y = mlx->ply->pos.y - mlx->ply->dir.y * MOV_SPEED;
		if (move_on(new_x + COLLISION_MARGIN, mlx->ply->pos.y) != '1'
			&& move_on(new_x - COLLISION_MARGIN, mlx->ply->pos.y) != '1')
			mlx->ply->pos.x = new_x;
		if (move_on(mlx->ply->pos.x, new_y + COLLISION_MARGIN) != '1'
			&& move_on(mlx->ply->pos.x, new_y - COLLISION_MARGIN) != '1')
			mlx->ply->pos.y = new_y;
	}
}

void	move_left_right(t_mlx *mlx, t_vec perp)
{
	double	new_x;
	double	new_y;

	if (mlx->keys[2])
	{
		new_x = mlx->ply->pos.x + perp.x * MOV_SPEED;
		new_y = mlx->ply->pos.y + perp.y * MOV_SPEED;
		if (move_on(new_x + COLLISION_MARGIN, mlx->ply->pos.y) != '1'
			&& move_on(new_x - COLLISION_MARGIN, mlx->ply->pos.y) != '1')
			mlx->ply->pos.x = new_x;
		if (move_on(mlx->ply->pos.x, new_y + COLLISION_MARGIN) != '1'
			&& move_on(mlx->ply->pos.x, new_y - COLLISION_MARGIN) != '1')
			mlx->ply->pos.y = new_y;
	}
	if (mlx->keys[3])
	{
		new_x = mlx->ply->pos.x - perp.x * MOV_SPEED;
		new_y = mlx->ply->pos.y - perp.y * MOV_SPEED;
		if (move_on(new_x + COLLISION_MARGIN, mlx->ply->pos.y) != '1'
			&& move_on(new_x - COLLISION_MARGIN, mlx->ply->pos.y) != '1')
			mlx->ply->pos.x = new_x;
		if (move_on(mlx->ply->pos.x, new_y + COLLISION_MARGIN) != '1'
			&& move_on(mlx->ply->pos.x, new_y - COLLISION_MARGIN) != '1')
			mlx->ply->pos.y = new_y;
	}
}

int	update(t_mlx *mlx)
{
	t_vec	perp;

	perp.x = -mlx->ply->dir.y;
	perp.y = mlx->ply->dir.x;
	move_up_down(mlx);
	move_left_right(mlx, perp);
	perfom_rotate(mlx);
	render(mlx);
	return (0);
}
