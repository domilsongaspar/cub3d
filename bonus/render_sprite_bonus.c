/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:03:31 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/26 13:13:48 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	fire_frame(t_mlx *mlx)
{
	if (mlx->weapon->is_firing)
	{
		mlx->weapon->anim_counter++;
		if (mlx->weapon->anim_counter % 5 == 0)
		{
			mlx->weapon->current_frame++;
			if (mlx->weapon->current_frame >= 5)
			{
				mlx->weapon->current_frame = 0;
				mlx->weapon->is_firing = 0;
			}
		}
	}
}

void	draw_weapon(t_mlx *mlx)
{
	int		current;
	int		tex_color;
	t_pos	weapon;
	t_pos	iter;

	if (!mlx->weapon || !mlx->weapon->is_visible)
		return ;
	current = 0;
	if (mlx->weapon->is_firing)
		current = mlx->weapon->current_frame;
	weapon.x = (WIDTH - mlx->weapon->sprites[current].width) / 3;
	weapon.y = HEIGHT - mlx->weapon->sprites[current].height + 1;
	iter.x = -1;
	while (++iter.x < mlx->weapon->sprites[current].width)
	{
		iter.y = -1;
		while (++iter.y < mlx->weapon->sprites[current].height)
		{	
			tex_color = get_texture_color(&mlx->weapon->sprites[current],
					iter.x, iter.y);
			if (tex_color != -1)
				put_pixel(weapon.x + iter.x, weapon.y + iter.y, tex_color);
		}
	}
	fire_frame(mlx);
}
