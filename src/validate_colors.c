/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:11:49 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/09 21:44:35 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_color_range(int value, char *color)
{
	color = ft_strtrim(color, " ");
	if (value < 0 || value > 255 || ft_strlen(color) > 3)
		return (false);
	return (true);
}

bool	std_digit_comma(char *color)
{
	int		x;
	int		y;
	char	*tmp;
	char	**rgb;

	tmp = ft_strtrim(color, " ");
	if (tmp[0] == ',')
		return (false);
	rgb = ft_split(tmp, ',');
	y = 0;
	while (rgb[y])
	{
		tmp = ft_strtrim(rgb[y], " ");
		x = 0;
		while (tmp[x])
		{
			if (ft_isspace(tmp[x]) && tmp[x] != '\n')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	valid_color_format(char *color)
{
	int		i;
	int		comma_count;

	i = 0;
	comma_count = 0;
	if (!color)
		return (false);
	while (color[i])
	{
		if (color[i] == ',')
			comma_count++;
		else if (!ft_isdigit(color[i]) && ft_isprint(color[i])
			&& color[i] != 32)
			return (false);
		i++;
	}
	if (comma_count != 2)
		return (false);
	return (std_digit_comma(color));
}
