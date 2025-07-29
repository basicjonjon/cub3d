/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:18:43 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/29 13:35:50 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_hit(t_data *data, t_ray *ray, char **map, int *side)
{
	while (1)
	{
		if (ray->map_x < 0 || ray->map_x >= data->param.map_x
			|| ray->map_y < 0 || ray->map_y >= data->param.map_y)
			break ;
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			*side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			*side = 1;
		}
		if (ray->map_y >= 0 && ray->map_y < data->param.map_y
			&& ray->map_x >= 0 && ray->map_x < data->param.map_x
			&& map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

static void	calc_ray_dir(t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	}
	if (ray->raydiry < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ray->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->deltadist_y;
	}
}

float	calc_wall_hit_x(t_ray *ray, int side, float dist)
{
	float	wall_hit_x;

	if (side == 0)
		wall_hit_x = ray->pos_y + dist * ray->raydiry;
	else
		wall_hit_x = ray->pos_x + dist * ray->raydirx;
	wall_hit_x -= floor(wall_hit_x);
	return (wall_hit_x);
}

t_ray	init_ray_struct(t_player *player, float ray_angle)
{
	t_ray	ray;

	ray.pos_x = player->x;
	ray.pos_y = player->y;
	ray.map_x = (int)player->x;
	ray.map_y = (int)player->y;
	ray.raydirx = cos(ray_angle);
	ray.raydiry = sin(ray_angle);
	ray.deltadist_x = fabs(1.0 / ray.raydirx);
	ray.deltadist_y = fabs(1.0 / ray.raydiry);
	ray.step_x = 0;
	ray.step_y = 0;
	ray.sidedist_x = 0;
	ray.sidedist_y = 0;
	calc_ray_dir(&ray);
	return (ray);
}
