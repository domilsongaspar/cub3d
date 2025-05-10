/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:52 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 02:37:16 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	free_textures(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mlx->scene->texture[i].img)
		{
			mlx_destroy_image(mlx->cnt, mlx->scene->texture[i].img);
		}
		i++;
	}
}

int	close_game(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	free_textures(mlx);
	mlx_destroy_window(mlx->cnt, mlx->wnd);
	mlx_destroy_display(mlx->cnt);
	free(mlx->cnt);
	free(mlx->dda);
	free(mlx->ray);
	free(mlx->ply);
	if (mlx->scene->map && mlx->scene->map->copy)
		free_matriz(mlx->scene->map->copy);
	free(mlx->scene);
	ft_free_collector();
	exit(0);
}
