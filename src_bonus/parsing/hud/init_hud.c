/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:05:48 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/28 14:56:17 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_batterie(t_data *data)
{
	data->hud.batterie[0].path = BAT0;
	data->hud.batterie[1].path = BAT1;
	data->hud.batterie[2].path = BAT2;
	data->hud.batterie[3].path = BAT3;
	data->hud.batterie[4].path = BAT4;
	data->hud.batterie[5].path = BAT5;
	create_img(data, &data->hud.batterie[0]);
	if (!data->hud.batterie[0].img.img_ptr)
		return (1);
	create_img(data, &data->hud.batterie[1]);
	if (!data->hud.batterie[1].img.img_ptr)
		return (1);
	create_img(data, &data->hud.batterie[2]);
	if (!data->hud.batterie[2].img.img_ptr)
		return (1);
	create_img(data, &data->hud.batterie[3]);
	if (!data->hud.batterie[3].img.img_ptr)
		return (1);
	create_img(data, &data->hud.batterie[4]);
	if (!data->hud.batterie[4].img.img_ptr)
		return (1);
	create_img(data, &data->hud.batterie[5]);
	if (!data->hud.batterie[5].img.img_ptr)
		return (1);
	return (0);
}

int	init_border(t_data *data)
{
	data->hud.border[0].path = BORDERLT;
	data->hud.border[1].path = BORDERRT;
	data->hud.border[2].path = BORDERRB;
	data->hud.border[3].path = BORDERLB;
	data->hud.center_cam.path = CENTERCAM;
	create_img(data, &data->hud.border[0]);
	if (!data->hud.border[0].img.img_ptr)
		return (1);
	create_img(data, &data->hud.border[1]);
	if (!data->hud.border[1].img.img_ptr)
		return (1);
	create_img(data, &data->hud.border[2]);
	if (!data->hud.border[2].img.img_ptr)
		return (1);
	create_img(data, &data->hud.border[3]);
	if (!data->hud.border[3].img.img_ptr)
		return (1);
	create_img(data, &data->hud.center_cam);
	if (!data->hud.center_cam.img.img_ptr)
		return (1);
	return (0);
}

int	init_rec(t_data *data)
{
	data->hud.rec[0].path = RECNP;
	data->hud.rec[1].path = RECP;
	create_img(data, &data->hud.rec[0]);
	if (!data->hud.rec[0].img.img_ptr)
		return (printf(RED "ERROR1" NC), 1);
	create_img(data, &data->hud.rec[1]);
	if (!data->hud.rec[1].img.img_ptr)
		return (printf(RED "ERROR2" NC), 1);
	return (0);
}

int	init_hud(t_data *data)
{
	if (init_batterie(data))
		return (1);
	if (init_rec(data))
		return (1);
	if (init_border(data))
		return (1);
	data->hud.rec_tempo = 0;
	data->hud.rec_position = 0;
	data->hud.time_start = get_time();
	data->hud.bat_tempo = get_time();
	data->hud.bat_pos = 5;
	data->hud.save_bat_pos = 5;
	return (0);
}
