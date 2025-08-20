/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:14:23 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/21 00:18:55 by mmarps           ###   ########.fr       */
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

void	calc_rec(t_data *data)
{
	data->hud.rec_tempo++;
	if (data->hud.rec_tempo == 40)
	{
		data->hud.rec_tempo = 0;
		if (data->hud.rec_position == 0)
			data->hud.rec_position = 1;
		else
			data->hud.rec_position = 0;
	}
}

void	calc_batterie(t_data *data)
{
	if (get_time() - data->hud.bat_tempo > 500 && data->hud.bat_pos > 0)
	{
		data->hud.bat_tempo = get_time();
		if (data->hud.bat_pos == data->hud.save_bat_pos)
			data->hud.bat_pos--;
		else
			data->hud.bat_pos++;
	}
	if (get_time() - data->hud.time_start > 1000)
	{
		data->hud.time_start = get_time();
		if (data->hud.bat_pos != 0)
		{
			data->hud.bat_pos = data->hud.save_bat_pos - 1;
			data->hud.save_bat_pos = data->hud.bat_pos;
		}
	}
}

void	print_hud(t_data *data)
{
	calc_rec(data);
	calc_batterie(data);
	print_texture(data, &data->hud.border[0], 10, 10);
	print_texture(data, &data->hud.border[1], SCREENWIDTH - 210, 10);
	print_texture(data, &data->hud.border[2], SCREENWIDTH - 210, SCREENHEIGHT
		- 210);
	print_texture(data, &data->hud.border[3], 10, SCREENHEIGHT - 210);
	print_texture(data, &data->hud.center_cam, (SCREENWIDTH - 210) / 2,
		(SCREENHEIGHT - 210) / 2);
	print_texture(data, &data->hud.batterie[data->hud.bat_pos], SCREENWIDTH
		- 220, 100);
	print_texture(data, &data->hud.rec[data->hud.rec_position], 100, 100);
}
