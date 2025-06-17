/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:21:12 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/06/18 01:00:22 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	return (dist);
}

void	draw_wall(t_data *data, t_config *c, int i, float wall_height)
{
	int		x;
	int		y;
	int		screen_x;
	int		start;
	int		end;

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
				ft_pixel_put(screen_x, y, &data->img, HWHITE);
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
