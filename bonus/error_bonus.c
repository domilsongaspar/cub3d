/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 07:24:18 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 07:05:47 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	exit_clean(void)
{
	close_game();
	exit (EXIT_FAILURE);
}

void	put_error(char *error)
{
	if (!error)
		return ;
	write(STDERR_FILENO, error, ft_strlen(error));
	exit_clean();
}
