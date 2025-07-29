/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:21:12 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/29 13:35:50 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calc_rays(t_data *data, float ray_angle)
{
	t_ray	ray;
	int		side;
	float	dist;
	float	dist_uncorrected;

	ray = init_ray_struct(&data->player, ray_angle);
	side = 0;
	calc_hit(data, &ray, data->param.map, &side);
	if (side == 0)
		dist_uncorrected = ray.sidedist_x - ray.deltadist_x;
	else
		dist_uncorrected = ray.sidedist_y - ray.deltadist_y;
	data->hit.wall_dir = find_dir(&ray, side);
	data->hit.wall_hit_x = calc_wall_hit_x(&ray, side, dist_uncorrected);
	dist = dist_uncorrected * cos(ray_angle - data->player.angle);
	return (dist);
}

void	rays_process(t_data *data, t_player *player, t_config *c)
{
	int		i;
	float	ray_angle;
	float	dist;
	float	wall_height;

	i = 0;
	while (i < c->nbr_rays)
	{
		ray_angle = player->angle - (c->fov / 2) + i * (c->fov / c->nbr_rays);
		dist = calc_rays(data, ray_angle);
		if (dist < 0.001)
			dist = 0.001;
		wall_height = SCREENHEIGHT / dist;
		draw_wall(data, c, i, wall_height);
		i++;
	}
}

int	raycasting(t_data *data)
{
	clear_image(&data->img, SCREENWIDTH, SCREENHEIGHT);
	move_player(&data->player, &data->conf);
	cast_ceiling(&data->img, data->asset.ceiling);
	cast_floor(&data->img, data->asset.floor);
	rays_process(data, &data->player, &data->conf);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
