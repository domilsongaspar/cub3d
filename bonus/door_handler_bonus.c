/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:26:23 by cgama             #+#    #+#             */
/*   Updated: 2025/05/29 16:34:23 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_door	*find_door(t_mlx *mlx, int x, int y)
{
	int	i;

	i = 0;
	while (i < mlx->scene->door_count)
	{
		if (mlx->scene->doors[i].x == x && mlx->scene->doors[i].y == y)
			return (&mlx->scene->doors[i]);
		i++;
	}
	return (NULL);
}

void	set_texture_number(t_mlx *mlx, t_tex *tex)
{
	if (mlx->scene->map->matriz[mlx->ray->map_y][mlx->ray->map_x] == DOOR_CHAR
		|| mlx->scene->map->matriz[mlx->ray->map_y][mlx->ray->map_x]
		== DOOR_OPEN_CHAR)
	{
		tex->text_num = 4;
	}
	else if (mlx->dda->side == 0)
	{
		if (mlx->ray->step_x > 0)
			tex->text_num = 2;
		else
			tex->text_num = 3;
	}
	else
	{
		if (mlx->ray->step_y > 0)
			tex->text_num = 0;
		else
			tex->text_num = 1;
	}
}
