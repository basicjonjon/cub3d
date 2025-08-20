/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:12:58 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/20 22:44:18 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_player_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->param.map[y])
	{
		x = 0;
		while (data->param.map[y][x])
		{
			if (data->param.map[y][x] == 'N' || data->param.map[y][x] == 'S'
				|| data->param.map[y][x] == 'W' || data->param.map[y][x] == 'E')
			{
				data->player.x = x + 0.5;
				data->player.y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_player_direction(t_data *data)
{
	char	player;

	player = data->param.map[(int)data->player.y][(int)data->player.x];
	if (player == 'N')
		data->player.angle = -(M_PI / 2);
	else if (player == 'W')
		data->player.angle = 0;
	else if (player == 'S')
		data->player.angle = M_PI / 2;
	else
		data->player.angle = M_PI;
	data->player.dir_x = cos(data->player.angle);
	data->player.dir_y = sin(data->player.angle);
	data->player.plane_x = -data->player.dir_y * data->conf.fov;
	data->player.plane_y = data->player.dir_x * data->conf.fov;
}

void	init_bool(t_data *data)
{
	data->player.key_up = false;
	data->player.key_down = false;
	data->player.key_left = false;
	data->player.key_right = false;
	data->player.rot_left = false;
	data->player.rot_right = false;
	data->player.map = false;
	data->player.run = false;
	data->player.interact = false;
	data->player.tt_interact = get_time();
}

int	init_player(t_data *data)
{
	get_player_pos(data);
	get_player_direction(data);
	return (0);
}
