/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:37:06 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/06/05 18:25:11 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	cast_rays(t_player *player, char **map, float ray_angle)
// {
// 	int		x;
// 	int		y;

// 	float	rayDirX;
// 	float	rayDirY;

// 	float	deltaDistX;
// 	float	deltaDistY;

// 	int		stepX;
//     int		stepY;
//     float	sideDistX;
//     float	sideDistY;

// 	x = player->posX / BLOCK;
// 	y = player->posY / BLOCK;

// 	rayDirX = cos(ray_angle);
// 	rayDirY = sin(ray_angle);

// 	deltaDistX = fabs(1.0 / rayDirX);
// 	deltaDistY = fabs(1.0 / rayDirY);

// 	if (rayDirX < 0)
// 	{
// 		stepX = -1;
// 		sideDistX = (x - mapX) * deltaDistX;
// 	}
// 	else
// 	{
// 		stepX = 1;
// 		sideDistX = (mapX + 1.0 - x) * deltaDistX;
// 	}

// 	if (rayDirY < 0)
// 	{
// 		stepY = -1;
// 		sideDistY = (y - mapY) * deltaDistY;
// 	}
// 	else
// 	{
// 		stepY = 1;
// 		sideDistY = (mapY + 1.0 - y) * deltaDistY;
// 	}
// }

// void	draw_rays(t_data *data, t_player *player, t_config *c)
// {
// 	int		i;
// 	float	ray_angle;

// 	i = 0;
// 	ray_angle = 0;
// 	while (i < NBR_RAYS)
// 	{
// 		ray_angle = player->angle - (c->fov / 2) + i * (c->fov / NBR_RAYS);
// 		cast_rays(player, data->param.map, ray_angle);
// 		i++;
// 	}
// }

int	debug(t_data *data)
{
	if (verif_move(&data->player) == 1)
	{
		draw_player(data->player.posX, data->player.posY, playerSize, HBLACK, data);
		move_player(data, &data->player, &data->conf);
		draw_map(data);
		draw_player(data->player.posX, data->player.posY, playerSize, HRED, data);
		// draw_rays(data, &data->player, &data->conf);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	}
	return (0);
}
