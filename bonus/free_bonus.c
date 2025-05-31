/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:52 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/29 15:17:32 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	while (i < 5)
	{
		if (mlx->scene->texture[i].img)
		{
			mlx_destroy_image(mlx->cnt, mlx->scene->texture[i].img);
		}
		i++;
	}
}

void	free_weapon(t_mlx *mlx)
{
	int	i;

	if (!mlx->weapon)
		return ;
	i = 0;
	while (i < 5)
	{
		if (mlx->weapon->sprites[i].img)
			mlx_destroy_image(mlx->cnt, mlx->weapon->sprites[i].img);
		i++;
	}
	free(mlx->weapon);
}

int	close_game(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	free_textures(mlx);
	free_weapon(mlx);
	mlx_mouse_show(mlx->cnt, mlx->wnd);
	mlx_destroy_window(mlx->cnt, mlx->wnd);
	mlx_destroy_display(mlx->cnt);
	free(mlx->cnt);
	free(mlx->dda);
	free(mlx->ray);
	free(mlx->ply);
	if (mlx->scene->doors)
		free(mlx->scene->doors);
	if (mlx->scene->map && mlx->scene->map->copy)
		free_matriz(mlx->scene->map->copy);
	free(mlx->scene);
	ft_free_collector();
	exit(0);
}
