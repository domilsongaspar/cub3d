/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:52:36 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 07:05:47 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	count_line(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		if (!is_invisible_line(line) && !is_texture_or_color(line))
			i++;
	}
	close(fd);
	return (i);
}

int	count_with_newline(char *filename)
{
	int		i;
	int		fd;
	int		data;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	data = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		if (data >= 0 && data < 6 && is_invisible_line(line))
			continue ;
		if (is_texture_or_color(line))
			data++;
		increase_line_counter(&i, &data, line);
	}
	close(fd);
	return (i - 1);
}

int	init_map(t_map *map, char *filename)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	map->maxl = count_line(filename);
	map->maxl_with_nl = count_with_newline(filename);
	map->copy = NULL;
	if (map->maxl > 0)
		mlx->scene->has_map = true;
	if (map->maxl_with_nl == -1)
		return (EXIT_FAILURE);
	map->matriz = ft_calloc(sizeof(char *), map->maxl_with_nl + 2);
	return (0);
}

t_map	*get_map(char *filename)
{
	int		i;
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	map = ft_calloc(sizeof(t_map), 1);
	if (init_map(map, filename) == EXIT_FAILURE)
		return (NULL);
	if ((!map || fd < 0))
		return (NULL);
	line = NULL;
	i = 0;
	get_map_loop(fd, line, &i, map);
	map->matriz[i] = NULL;
	close(fd);
	return (map);
}
