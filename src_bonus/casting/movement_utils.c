/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:18:40 by mmarps            #+#    #+#             */
/*   Updated: 2025/08/20 19:19:32 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_forward_backward(t_data *d, t_player *p, float speed)
{
	float	new_x;
	float	new_y;

	if (p->keyUp)
	{
		new_x = p->x + p->dirX * speed;
		new_y = p->y + p->dirY * speed;
		if (check_colision(new_x, new_y, &d->param))
		{
			p->x = new_x;
			p->y = new_y;
		}
	}
	if (p->keyDown)
	{
		new_x = p->x - p->dirX * speed;
		new_y = p->y - p->dirY * speed;
		if (check_colision(new_x, new_y, &d->param))
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

	if (p->keyLeft)
	{
		strafe_x = p->dirY * speed;
		strafe_y = -p->dirX * speed;
		if (check_colision(p->x + strafe_x, p->y + strafe_y, &d->param))
		{
			p->x += strafe_x;
			p->y += strafe_y;
		}
	}
	if (p->keyRight)
	{
		strafe_x = -p->dirY * speed;
		strafe_y = p->dirX * speed;
		if (check_colision(p->x + strafe_x, p->y + strafe_y, &d->param))
		{
			p->x += strafe_x;
			p->y += strafe_y;
		}
	}
}

void	rotate_player(t_player *p, t_config *c)
{
	if (p->rotLeft)
		p->angle -= c->rot_speed;
	if (p->rotRight)
		p->angle += c->rot_speed;
	if (p->angle < 0.0f)
		p->angle += 2.0f * M_PI;
	else if (p->angle >= 2.0f * M_PI)
		p->angle -= 2.0f * M_PI;
}

void	rotate_with_mouse(t_data *d, t_player *p)
{
	int		mouse_x;
	int		mouse_y;
	int		delta_x;
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
