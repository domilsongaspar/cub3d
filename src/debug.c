/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:07:25 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/31 12:20:48 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_scene(t_scene *scene)
{
	if (is_missing(scene))
	{
		printf("Error\n%s\n", scene->error);
		return ;
	}
	printf("NO:%s\n", scene->no);
	printf("SO:%s\n", scene->so);
	printf("WE:%s\n", scene->we);
	printf("EA:%s\n", scene->ea);
	printf("F:%s\n", scene->floor);
	printf("C:%s\n", scene->sky);
	print_map(scene->map->matriz);
}

void	print_map(char **matriz)
{
	int	x;
	int	y;

	y = 0;
	while (matriz[y])
	{
		x = 0;
		while (matriz[y][x])
		{
			write(STDOUT_FILENO, &matriz[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
