/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:10:14 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 07:05:56 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	valid_file_format(char *src)
{
	int	len;

	len = ft_strlen(src);
	if (src[len - 4] == '.' && src[len - 3] == 'c'
		&& src[len - 2] == 'u' && src[len - 1] == 'b')
		return (true);
	return (false);
}

bool	valid_file_existence(char *src)
{
	int	fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	is_empty_file(char *src)
{
	int		fd;
	char	buff[24];

	fd = open(src, O_RDONLY);
	if (read(fd, buff, 23) == 0)
		return (true);
	close(fd);
	return (false);
}

bool	imcomplete_color(char **matriz)
{
	if (!matriz[0] || !matriz[1] || !matriz[2])
		return (true);
	return (false);
}

void	validate_scene(t_scene *scene, char *src)
{
	char	**sky;
	char	**floor;

	if (is_missing(scene))
		put_error(scene->error);
	if (is_empty_file(src))
		put_error(ERR_EMPTY_FILE);
	if (!valid_color_format(scene->sky))
		put_error(ERR_WITH_SKY_COLOR);
	if (!valid_color_format(scene->floor))
		put_error(ERR_WITH_FLOOR_COLOR);
	sky = ft_split(scene->sky, ',');
	floor = ft_split(scene->floor, ',');
	if (imcomplete_color(sky) || !valid_color_range(ft_atoi(sky[0]), sky[0])
		|| !valid_color_range(ft_atoi(sky[1]), sky[1])
		|| !valid_color_range(ft_atoi(sky[2]), sky[2]))
		put_error(ERR_WITH_SKY_COLOR);
	if (imcomplete_color(floor)
		|| !valid_color_range(ft_atoi(floor[0]), floor[0])
		|| !valid_color_range(ft_atoi(floor[1]), floor[1])
		|| !valid_color_range(ft_atoi(floor[2]), floor[2]))
		put_error(ERR_WITH_FLOOR_COLOR);
	validate_textures(scene);
	validate_map(scene);
}
