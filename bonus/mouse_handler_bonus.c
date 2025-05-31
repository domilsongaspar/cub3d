/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:21:34 by cgama             #+#    #+#             */
/*   Updated: 2025/05/29 14:49:34 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	mouse_rotate(t_mlx *mlx, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

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

int	mouse_move_handler(int x, int y, t_mlx *mlx)
{
	static int	prev_x = -1;

	(void) y;
	if (prev_x == -1)
	{
		prev_x = x;
		return (0);
	}
	if (x - prev_x != 0)
	{
		if (x - prev_x < 0)
			mouse_rotate(mlx, -(MOUSE_ROT_SPEED / 3));
		else
			mouse_rotate(mlx, MOUSE_ROT_SPEED / 3);
		prev_x = x;
		render(mlx);
	}
	if (x < WIDTH / 4 || x > WIDTH * 3 / 4)
		mlx_mouse_move(mlx->cnt, mlx->wnd, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 1 && !mlx->weapon->is_firing)
	{
		mlx->weapon->is_firing = 1;
		mlx->weapon->current_frame = 0;
		mlx->weapon->anim_counter = 0;
	}
	return (0);
}
