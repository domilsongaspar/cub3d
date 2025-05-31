/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:43:35 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 04:17:52 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_mlx *mlx, t_vec *ray, double cam_x)
{
	ray->x = mlx->ply->dir.x + mlx->ply->plane.x * cam_x;
	ray->y = mlx->ply->dir.y + mlx->ply->plane.y * cam_x;
	mlx->ray->map_x = (int)mlx->ply->pos.x;
	mlx->ray->map_y = (int)mlx->ply->pos.y;
	mlx->ray->delta_x = fabs(1 / ray->x);
	mlx->ray->delta_y = fabs(1 / ray->y);
}

void	calculate_sides(t_vec *ray, t_mlx *mlx)
{
	if (ray->x < 0)
	{
		mlx->ray->step_x = -1;
		mlx->ray->side_x = (mlx->ply->pos.x - mlx->ray->map_x) \
		* mlx->ray->delta_x;
	}
	else
	{
		mlx->ray->step_x = 1;
		mlx->ray->side_x = (mlx->ray->map_x + 1.0 - mlx->ply->pos.x) \
		* mlx->ray->delta_x;
	}
	if (ray->y < 0)
	{
		mlx->ray->step_y = -1;
		mlx->ray->side_y = (mlx->ply->pos.y - mlx->ray->map_y) \
		* mlx->ray->delta_y;
	}
	else
	{
		mlx->ray->step_y = 1;
		mlx->ray->side_y = (mlx->ray->map_y + 1.0 - mlx->ply->pos.y) \
		* mlx->ray->delta_y;
	}
}

void	calculate_dda(t_mlx *mlx, t_vec ray)
{
	mlx->dda->hit = 0;
	while (!mlx->dda->hit)
	{
		if (mlx->ray->side_x < mlx->ray->side_y)
		{
			mlx->ray->side_x += mlx->ray->delta_x;
			mlx->ray->map_x += mlx->ray->step_x;
			mlx->dda->side = X;
		}
		else
		{
			mlx->ray->side_y += mlx->ray->delta_y;
			mlx->ray->map_y += mlx->ray->step_y;
			mlx->dda->side = Y;
		}
		if (map_at(mlx->ray->map_x, mlx->ray->map_y) == '1')
			mlx->dda->hit = 1;
	}
	draw_height(mlx, ray);
}

void	draw_height(t_mlx *mlx, t_vec ray)
{
	mlx->dda->perp_dist = (mlx->ray->map_y - mlx->ply->pos.y + \
		(1 - mlx->ray->step_y) / 2) / ray.y;
	if (mlx->dda->side == X)
		mlx->dda->perp_dist = (mlx->ray->map_x - mlx->ply->pos.x + \
			(1 - mlx->ray->step_x) / 2) / ray.x;
	mlx->dda->line_height = (int)(HEIGHT / mlx->dda->perp_dist);
	mlx->dda->draw_start = HEIGHT / 2 - mlx->dda->line_height / 2;
	mlx->dda->draw_end = HEIGHT / 2 + mlx->dda->line_height / 2;
}

void	render(t_mlx *mlx)
{
	int			x;
	double		cam_x;
	t_vec		ray;

	x = -1;
	init_image(mlx);
	while (++x < WIDTH)
	{
		cam_x = 2 * x / (double)WIDTH - 1;
		init_ray(mlx, &ray, cam_x);
		calculate_sides(&ray, mlx);
		calculate_dda(mlx, ray);
		draw_textured_line(mlx, x, &ray);
	}
	mlx_put_image_to_window(mlx->cnt, mlx->wnd, mlx->img, 0, 0);
	mlx_destroy_image(mlx->cnt, mlx->img);
}
