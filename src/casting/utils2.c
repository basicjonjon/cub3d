/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:09:05 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/29 12:15:56 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*find_texture(t_data *data)
{
	if (data->hit.wall_dir == NORTH)
		return (&data->asset.north);
	if (data->hit.wall_dir == SOUTH)
		return (&data->asset.south);
	if (data->hit.wall_dir == EAST)
		return (&data->asset.east);
	if (data->hit.wall_dir == WEST)
		return (&data->asset.west);
	return (NULL);
}

s_dir	find_dir(t_ray *ray, int side)
{
	if (side == 0)
	{
		if (ray->rayDirX > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->rayDirY > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void	clear_image(t_img *img, int width, int height)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			dst = img->addr + y * img->line_lenght + x * img->bit_per_pixels;
			*(unsigned int *)dst = 0x000000;
			x++;
		}
		y++;
	}
}
