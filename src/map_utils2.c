/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:38:43 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/31 14:25:58 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_data(t_mlx *mlx, char *line, int len)
{
	if (ft_strncmp(line, "NO ", len) == 0)
		mlx->scene->no = ft_strtrim(ft_strdup(line + len), " ");
	else if (ft_strncmp(line, "SO ", len) == 0)
		mlx->scene->so = ft_strtrim(ft_strdup(line + len), " ");
	else if (ft_strncmp(line, "WE ", len) == 0)
		mlx->scene->we = ft_strtrim(ft_strdup(line + len), " ");
	else if (ft_strncmp(line, "EA ", len) == 0)
		mlx->scene->ea = ft_strtrim(ft_strdup(line + len), " ");
	else if (ft_strncmp(line, "F ", len) == 0)
		mlx->scene->floor = ft_strtrim(ft_strdup(line + len), " ");
	else if (ft_strncmp(line, "C ", len) == 0)
		mlx->scene->sky = ft_strtrim(ft_strdup(line + len), " ");
	free(line);
}

void	close_if_duplicated(t_mlx *mlx, char *line)
{
	if (has_duplicated_color(mlx->scene, line)
		|| has_duplicated_texture(mlx->scene, line))
	{
		free(line);
		put_error(mlx->scene->error);
	}
}
