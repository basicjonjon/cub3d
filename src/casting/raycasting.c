/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:21:12 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/06/19 23:44:20 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

s_dir	find_dir(t_ray *ray, int side)
{
	if (side == 0)
	{
		if (ray->rayDirX > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->rayDirY > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

float	calc_rays(t_data *data, float ray_angle, int *hit_x, int *hit_y)
{
	t_ray	ray;
	int		side;
	float	dist;

	ray = init_ray_struct(&data->player, ray_angle);

	side = 0;
	calc_hit(data, &ray, data->param.map, &side);

	dist = 0;
	if (hit_x && hit_y)
	{
		if (side == 0)
			dist = ray.sideDistX - ray.deltaDistX;
		else
			dist = ray.sideDistY - ray.deltaDistY;

		dist *= cos(ray_angle - data->player.angle);

		*hit_x = (int)((ray.posX + ray.rayDirX * dist) * BLOCK);
		*hit_y = (int)((ray.posY + ray.rayDirY * dist) * BLOCK);
	}
	data->dir = find_dir(&ray, side);
	return (dist);
}

int		find_color(t_data *data)
{
	if (data->dir == NORTH)
		return (HYELLOW);
	if (data->dir == SOUTH)
		return (HGREEN);
	if (data->dir == EAST)
		return (HBLUE);
	if (data->dir == WEST)
		return (HRED);
	return (0);
}

void	draw_wall(t_data *data, t_config *c, int i, float wall_height)
{
	int		x;
	int		y;
	int		screen_x;
	int		start;
	int		end;
	int		color;

	color = find_color(data);
	start = (screenHeight / 2) - (wall_height / 2);
	end = (screenHeight / 2) + (wall_height / 2);
	x = 0;
	while (x < c->column_width)
	{
		screen_x = i * c->column_width + x;
		if (screen_x >= 0 && screen_x < screenWidth)
		{
			y = start;
			while (y++ < end)
				ft_pixel_put(screen_x, y, &data->img, color);
		}
		x++;
	}
}

void	rays_process(t_data *data, t_player *player, t_config *c)
{
	int		i;
	float	ray_angle;
	int		hit_x;
	int		hit_y;
	float	dist;
	float	wall_height;

	i = 0;
	while (i < c->nbr_rays)
	{
		ray_angle = player->angle - (c->fov / 2) + i * (c->fov / c->nbr_rays);
		dist = calc_rays(data, ray_angle, &hit_x, &hit_y);
		if (dist < 0.001)
			dist = 0.001;
		wall_height = screenHeight / dist;
		if (wall_height > screenHeight)
			wall_height = screenHeight;
		draw_wall(data, c, i, wall_height);
		i++;
	}
}

int	raycasting(t_data *data)
{
	clear_image(&data->img, screenWidth, screenHeight);
	move_player(data, &data->player, &data->conf);
	rays_process(data, &data->player, &data->conf);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
