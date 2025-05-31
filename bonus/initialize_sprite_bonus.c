/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sprite_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:44:33 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/27 11:37:58 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**get_paths(void)
{
	static char	*sprite_paths[5];

	sprite_paths[0] = "bonus/sprites/shotgun1.xpm";
	sprite_paths[1] = "bonus/sprites/shotgun2.xpm";
	sprite_paths[2] = "bonus/sprites/shotgun3.xpm";
	sprite_paths[3] = "bonus/sprites/shotgun4.xpm";
	sprite_paths[4] = "bonus/sprites/shotgun5.xpm";
	return (sprite_paths);
}

static void	free_weapon(t_mlx *mlx, t_weapon *weapon, int *i)
{
	while (--(*i) >= 0)
		if (weapon->sprites[*i].img)
			mlx_destroy_image(mlx->cnt, weapon->sprites[*i].img);
	if (weapon)
		free(weapon);
	put_error("Failed to load weapon sprite\n");
}

bool	play_animation(t_mlx *mlx, t_weapon *weapon, int *width, int *height)
{
	int		i;
	char	**sprite_paths;

	sprite_paths = get_paths();
	i = 0;
	while (i < 5)
	{
		weapon->sprites[i].img = mlx_xpm_file_to_image(mlx->cnt,
				sprite_paths[i], width, height);
		if (!weapon->sprites[i].img)
		{
			free_weapon(mlx, weapon, &i);
			return (false);
		}
		weapon->sprites[i].addr = mlx_get_data_addr(weapon->sprites[i].img,
				&weapon->sprites[i].bpp,
				&weapon->sprites[i].line_length,
				&weapon->sprites[i].endian);
		weapon->sprites[i].width = *width;
		weapon->sprites[i].height = *height;
		i++;
	}
	return (true);
}

t_weapon	*init_weapon(void)
{
	int			width;
	int			height;
	t_weapon	*weapon;

	weapon = malloc(sizeof(t_weapon));
	if (!weapon)
		return (NULL);
	weapon->width = 256;
	weapon->height = 256;
	if (!weapon)
		return (free(weapon), NULL);
	if (!play_animation(get_mlx(), weapon, &width, &height))
		return (NULL);
	weapon->is_visible = 1;
	weapon->is_firing = 0;
	weapon->current_frame = 0;
	weapon->anim_counter = 0;
	return (weapon);
}
