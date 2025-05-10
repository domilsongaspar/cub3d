/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:44:05 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/09 21:44:10 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	*get_mlx(void)
{
	static t_mlx	*mlx;

	if (!mlx)
		mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	return (mlx);
}

char	map_at(int x, int y)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	if (x >= 0 && x < mlx->scene->map->maxc
		&& y >= 0 && y < mlx->scene->map->maxl)
	{
		return (mlx->scene->map->matriz[y][x]);
	}
	return ('1');
}

bool	is_invisible_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t'
			&& line[i] != '\v' && line[i] != '\f'
			&& line[i] != '\r' && line[i] != '\0')
			return (false);
		i++;
	}
	return (true);
}

int	ft_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

char	*ft_strcspn(char *str, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != c)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
