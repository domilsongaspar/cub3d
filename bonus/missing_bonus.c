/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:04:34 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 07:05:52 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	missing_texture(t_scene *scene)
{
	if ((!scene->no && !scene->error) || (is_invisible_line(scene->no)))
	{
		scene->error = ft_strdup("Missing NO texture\n");
		return (true);
	}
	if ((!scene->so && !scene->error) || (is_invisible_line(scene->so)))
	{
		scene->error = ft_strdup("Missing SO texture\n");
		return (true);
	}
	if ((!scene->we && !scene->error) || (is_invisible_line(scene->we)))
	{
		scene->error = ft_strdup("Missing WE texture\n");
		return (true);
	}
	if ((!scene->ea && !scene->error) || (is_invisible_line(scene->ea)))
	{
		scene->error = ft_strdup("Missing EA texture\n");
		return (true);
	}
	return (false);
}

bool	missing_color(t_scene *scene)
{
	if ((!scene->floor && !scene->error) || (is_invisible_line(scene->floor)))
	{
		scene->error = ft_strdup("Missing floor color\n");
		return (true);
	}
	if ((!scene->sky && !scene->error) || (is_invisible_line(scene->sky)))
	{
		scene->error = ft_strdup("Missing sky color\n");
		return (true);
	}
	return (false);
}

bool	missing_map(t_scene *scene)
{
	if ((!scene->map || !scene->map->matriz[0]) && !scene->error)
	{
		scene->error = ft_strdup(ERR_MISSING_MAP);
		return (true);
	}
	return (false);
}

bool	is_missing(t_scene *scene)
{
	if (missing_texture(scene) || missing_color(scene)
		|| missing_map(scene) || scene->error)
		return (true);
	return (false);
}
