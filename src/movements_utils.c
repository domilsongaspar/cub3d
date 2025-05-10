/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 05:01:42 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 06:39:09 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (grid_x >= 1 && grid_x < mlx->scene->map->maxc - 2
		&& grid_y >= 1 && grid_y < mlx->scene->map->maxl)
	{
		return ('0');
	}
	return ('1');
}
