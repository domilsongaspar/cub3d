/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:06:40 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 07:05:50 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	is_texture_or_color(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (ft_strncmp(tmp, "NO", 2) == 0 || ft_strncmp(tmp, "SO", 2) == 0
		|| ft_strncmp(tmp, "WE", 2) == 0 || ft_strncmp(tmp, "EA", 2) == 0
		|| ft_strncmp(tmp, "F", 1) == 0 || ft_strncmp(tmp, "C", 1) == 0)
		return (true);
	return (false);
}

bool	has_duplicated_texture(t_scene *scene, char *elem)
{
	if (ft_strncmp(elem, "NO", 2) == 0 && scene->no)
	{
		scene->error = ERR_DUP_NO_TEXTURE;
		return (true);
	}
	if (ft_strncmp(elem, "SO", 2) == 0 && scene->so)
	{
		scene->error = ERR_DUP_SO_TEXTURE;
		return (true);
	}
	if (ft_strncmp(elem, "WE", 2) == 0 && scene->we)
	{
		scene->error = ERR_DUP_WE_TEXTURE;
		return (true);
	}
	if (ft_strncmp(elem, "EA", 2) == 0 && scene->ea)
	{
		scene->error = ERR_DUP_EA_TEXTURE;
		return (true);
	}
	return (false);
}

bool	has_duplicated_color(t_scene *scene, char *elem)
{
	if (ft_strncmp(elem, "F", 1) == 0 && scene->floor)
	{
		scene->error = ERR_DUP_FLOOR_COLOR;
		return (true);
	}
	if (ft_strncmp(elem, "C", 1) == 0 && scene->sky)
	{
		scene->error = ERR_DUP_CEIL_COLOR;
		return (true);
	}
	return (false);
}

void	fill_colors_and_textures(t_mlx *mlx, char *filename)
{
	int		fd;
	int		len;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		tmp = ft_strtrim(get_next_line(fd), " ");
		line = NULL;
		if (!*tmp)
			break ;
		if (is_invisible_line(tmp))
			continue ;
		line = ft_strcspn(tmp, '\n');
		if (!line || !*line)
			break ;
		close_if_duplicated(mlx, line);
		tmp = ft_strcspn(line, ' ');
		len = ft_strlen(tmp) + 1;
		(free(tmp), fill_data(mlx, line, len));
	}
	if (line)
		free(line);
	close(fd);
}

void	fill_scene(char	*filename)
{
	t_mlx	*mlx;
	int		i;

	mlx = get_mlx();
	mlx->scene->map = get_map(filename);
	fill_colors_and_textures(mlx, filename);
	i = 0;
	while (i < 4)
		mlx->scene->texture[i++].img = NULL;
	if (mlx->scene->has_map)
	{
		if (missing_texture(mlx->scene) || missing_color(mlx->scene))
			put_error(mlx->scene->error);
		if (!mlx->scene->map)
			put_error(ERR_MAP_WRONG_POS);
	}
	else
		put_error(ERR_MISSING_MAP);
	dup_map(mlx->scene->map->matriz);
}
