/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:45:12 by cgama             #+#    #+#             */
/*   Updated: 2025/05/10 03:54:08 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_if_fail(t_mlx *mlx, int text_num)
{
	char	*cardiais[4];

	cardiais[0] = "Norte";
	cardiais[1] = "Sul";
	cardiais[2] = "Oeste";
	cardiais[3] = "Este";
	ft_putstr_fd("Error\nProblem while loading texture ", 2);
	ft_putstr_fd(cardiais[text_num], 2);
	ft_putstr_fd(": ", 2);
	if (text_num == 0)
		ft_putstr_fd(mlx->scene->no, 2);
	else if (text_num == 1)
		ft_putstr_fd(mlx->scene->so, 2);
	else if (text_num == 2)
		ft_putstr_fd(mlx->scene->we, 2);
	else
		ft_putstr_fd(mlx->scene->ea, 2);
	ft_putstr_fd("\n", 2);
	close_game();
}

void	load_one_text(int text_num, char *text_path)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	mlx->scene->texture[text_num].img = mlx_xpm_file_to_image(mlx->cnt,
			text_path, &mlx->scene->texture[text_num].width,
			&mlx->scene->texture[text_num].height);
	if (!mlx->scene->texture[text_num].img)
		exit_if_fail(mlx, text_num);
	mlx->scene->texture[text_num].addr = mlx_get_data_addr(
			mlx->scene->texture[text_num].img,
			&mlx->scene->texture[text_num].bpp,
			&mlx->scene->texture[text_num].line_length,
			&mlx->scene->texture[text_num].endian);
}

void	load_all_texts(t_mlx *mlx)
{
	load_one_text(0, mlx->scene->no);
	load_one_text(1, mlx->scene->so);
	load_one_text(2, mlx->scene->we);
	load_one_text(3, mlx->scene->ea);
}

int	get_texture_color(t_texture *texture, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= texture->width || y >= texture->height)
		return (0);
	dst = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	return (*(int *)dst);
}
