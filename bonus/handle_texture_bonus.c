/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:47:37 by cgama             #+#    #+#             */
/*   Updated: 2025/05/29 16:35:30 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	initialize_all_textures(t_mlx *mlx)
{
	mlx->scene->texture[0].img = NULL;
	mlx->scene->texture[1].img = NULL;
	mlx->scene->texture[2].img = NULL;
	mlx->scene->texture[3].img = NULL;
	mlx->scene->texture[4].img = NULL;
}

void	draw_line( t_mlx *mlx, t_tex *tex, int x)
{
	while (tex->y < mlx->dda->draw_end)
	{
		tex->text_y = (int)tex->text_pos
			& ((mlx->scene->texture[tex->text_num]).height - 1);
		tex->text_pos += tex->step;
		tex->color = get_texture_color(
				&mlx->scene->texture[tex->text_num],
				tex->text_x, tex->text_y);
		put_pixel(x, tex->y, tex->color);
		tex->y++;
	}
}

void	draw_textured_line(t_mlx *mlx, int x, t_vec *ray)
{
	t_tex	tex;
	int		line_height;

	set_texture_number(mlx, &tex);
	if (mlx->dda->draw_start < 0)
		mlx->dda->draw_start = 0;
	if (mlx->dda->draw_end >= HEIGHT)
		mlx->dda->draw_end = HEIGHT - 1;
	tex.wallx = mlx->ply->pos.x + mlx->dda->perp_dist * ray->x;
	if (mlx->dda->side == 0)
		tex.wallx = mlx->ply->pos.y + mlx->dda->perp_dist * ray->y;
	tex.wallx -= floor(tex.wallx);
	tex.text_x = (int)(tex.wallx
			* (double)mlx->scene->texture[tex.text_num].width);
	line_height = mlx->dda->line_height;
	if (line_height < 1)
		line_height = 1;
	tex.step = (double)mlx->scene->texture[tex.text_num].height / line_height;
	tex.text_pos = (mlx->dda->draw_start - HEIGHT / 2 + line_height / 2)
		* tex.step;
	tex.y = mlx->dda->draw_start;
	draw_line(mlx, &tex, x);
}
