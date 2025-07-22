/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:14:23 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/22 17:27:30 by jle-doua         ###   ########.fr       */
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

void	put_hud_test(t_data *data)
{
	t_texture	batterie;
	t_texture	rec;
	t_texture	border[4];
	t_texture	center_cam;

	batterie.path = "assets/xpm/hud/batterie/bat5.xpm";
	rec.path = "assets/xpm/hud/rec/recwp.xpm";
	border[0].path = "assets/xpm/hud/border/left_top.xpm";
	border[1].path = "assets/xpm/hud/border/rigth_top.xpm";
	border[2].path = "assets/xpm/hud/border/rigth_bottom.xpm";
	border[3].path = "assets/xpm/hud/border/left_bottom.xpm";
	center_cam.path = "assets/xpm/hud/border/center_cam.xpm";
	create_img(data, &batterie);
	create_img(data, &rec);
	create_img(data, &border[0]);
	create_img(data, &border[1]);
	create_img(data, &border[2]);
	create_img(data, &border[3]);
	create_img(data, &center_cam);
	print_texture(data, &border[0], 10, 10);
	print_texture(data, &border[1], screenWidth - 210, 10);
	print_texture(data, &border[2], screenWidth - 210, screenHeight - 210);
	print_texture(data, &border[3], 10, screenHeight - 210);
	print_texture(data, &center_cam, (screenWidth - 210) / 2, (screenHeight - 210) / 2);
	print_texture(data, &batterie, screenWidth - 210, 10);
	print_texture(data, &rec, 60, 10);
}
