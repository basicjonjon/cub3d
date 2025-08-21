/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:50 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/08/20 22:42:28 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_player_vectors(t_player *p, t_config *c)
{
	p->dir_x = cosf(p->angle);
	p->dir_y = sinf(p->angle);
	p->plane_x = -p->dir_y * tanf(c->fov / 2.0f);
	p->plane_y = p->dir_x * tanf(c->fov / 2.0f);
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
