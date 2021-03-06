/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:35:33 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/03/27 17:57:51 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_all_raycast(t_game *main)
{
	if (main->raycast->keys)
		free(main->raycast->keys);
	free_txtr(main);
	mlx_destroy_image(main->raycast->mlx, main->raycast->pixel->img);
	mlx_destroy_window(main->raycast->mlx, main->raycast->win);
	if (main->raycast->pixel)
		free(main->raycast->pixel);
	if (main->raycast)
		free(main->raycast);
}

void	free_txtr(t_game *main)
{
	if (main->west)
		free(main->west);
	if (main->east)
		free(main->east);
	if (main->north)
		free(main->north);
	if (main->south)
		free(main->south);
}
