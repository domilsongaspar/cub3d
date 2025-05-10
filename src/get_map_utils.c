/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:24:52 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/09 21:31:53 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	findp(t_map *map, int y)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(map->matriz[y]);
	while (x < len)
	{
		if (ft_strchr("NSEW", map->matriz[y][x]))
		{
			map->px = x;
			map->py = y;
			map->ply_sybl = map->matriz[y][x];
			return ;
		}
		x++;
	}
}

void	increase_line_counter(int *val, int *data, char *line)
{
	if (*data > 5 && !is_texture_or_color(line) && !is_invisible_line(line))
	{
		*data = -1;
		(*val)++;
	}
	if (*data == -1)
		(*val)++;
}

void	get_map_loop(int fd, char *line, int *i, t_map *map)
{
	int		maxc;

	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		if (!is_texture_or_color(line))
		{
			if (*i == 0 && is_invisible_line(line))
				continue ;
			map->matriz[*i] = ft_strdup(line);
			maxc = ft_strlen(map->matriz[*i]);
			findp(map, *i);
			if (maxc > map->maxc)
				map->maxc = maxc;
			(*i)++;
		}
	}
}
