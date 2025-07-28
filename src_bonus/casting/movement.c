/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:50 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/28 17:50:04 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_player_vectors(t_player *p, t_config *c)
{
	p->dirX = cosf(p->angle);
	p->dirY = sinf(p->angle);
	p->planeX = -p->dirY * tanf(c->fov / 2.0f);
	p->planeY =  p->dirX * tanf(c->fov / 2.0f);
}

void	move_forward_backward(t_data *d, t_player *p, float speed)
{
	float	new_x;
	float	new_y;

	if (p->keyUp == true)
	{
		new_x = p->x + p->dirX * speed;
		new_y = p->y + p->dirY * speed;
		if (check_colision(new_x, new_y, &d->param) == true)
		{
			p->x = new_x;
			p->y = new_y;
		}
	}
	if (p->keyDown == true)
	{
		new_x = p->x - p->dirX * speed;
		new_y = p->y - p->dirY * speed;
		if (check_colision(new_x, new_y, &d->param) == true)
		{
			p->x = new_x;
			p->y = new_y;
		}
	}
}

void	move_strafe(t_data *d, t_player *p, float speed)
{
	float	strafe_x;
	float	strafe_y;

	if (p->keyLeft == true)
	{
		strafe_x = p->dirY * speed;
		strafe_y = -p->dirX * speed;
		if (check_colision(p->x + strafe_x, p->y + strafe_y, &d->param) == true)
		{
			p->x += strafe_x;
			p->y += strafe_y;
		}
	}
	if (p->keyRight == true)
	{
		strafe_x = -p->dirY * speed;
		strafe_y = p->dirX * speed;
		if (check_colision(p->x + strafe_x, p->y + strafe_y, &d->param) == true)
		{
			p->x += strafe_x;
			p->y += strafe_y;
		}
	}
}

void	rotate_player(t_player *p, t_config *c)
{
	if (p->rotLeft == true)
		p->angle -= c->rot_speed;
	if (p->rotRight == true)
		p->angle += c->rot_speed;
	if (p->angle < 0.0f)
		p->angle += 2.0f * M_PI;
	else if (p->angle >= 2.0f * M_PI)
		p->angle -= 2.0f * M_PI;
}

void	rotate_with_mouse(t_data *d, t_player *p)
{
	int	mouse_x;
	int	mouse_y;
	int	delta_x;
	float	sensitivity;

	mouse_x = 0;
	mouse_y = 0;
	sensitivity = d->conf.sensitivity;

	mlx_mouse_get_pos(d->mlx, d->win, &mouse_x, &mouse_y);
	delta_x = mouse_x - (screenWidth / 2);
	if (delta_x != 0)
	{
		p->angle += delta_x * sensitivity;
		mlx_mouse_move(d->mlx, d->win, screenWidth / 2, screenHeight / 2);
	}
}

int	move_player(t_data *d, t_player *p, t_config *c)
{
	float	speed;

	if (p->run == true)
		speed = c->run_speed;
	else
		speed = c->move_speed;

	move_forward_backward(d, p, speed);
	move_strafe(d, p, speed);
	rotate_player(p, c);
	rotate_with_mouse(d, p);
	update_player_vectors(p, c);
	return (0);
}

// int	move_player(t_data *data, t_player *player, t_config *c)
// {
// 	float	dx;
// 	float	dy;
// 	float	strafeX;
// 	float	strafeY;

// 	if (player->run)
// 		c->move_speed = c->run_speed;
// 	else
// 		c->move_speed = 0.008;
// 	dx = cos(player->angle) * c->move_speed;
// 	dy = sin(player->angle) * c->move_speed;
// 	if (player->keyUp == true)
// 	{
// 		if (check_colision(player->x + dx, player->y + dy, &data->param))
// 		{
// 			player->x += dx;
// 			player->y += dy;
// 		}
// 	}
// 	if (player->keyDown == true)
// 	{
// 		if (check_colision(player->x - dx, player->y - dy, &data->param))
// 		{
// 			player->x -= dx;
// 			player->y -= dy;
// 		}
// 	}
// 	if (player->keyLeft == true)
// 	{
// 		strafeX = cos(player->angle - M_PI_2) * c->move_speed;
// 		strafeY = sin(player->angle - M_PI_2) * c->move_speed;
// 		if (check_colision(player->x + strafeX, player->y + strafeY,
// 				&data->param))
// 		{
// 			player->x += strafeX;
// 			player->y += strafeY;
// 		}
// 	}
// 	if (player->keyRight == true)
// 	{
// 		strafeX = cos(player->angle + M_PI_2) * c->move_speed;
// 		strafeY = sin(player->angle + M_PI_2) * c->move_speed;
// 		if (check_colision(player->x + strafeX, player->y + strafeY,
// 				&data->param))
// 		{
// 			player->x += strafeX;
// 			player->y += strafeY;
// 		}
// 	}
// 	if (player->rotLeft == true)
// 		player->angle -= c->rot_speed;
// 	if (player->rotRight == true)
// 		player->angle += c->rot_speed;
// 	if (player->angle < 0)
// 		player->angle += 2 * M_PI;
// 	else if (player->angle >= 2 * M_PI)
// 		player->angle -= 2 * M_PI;
// 	return (0);
// }

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
