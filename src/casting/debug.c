/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:37:06 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/06/16 17:01:38 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cast_rays(t_data *data, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);

	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;

	int err = dx - dy;

	while (1)
	{
		ft_pixel_put(x0, y0, &data->img, color);
		if (x0 == x1 && y0 == y1)
			break;

		int e2 = 2 * err;

		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}

		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

float	calc_rays(t_data *data, char **map, float ray_angle, int *hit_x, int *hit_y)
{
	float	x;
	float	y;

	int		mapX;
	int		mapY;

	float	rayDirX;
	float	rayDirY;

	float	deltaDistX;
	float	deltaDistY;

	int		stepX;
    int		stepY;
    float	sideDistX;
    float	sideDistY;

	x = data->player.x;
	y = data->player.y;

	mapX = (int)x;
	mapY = (int)y;

	rayDirX = cos(ray_angle);
	rayDirY = sin(ray_angle);

	deltaDistX = fabs(1.0 / rayDirX);
	deltaDistY = fabs(1.0 / rayDirY);

	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (x - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - x) * deltaDistX;
	}

	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (y - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - y) * deltaDistY;
	}

	int		hit = 0;
	int		side = 0;

	while (!hit)
	{
		if (mapX < 0 || mapX >= data->param.mapX || mapY < 0 || mapY >= data->param.mapY)
			break;
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		if (mapY >= 0 && mapY < data->param.mapY
			&& mapX >= 0 && mapX < data->param.mapX
			&& map[mapY][mapX] == '1')
			hit = 1;
	}

	float dist = 0;

	if (hit_x && hit_y)
	{
		if (side == 0)
			dist = sideDistX - deltaDistX;
		else
			dist = sideDistY - deltaDistY;

		dist *= cos(ray_angle - data->player.angle);

		*hit_x = (int)((x + rayDirX * dist) * BLOCK);
		*hit_y = (int)((y + rayDirY * dist) * BLOCK);
	}
	return (dist);
}

// void	draw_rays(t_data *data, t_player *player, t_config *c)
// {
// 	int		i;
// 	float	ray_angle;
// 	int		hit_x;
// 	int		hit_y;
// 	float	dist;
// 	float	wall_height;
// 	int		start;
// 	int		end;

// 	hit_x = 0;
// 	hit_y = 0;
// 	i = 0;
// 	ray_angle = 0;
// 	while (i < NBR_RAYS)
// 	{
// 		ray_angle = player->angle - (c->fov / 2) + i * (c->fov / NBR_RAYS);
// 		dist = calc_rays(data, data->param.map, ray_angle, &hit_x, &hit_y);
// 		wall_height = (screenHeight) / dist;
// 		start = (screenHeight / 2) - (wall_height / 2);
// 		end = (screenHeight / 2) + (wall_height / 2);
// 		for (int y = start; y < end; y++)
// 			ft_pixel_put(i, y, &data->img, HGREEN);
// 		// cast_rays(data, player->x * BLOCK, player->y * BLOCK, hit_x, hit_y, HGREEN);
// 		i++;
// 	}
// }

void	draw_rays(t_data *data, t_player *player, t_config *c)
{
	int		i;
	float	ray_angle;
	int		hit_x;
	int		hit_y;
	float	dist;
	float	wall_height;
	int		start;
	int		end;
	int		column_width = screenWidth / NBR_RAYS + 1;

	for (i = 0; i < NBR_RAYS; i++)
	{
		ray_angle = player->angle - (c->fov / 2) + i * (c->fov / NBR_RAYS);
		dist = calc_rays(data, data->param.map, ray_angle, &hit_x, &hit_y);
		if (dist < 0.001)
			dist = 0.001;
		wall_height = screenHeight / dist;
		if (wall_height > screenHeight)
			wall_height = screenHeight;

		start = (screenHeight / 2) - (wall_height / 2);
		end = (screenHeight / 2) + (wall_height / 2);

		for (int x = 0; x < column_width; x++)
		{
			int screen_x = i * column_width + x;
			if (screen_x >= 0 && screen_x < screenWidth)
			{
				for (int y = start; y < end; y++)
					ft_pixel_put(screen_x, y, &data->img, HGREEN);
			}
		}
	}
}

int	debug(t_data *data)
{
	if (verif_move(&data->player) == 1)
	{
		// draw_player(data->player.posX, data->player.posY, playerSize, HBLACK, data);
		clear_image(&data->img, screenWidth, screenHeight);
		move_player(data, &data->player, &data->conf);
		// draw_map(data);
		// draw_player(data->player.x * BLOCK, data->player.y * BLOCK, playerSize, HRED, data);
		draw_rays(data, &data->player, &data->conf);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	}
	return (0);
}
