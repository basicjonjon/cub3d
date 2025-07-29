/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:50 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/29 13:40:00 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_vectors(t_player *p, t_config *c)
{
	p->dirx = cosf(p->angle);
	p->diry = sinf(p->angle);
	p->plane_x = -p->diry * tanf(c->fov / 2.0f);
	p->plane_y = p->dirx * tanf(c->fov / 2.0f);
}

void	move_forward_backward(t_player *p, float speed)
{
	float	new_x;
	float	new_y;

	if (p->keyup == true)
	{
		new_x = p->x + p->dirx * speed;
		new_y = p->y + p->diry * speed;
		p->x = new_x;
		p->y = new_y;
	}
	if (p->keydown == true)
	{
		new_x = p->x - p->dirx * speed;
		new_y = p->y - p->diry * speed;
		p->x = new_x;
		p->y = new_y;
	}
}

void	move_strafe(t_player *p, float speed)
{
	float	strafe_x;
	float	strafe_y;

	if (p->keyleft == true)
	{
		strafe_x = p->diry * speed;
		strafe_y = -p->dirx * speed;
		p->x += strafe_x;
		p->y += strafe_y;
	}
	if (p->keyright == true)
	{
		strafe_x = -p->diry * speed;
		strafe_y = p->dirx * speed;
		p->x += strafe_x;
		p->y += strafe_y;
	}
}

void	rotate_player(t_player *p, t_config *c)
{
	if (p->rotleft == true)
		p->angle -= c->rot_speed;
	if (p->rotright == true)
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
