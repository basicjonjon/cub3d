/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:50 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/08/20 22:30:07 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_player_vectors(t_player *p, t_config *c)
{
	p->dirX = cosf(p->angle);
	p->dirY = sinf(p->angle);
	p->planeX = -p->dirY * tanf(c->fov / 2.0f);
	p->planeY = p->dirX * tanf(c->fov / 2.0f);
}

int	move_player(t_data *d, t_player *p, t_config *c)
{
	float	speed;

	if (p->run)
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
