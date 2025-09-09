/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:21:12 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/09/09 17:47:07 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_dir	find_dir(t_ray *ray, int side)
{
	if (side == 0)
	{
		if (ray->raydir_x > 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (ray->raydir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

float	calc_rayt_dir(t_data *data, float raydir_x, float raydir_y)
{
	t_ray	ray;
	int		side;
	float	dist_uncorrected;
	float	cos_c;

	ray = init_ray_dir(&data->player, raydir_x, raydir_y);
	side = 0;
	calc_hit(data, &ray, data->param.map, &side);
	if (side == 0)
		dist_uncorrected = ray.sidedist_x - ray.deltadist_x;
	else
		dist_uncorrected = ray.sidedist_y - ray.deltadist_y;
	data->hit.wall_dir = find_dir(&ray, side);
	data->hit.wall_hit_x = calc_wall_hit_x(&ray, side, dist_uncorrected);
	cos_c = ray.raydir_x * data->player.dir_x + ray.raydir_y
		* data->player.dir_y;
	return (dist_uncorrected * cos_c);
}

void	rays_process(t_data *data, t_player *player, t_config *c)
{
	int		i;
	int		col_cx;
	float	raydir_x;
	float	raydir_y;
	float	dist;

	i = 0;
	while (i < c->nbr_rays)
	{
		col_cx = i * c->column_width + (c->column_width / 2);
		raydir_x = player->dir_x + player->plane_x
			* (2.0f * (float)col_cx / (float)SCREENWIDTH - 1.0f);
		raydir_y = player->dir_y + player->plane_y
			* (2.0f * (float)col_cx / (float)SCREENWIDTH - 1.0f);
		dist = calc_rayt_dir(data, raydir_x, raydir_y);
		if (dist < 0.001f)
			dist = 0.001f;
		draw_wall(data, c, i, SCREENHEIGHT / dist);
		i++;
	}
}

void	interact_door(t_player *p, t_map *m)
{
	int	px;
	int	py;

	if (p->interact == false)
		return ;
	if (get_time() - p->tt_interact < 500)
		return ;
	px = (int)(p->x + p->dir_x);
	py = (int)(p->y + p->dir_y);
	if (m->map[py][px] && m->map[py][px] == 'P')
		m->map[py][px] = 'O';
	else if (m->map[py][px] && m->map[py][px] == 'O')
		m->map[py][px] = 'P';
	p->tt_interact = get_time();
}

int	raycasting(t_data *data)
{
	if (data->player.map == true)
	{
		clear_image(&data->img, SCREENWIDTH, SCREENHEIGHT);
		move_player(data, &data->player, &data->conf);
		draw_floor_ceiling(data);
		interact_door(&data->player, &data->param);
		rays_process(data, &data->player, &data->conf);
		print_hud(data);
		draw_minimap(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
		return (0);
	}
	clear_image(&data->img, SCREENWIDTH, SCREENHEIGHT);
	move_player(data, &data->player, &data->conf);
	draw_floor_ceiling(data);
	interact_door(&data->player, &data->param);
	rays_process(data, &data->player, &data->conf);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
