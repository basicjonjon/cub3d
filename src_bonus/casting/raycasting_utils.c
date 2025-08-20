/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:18:43 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/08/20 22:57:09 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	advance_map_x_y(t_ray *ray, int *side)
{
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
}

void	calc_hit(t_data *data, t_ray *ray, char **map, int *side)
{
	while (1)
	{
		if (ray->map_x < 0 || ray->map_x >= data->param.map_x || ray->map_y < 0
			|| ray->map_y >= data->param.map_y)
			break ;
		advance_map_x_y(ray, side);
		if (ray->map_y >= 0 && ray->map_y < data->param.map_y && ray->map_x >= 0
			&& ray->map_x < data->param.map_x
			&& (map[ray->map_y][ray->map_x] == '1'
			|| map[ray->map_y][ray->map_x] == 'P'))
		{
			if (map[ray->map_y][ray->map_x] == 'P')
				data->hit.door_flg = true;
			else
				data->hit.door_flg = false;
			break ;
		}
	}
}

static void	calc_ray_dir(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
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
		wall_hit_x = ray->pos_y + dist * ray->raydir_y;
	else
		wall_hit_x = ray->pos_x + dist * ray->raydir_x;
	wall_hit_x -= floor(wall_hit_x);
	return (wall_hit_x);
}

t_ray	init_ray_dir(t_player *player, float raydir_x, float raydir_y)
{
	t_ray	ray;

	ray.pos_x = player->x;
	ray.pos_y = player->y;
	ray.map_x = (int)player->x;
	ray.map_y = (int)player->y;
	ray.raydir_x = raydir_x;
	ray.raydir_y = raydir_y;
	if (fabs(ray.raydir_x) < 1e-12)
		ray.deltadist_x = 1e30;
	else
		ray.deltadist_x = fabs(1.0 / ray.raydir_x);
	if (fabs(ray.raydir_y) < 1e-12)
		ray.deltadist_y = 1e30;
	else
		ray.deltadist_y = fabs(1.0 / ray.raydir_y);
	ray.step_x = 0;
	ray.step_y = 0;
	ray.sidedist_x = 0;
	ray.sidedist_y = 0;
	calc_ray_dir(&ray);
	return (ray);
}
