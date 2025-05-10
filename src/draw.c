/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:43:30 by dgaspar           #+#    #+#             */
/*   Updated: 2025/04/30 07:00:30 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(int x, int y, int color)
{
	t_mlx	*mlx;
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	mlx = get_mlx();
	offset = y * mlx->line_length + x * (mlx->bpp / 8);
	*(int *)(mlx->addr + offset) = color;
}

void	draw_vertical_line(int x, int start, int end, int color)
{
	int	y;

	if (start < 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT;
	y = start;
	while (y < end)
	{
		put_pixel(x, y, color);
		y++;
	}
}

void	clear_img(void)
{
	int		x;
	int		y;
	t_mlx	*mlx;

	y = 0;
	mlx = get_mlx();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(x, y, mlx->scene->sky_color);
			else
				put_pixel(x, y, mlx->scene->floor_color);
			x++;
		}
		y++;
	}
}

int	set_wall_colors(int side, int step_x, int step_y)
{
	int	color;

	if (side == 0)
	{
		if (step_x > 0)
			color = 0xFF0000;
		else
			color = 0x00FF00;
	}
	else
	{
		if (step_y > 0)
			color = 0x0000FF;
		else
			color = 0xFFFF00;
	}
	return (color);
}

void	paint_sky_and_floor(t_scene *scene)
{
	char	**floor;
	char	**sky;

	floor = ft_split(scene->floor, ',');
	sky = ft_split(scene->sky, ',');
	scene->floor_color = ft_rgb(ft_atoi(floor[0]), ft_atoi(floor[1]),
			ft_atoi(floor[2]));
	scene->sky_color = ft_rgb(ft_atoi(sky[0]), ft_atoi(sky[1]),
			ft_atoi(sky[2]));
}
