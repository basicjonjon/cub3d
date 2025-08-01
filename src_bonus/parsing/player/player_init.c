/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:12:58 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/27 21:47:55 by mmarps           ###   ########.fr       */
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
	data->player.dirX = cos(data->player.angle);
	data->player.dirY = sin(data->player.angle);
	data->player.planeX = -data->player.dirY * data->conf.fov;
	data->player.planeY = data->player.dirX * data->conf.fov;
}

void	init_bool(t_data *data)
{
	data->player.keyUp = false;
	data->player.keyDown = false;
	data->player.keyLeft = false;
	data->player.keyRight = false;
	data->player.rotLeft = false;
	data->player.rotRight = false;
	data->player.map = false;
	data->player.run = false;
}

int	init_player(t_data *data)
{
	get_player_pos(data);
	get_player_direction(data);
	return (0);
}