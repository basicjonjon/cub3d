/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:50 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/29 12:12:49 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_vectors(t_player *p, t_config *c)
{
	p->dirX = cosf(p->angle);
	p->dirY = sinf(p->angle);
	p->planeX = -p->dirY * tanf(c->fov / 2.0f);
	p->planeY = p->dirX * tanf(c->fov / 2.0f);
}

void	move_forward_backward(t_player *p, float speed)
{
	float	new_x;
	float	new_y;

	if (p->keyUp == true)
	{
		new_x = p->x + p->dirX * speed;
		new_y = p->y + p->dirY * speed;
		p->x = new_x;
		p->y = new_y;
	}
	if (p->keyDown == true)
	{
		new_x = p->x - p->dirX * speed;
		new_y = p->y - p->dirY * speed;
		p->x = new_x;
		p->y = new_y;
	}
}

void	move_strafe(t_player *p, float speed)
{
	float	strafe_x;
	float	strafe_y;

	if (p->keyLeft == true)
	{
		strafe_x = p->dirY * speed;
		strafe_y = -p->dirX * speed;
		p->x += strafe_x;
		p->y += strafe_y;
	}
	if (p->keyRight == true)
	{
		strafe_x = -p->dirY * speed;
		strafe_y = p->dirX * speed;
		p->x += strafe_x;
		p->y += strafe_y;
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

int	move_player(t_player *p, t_config *c)
{
	float	speed;

	if (p->run == true)
		speed = c->run_speed;
	else
		speed = c->move_speed;
	move_forward_backward(p, speed);
	move_strafe(p, speed);
	rotate_player(p, c);
	update_player_vectors(p, c);
	return (0);
}
