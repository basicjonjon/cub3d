/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:50 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/06/03 18:39:23 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	move_player(t_data *data)
{
	double	speed;
	double	x;
	double	y;

	double	angle_speed;
	double	cos_angle;
	double	sin_angle;

	x = data->player.posX;
	y = data->player.posY;
	speed = 0.05;
	angle_speed = 0.1;
	cos_angle = cos(data->player.angle);
	sin_angle = sin(data->player.angle);
	if (data->player.keyUp == true
		&& check_colision(x, y - speed, data->param.map))
	{
		data->player.posY -= speed;
	}
	if (data->player.keyDown == true
		&& check_colision(x, y + speed, data->param.map))
	{
		data->player.posY += speed;
	}
	if (data->player.keyLeft == true
		&& check_colision(x - speed, y, data->param.map))
	{
		data->player.posX -= speed;
	}
	if (data->player.keyRight == true
		&& check_colision(x + speed, y, data->param.map))
	{
		data->player.posX += speed;
	}
	return (0);
}

int	move_loop(t_data *data)
{
	if (verif_move(&data->player) == 1)
	{
		draw_player(data->player.posX, data->player.posY, playerSize, HBLACK, data);
		move_player(data);
		draw_map(data);
		draw_player(data->player.posX, data->player.posY, playerSize, HRED, data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	}
	return (0);
}
