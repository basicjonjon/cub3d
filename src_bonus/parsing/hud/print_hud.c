/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:14:23 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/25 15:04:44 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	print_texture(t_data *data, t_texture *texture, int x, int y)
{
	int	save_x;
	int	x_t;
	int	y_t;
	int	color;

	save_x = x;
	y_t = 0;
	while (y_t < texture->tex_h)
	{
		x_t = 0;
		x = save_x;
		while (x_t < texture->tex_w)
		{
			color = get_texture_pixel(texture, x_t, y_t);
			if (color > 0)
			{
				ft_pixel_put(x, y, &data->img, color);
			}
			x++;
			x_t++;
		}
		y++;
		y_t++;
	}
}

void	print_hud(t_data *data)
{
	(void)data;
	print_texture(data, &data->hud.border[0], 10, 10);
	print_texture(data, &data->hud.border[1], screenWidth - 210, 10);
	print_texture(data, &data->hud.border[2], screenWidth - 210, screenHeight
		- 210);
	print_texture(data, &data->hud.border[3], 10, screenHeight - 210);
	print_texture(data, &data->hud.center_cam, (screenWidth - 210) / 2,
		(screenHeight - 210) / 2);
	print_texture(data, &data->hud.batterie[5], screenWidth - 209, 90);
	print_texture(data, &data->hud.rec[1], 60, 10);
}
