/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:47:59 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 02:21:32 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->cnt, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
	clear_img();
}

void	set_ply_dir(t_map *map, t_vec *ply_dir)
{
	if (map->ply_sybl == 'N')
	{
		ply_dir->x = 0;
		ply_dir->y = -1;
	}
	else if (map->ply_sybl == 'S')
	{
		ply_dir->x = 0;
		ply_dir->y = 1;
	}
	else if (map->ply_sybl == 'W')
	{
		ply_dir->x = -1;
		ply_dir->y = 0;
	}
	else if (map->ply_sybl == 'E')
	{
		ply_dir->x = 1;
		ply_dir->y = 0;
	}
}

void	set_ply_plane(t_map *map, t_vec *ply_plane)
{
	if (map->ply_sybl == 'N')
	{
		ply_plane->x = 0.66;
		ply_plane->y = 0;
	}
	else if (map->ply_sybl == 'S')
	{
		ply_plane->x = -0.66;
		ply_plane->y = 0;
	}
	else if (map->ply_sybl == 'W')
	{
		ply_plane->x = 0;
		ply_plane->y = -0.66;
	}
	else if (map->ply_sybl == 'E')
	{
		ply_plane->x = 0;
		ply_plane->y = 0.66;
	}
}

t_ply	*init_player(void)
{
	t_ply	*ply;
	t_mlx	*mlx;

	ply = malloc(sizeof(t_ply));
	mlx = get_mlx();
	ply->pos.x = mlx->scene->map->px + 0.5;
	ply->pos.y = mlx->scene->map->py + 0.5;
	set_ply_dir(mlx->scene->map, &ply->dir);
	set_ply_plane(mlx->scene->map, &ply->plane);
	return (ply);
}

void	initialize(t_mlx *mlx, char *map_src)
{
	mlx->cnt = mlx_init();
	if (!mlx->cnt)
		put_error("Error\nFalha ao inicializar MLX\n");
	mlx->wnd = mlx_new_window(mlx->cnt, WIDTH, HEIGHT, "cub3D");
	mlx->scene = malloc(sizeof(t_scene));
	mlx->scene->error = NULL;
	mlx->scene->no = NULL;
	mlx->scene->ea = NULL;
	mlx->scene->so = NULL;
	mlx->scene->we = NULL;
	mlx->scene->sky = NULL;
	mlx->scene->floor = NULL;
	mlx->scene->map = NULL;
	mlx->scene->has_map = false;
	if (!valid_file_existence(map_src))
		put_error(ERR_WITH_FILE);
	if (!valid_file_format(map_src))
		put_error(ERR_WITH_FILE_FORMAT);
	(fill_scene(map_src), load_all_texts(mlx));
	mlx->ray = malloc(sizeof(t_ray));
	mlx->dda = malloc(sizeof(t_dda));
	mlx->ply = init_player();
}
