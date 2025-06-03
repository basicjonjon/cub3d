/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:12:58 by jle-doua          #+#    #+#             */
/*   Updated: 2025/06/03 17:58:12 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
				data->player.x = x;
				data->player.posX = x * BLOCK + BLOCK / 2;
				data->player.y = y;
				data->player.posY = y * BLOCK + BLOCK / 2;
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

	player = data->param.map[data->player.y][data->player.x];
	if (player == 'N')
		data->player.angle = 0;
	else if (player == 'W')
		data->player.angle = 90;
	else if (player == 'S')
		data->player.angle = 180;
	else
		data->player.angle = 270;
}

void	init_bool(t_data *data)
{
	data->player.keyUp = false;
	data->player.keyDown = false;
	data->player.keyLeft = false;
	data->player.keyRight = false;
	data->player.rotLeft = false;
	data->player.rotRight = false;
}

int	init_player(t_data *data)
{
	get_player_pos(data);
	get_player_direction(data);
	return (0);
}