/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:18:43 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/22 14:35:58 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calc_hit(t_data *data, t_ray *ray, char **map, int *side)
{
	while (1)
	{
		if (ray->mapX < 0 || ray->mapX >= data->param.mapX || ray->mapY < 0
			|| ray->mapY >= data->param.mapY)
			break ;
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			*side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			*side = 1;
		}
		if (ray->mapY >= 0 && ray->mapY < data->param.mapY && ray->mapX >= 0
			&& ray->mapX < data->param.mapX && map[ray->mapY][ray->mapX] == '1')
			break ;
	}
}

static void	calc_ray_dir(t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
	}
}

float	calc_wall_hit_x(t_ray *ray, int side, float dist)
{
	float	wall_hit_x;

	if (side == 0)
		wall_hit_x = ray->posY + dist * ray->rayDirY;
	else
		wall_hit_x = ray->posX + dist * ray->rayDirX;
	wall_hit_x -= floor(wall_hit_x);
	return (wall_hit_x);
}

t_ray	init_ray_struct(t_player *player, float ray_angle)
{
	t_ray	ray;

	ray.posX = player->x;
	ray.posY = player->y;
	ray.mapX = (int)player->x;
	ray.mapY = (int)player->y;
	ray.rayDirX = cos(ray_angle);
	ray.rayDirY = sin(ray_angle);
	ray.deltaDistX = fabs(1.0 / ray.rayDirX);
	ray.deltaDistY = fabs(1.0 / ray.rayDirY);
	ray.stepX = 0;
	ray.stepY = 0;
	ray.sideDistX = 0;
	ray.sideDistY = 0;
	calc_ray_dir(&ray);
	return (ray);
}
