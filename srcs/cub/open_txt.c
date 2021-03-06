/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:35:54 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/03/27 18:01:02 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_txt(t_game *main)
{
	main->north = malloc(sizeof(t_textures));
	main->south = malloc(sizeof(t_textures));
	main->east = malloc(sizeof(t_textures));
	main->west = malloc(sizeof(t_textures));
	if (!main->north || !main->south || !main->west || !main->east)
	{
		free_txtr(main);
		exit(EXIT_FAILURE);
	}
	load_txt(main);
}

void	open_txt(t_game *main, t_textures *txt, char *path)
{
	if (access(path, O_RDONLY) == -1)
		ft_error(main, "Some texture is missing or access is denied\n", 0);
	txt->img_ptr = mlx_xpm_file_to_image(main->raycast->mlx,
			path, &txt->width, &txt->height);
	txt->img_value = mlx_get_data_addr(txt->img_ptr, &txt->bpp,
			&txt->line_len, &txt->endian);
}

void	load_txt(t_game *main)
{
	open_txt(main, main->north, main->nswe[0]);
	open_txt(main, main->south, main->nswe[1]);
	open_txt(main, main->west, main->nswe[2]);
	open_txt(main, main->east, main->nswe[3]);
}
