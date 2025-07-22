/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:21:12 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/22 16:04:13 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	float	dist_uncorrected;

	ray = init_ray_struct(&data->player, ray_angle);
	side = 0;
	calc_hit(data, &ray, data->param.map, &side);
	if (side == 0)
		dist_uncorrected = ray.sideDistX - ray.deltaDistX;
	else
		dist_uncorrected = ray.sideDistY - ray.deltaDistY;
	data->hit.wall_dir = find_dir(&ray, side);
	data->hit.wall_hit_x = calc_wall_hit_x(&ray, side, dist_uncorrected);
	if (hit_x && hit_y)
	{
		*hit_x = (int)((ray.posX + ray.rayDirX * dist_uncorrected)
				* data->conf.block);
		*hit_y = (int)((ray.posY + ray.rayDirY * dist_uncorrected)
				* data->conf.block);
	}
	dist = dist_uncorrected * cos(ray_angle - data->player.angle);
	// dist = dist_uncorrected;
	return (dist);
}

t_texture	*find_texture(t_data *data)
{
	if (data->hit.wall_dir == NORTH)
		return (&data->asset.north);
	if (data->hit.wall_dir == SOUTH)
		return (&data->asset.south);
	if (data->hit.wall_dir == EAST)
		return (&data->asset.east);
	if (data->hit.wall_dir == WEST)
		return (&data->asset.west);
	return (NULL);
}

void	draw_wall(t_data *data, t_config *c, int i, float wall_height)
{
	int			x;
	int			y;
	int			screen_x;
	int			start;
	int			end;
	int			color;
	t_texture	*texture;
	int			d;

	texture = find_texture(data);
	start = (screenHeight / 2) - (wall_height / 2);
	if (start < 0)
		start = 0;
	end = (screenHeight / 2) + (wall_height / 2);
	if (end >= screenHeight)
		end = screenHeight - 1;
	data->hit.tex_x = (int)(data->hit.wall_hit_x * texture->tex_w);
	if (data->hit.tex_x < 0)
		data->hit.tex_x = 0;
	if (data->hit.tex_x >= texture->tex_w)
		data->hit.tex_x = texture->tex_w - 1;
	x = 0;
	while (x < c->column_width)
	{
		screen_x = i * c->column_width + x;
		if (screen_x >= 0 && screen_x < screenWidth)
		{
			y = start;
			while (y++ < end)
			{
				d = y * 256 - screenHeight * 128 + wall_height * 128;
				data->hit.tex_y = ((d * texture->tex_h) / (int)wall_height)
					/ 256;
				color = get_texture_pixel(texture, data->hit.tex_x,
						data->hit.tex_y);
				ft_pixel_put(screen_x, y, &data->img, color);
			}
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
		if (!player->map)
		{
			wall_height = screenHeight / dist;
			draw_wall(data, c, i, wall_height);
		}
		else
			put_line(data, c, player, hit_x, hit_y);
		i++;
	}
}

void	cast_floor(t_img *img, int color)
{
	int	x;
	int	y;

	y = screenHeight / 2;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			ft_pixel_put(x, y, img, color);
			x++;
		}
		y++;
	}
}

void	cast_ceiling(t_img *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < screenWidth)
	{
		y = 0;
		while (y < screenHeight / 2)
		{
			ft_pixel_put(x, y, img, color);
			y++;
		}
		x++;
	}
}

int	raycasting(t_data *data)
{
	if (data->player.map == true)
	{
		clear_image(&data->img, screenWidth, screenHeight);
		move_player(data, &data->player, &data->conf);
		draw_map(data, &data->conf);
		draw_player(data, &data->player, &data->conf);
		rays_process(data, &data->player, &data->conf);
		put_hud_test(data, 10, 10, 200);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
		return (0);
	}
	clear_image(&data->img, screenWidth, screenHeight);
	move_player(data, &data->player, &data->conf);
	// cast_ceiling(&data->img, data->texture.ceiling);
	// cast_floor(&data->img, data->texture.floor);
	rays_process(data, &data->player, &data->conf);
	put_hud_test(data, 10, 10, 200);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
