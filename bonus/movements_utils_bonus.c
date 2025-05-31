/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 05:01:42 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/29 14:49:15 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_press(int kc, t_mlx *mlx)
{
	if (kc == _W)
		mlx->keys[0] = true;
	if (kc == _A)
		mlx->keys[3] = true;
	if (kc == _S)
		mlx->keys[1] = true;
	if (kc == _D)
		mlx->keys[2] = true;
	if (kc == _LEFT)
		mlx->keys[4] = true;
	if (kc == _RIGTH)
		mlx->keys[5] = true;
	if (kc == _E)
		mlx->keys[6] = true;
	if (kc == SHIFT && mlx->scene->show_minimap == false)
		mlx->scene->show_minimap = true;
	else if (kc == SHIFT && mlx->scene->show_minimap == true)
		mlx->scene->show_minimap = false;
	if (kc == ESCAPE)
		close_game();
	return (0);
}

int	key_release(int kc, t_mlx *mlx)
{
	if (kc == _W)
		mlx->keys[0] = false;
	if (kc == _A)
		mlx->keys[3] = false;
	if (kc == _S)
		mlx->keys[1] = false;
	if (kc == _D)
		mlx->keys[2] = false;
	if (kc == _LEFT)
		mlx->keys[4] = false;
	if (kc == _RIGTH)
		mlx->keys[5] = false;
	if (kc == _E)
		mlx->keys[6] = false;
	return (0);
}

char	move_on(double x, double y)
{
	t_mlx	*mlx;
	int		grid_x;
	int		grid_y;

	mlx = get_mlx();
	grid_x = (int)x;
	grid_y = (int)y;
	if (mlx->scene->map->matriz[grid_y][grid_x] == DOOR_CHAR)
		return ('1');
	if (mlx->scene->map->matriz[grid_y][grid_x] == DOOR_OPEN_CHAR)
		return ('0');
	return (mlx->scene->map->matriz[grid_y][grid_x]);
}

int	update(t_mlx *mlx)
{
	t_vec	perp;

	perp.x = -mlx->ply->dir.y;
	perp.y = mlx->ply->dir.x;
	move_up(mlx->ply, mlx->scene->map, mlx->keys[0]);
	move_down(mlx->ply, mlx->scene->map, mlx->keys[1]);
	move_left(mlx->ply, mlx->scene->map, perp, mlx->keys[2]);
	move_right(mlx->ply, mlx->scene->map, perp, mlx->keys[3]);
	perfom_rotate(mlx);
	check_door_interaction(mlx);
	update_doors(mlx);
	render(mlx);
	return (0);
}
