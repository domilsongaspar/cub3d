/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:28:21 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/06 16:02:41 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*strdup_fill_repl_space(char *s, int size)
{
	int		i;
	char	*new_str;

	if (!s)
		return (NULL);
	i = 0;
	new_str = malloc(sizeof(char) * (size + 1));
	while (s[i] && s[i] != '\n')
	{
		new_str[i] = s[i];
		i++;
	}
	while (i < size - 1)
	{
		new_str[i] = ' ';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	dup_map(char **map)
{
	int		i;
	int		longst;
	t_mlx	*mlx;
	t_map	*tmap;

	mlx = get_mlx();
	tmap = mlx->scene->map;
	if (!tmap->matriz[0])
		return ;
	tmap->copy = (char **)malloc(sizeof(char *) * (tmap->maxl_with_nl + 1));
	i = 0;
	longst = get_longest_line(map);
	while (map[i])
	{
		tmap->copy[i] = strdup_fill_repl_space(map[i], longst);
		i++;
	}
	tmap->copy[i] = NULL;
}

size_t	ft_strlen_line(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
