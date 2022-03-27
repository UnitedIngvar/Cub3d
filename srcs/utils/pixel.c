/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:17:39 by chasimir          #+#    #+#             */
/*   Updated: 2022/03/27 17:29:47 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_textures *txt, int x, int y)
{
	int	color;

	color = *(unsigned int *)(txt->img_value
			+ (y * txt->line_len + x * (txt->bpp / 8)));
	return (color);
}
