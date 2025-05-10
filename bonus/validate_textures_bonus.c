/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:11:32 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 07:05:57 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	valid_texture_format(char *src)
{
	int	len;

	len = ft_strlen(src);
	if (is_invisible_line(src) || len < 4)
		return (false);
	if (src[len - 4] == '.' && src[len - 3] == 'x'
		&& src[len - 2] == 'p' && src[len - 1] == 'm')
		return (true);
	return (false);
}

void	validate_textures(t_scene *scene)
{
	if (missing_texture(scene))
		put_error(scene->error);
	if (!valid_texture_format(scene->no)
		|| !valid_texture_format(scene->ea)
		|| !valid_texture_format(scene->so)
		|| !valid_texture_format(scene->we))
		put_error(ERR_WITH_FILE_FORMAT);
	if (!valid_file_existence(scene->no)
		|| !valid_file_existence(scene->ea)
		|| !valid_file_existence(scene->so)
		|| !valid_file_existence(scene->we))
		put_error(ERR_WITH_TEXTURE_FILE);
}
