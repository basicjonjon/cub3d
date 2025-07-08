/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:50 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/06/30 20:16:47 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	move_player(t_data *data, t_player *player, t_config *c)
{
	// float x = player->posX;
	// float y = player->posY;

	if (player->run)
		c->move_speed = c->run_speed;
	else
		c->move_speed = 0.008;

	float dx = cos(player->angle) * c->move_speed;
	float dy = sin(player->angle) * c->move_speed;

	if (player->keyUp == true)
	{
		if (check_colision(player->x + dx, player->y + dy, &data->param))
		{
			player->x += dx;
			player->y += dy;
		}
	}
	if (player->keyDown == true)
	{
		if (check_colision(player->x - dx, player->y - dy, &data->param))
		{
			player->x -= dx;
			player->y -= dy;
		}
	}

	if (player->keyLeft == true)
	{
		float strafeX = cos(player->angle - M_PI_2) * c->move_speed;
		float strafeY = sin(player->angle - M_PI_2) * c->move_speed;
		if (check_colision(player->x + strafeX, player->y + strafeY, &data->param))
		{
			player->x += strafeX;
			player->y += strafeY;
		}
	}
	if (player->keyRight == true)
	{
		float strafeX = cos(player->angle + M_PI_2) * c->move_speed;
		float strafeY = sin(player->angle + M_PI_2) * c->move_speed;
		if (check_colision(player->x + strafeX, player->y + strafeY, &data->param))
		{
			player->x += strafeX;
			player->y += strafeY;
		}
	}

	if (player->rotLeft == true)
		player->angle -= c->rot_speed;
	if (player->rotRight == true)
		player->angle += c->rot_speed;

	if (player->angle < 0)
		player->angle += 2 * M_PI;
	else if (player->angle >= 2 * M_PI)
		player->angle -= 2 * M_PI;

	return (0);
}

// int	move_player(t_data *data, t_player *player, t_config *c)
// {
// 	float	x;
// 	float	y;

// 	float	cos_angle;
// 	float	sin_angle;

// 	x = player->posX;
// 	y = player->posY;
// 	cos_angle = cos(player->angle);
// 	sin_angle = sin(player->angle);
// 	if (player->keyUp == true
// 		&& check_colision(x, y - c->move_speed, data->param.map))
// 	{
// 		player->posY -= c->move_speed;
// 	}
// 	if (player->keyDown == true
// 		&& check_colision(x, y + c->move_speed, data->param.map))
// 	{
// 		player->posY += c->move_speed;
// 	}
// 	if (player->keyLeft == true
// 		&& check_colision(x - c->move_speed, y, data->param.map))
// 	{
// 		player->posX -= c->move_speed;
// 	}
// 	if (player->keyRight == true
// 		&& check_colision(x + c->move_speed, y, data->param.map))
// 	{
// 		player->posX += c->move_speed;
// 	}

// 	if (player->rotLeft == true)
// 	{
// 		player->angle -= c->rot_speed;
// 	}
// 	if (player->rotRight == true)
// 	{
// 		player->angle += c->rot_speed;
// 	}
// 	if (player->angle < 0)
// 		player->angle += 2 * M_PI;
// 	else if (player->angle >= 2 * M_PI)
// 		player->angle -= 2 * M_PI;

// 	return (0);
// }

// int	move_player(t_data *data)
// {
// 	float	speed;
// 	float	x;
// 	float	y;

// 	float	angle_speed;
// 	float	cos_angle;
// 	float	sin_angle;

// 	x = data->player.posX;
// 	y = data->player.posY;
// 	speed = 0.05;
// 	angle_speed = 0.1;
// 	cos_angle = cos(data->player.angle);
// 	sin_angle = sin(data->player.angle);
// 	if (data->player.keyUp == true
// 		&& check_colision(x, y - speed, data->param.map))
// 	{
// 		data->player.posY -= speed;
// 	}
// 	if (data->player.keyDown == true
// 		&& check_colision(x, y + speed, data->param.map))
// 	{
// 		data->player.posY += speed;
// 	}
// 	if (data->player.keyLeft == true
// 		&& check_colision(x - speed, y, data->param.map))
// 	{
// 		data->player.posX -= speed;
// 	}
// 	if (data->player.keyRight == true
// 		&& check_colision(x + speed, y, data->param.map))
// 	{
// 		data->player.posX += speed;
// 	}
// 	return (0);
// }
