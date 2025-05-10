/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 08:17:57 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 10:40:11 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_square(int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			put_pixel(x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_mlx *mlx)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (mlx->scene->map->matriz[++i])
	{
		j = -1;
		while (mlx->scene->map->matriz[i][++j])
		{
			x = j * MINIMAP_SCALE;
			y = i * MINIMAP_SCALE;
			if (mlx->scene->map->matriz[i][j] == '1')
				draw_square(x, y, 0xFFFFFF);
			else if (mlx->scene->map->matriz[i][j] == '0'
				|| mlx->scene->map->matriz[i][j] == ' ')
				draw_square(x, y, 0x000000);
			else if (mlx->scene->map->matriz[i][j] == 'N'
				|| mlx->scene->map->matriz[i][j] == 'S'
				|| mlx->scene->map->matriz[i][j] == 'E'
				|| mlx->scene->map->matriz[i][j] == 'W')
				draw_square(x, y, 0xFF0000);
		}
	}
}
