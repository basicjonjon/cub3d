/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:22:43 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/08/21 00:18:55 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_floor_pixel(t_floor_data *fd, t_data *data,
	float *floor_x, float *floor_y)
{
	fd->cell_x = (int)(*floor_x);
	fd->cell_y = (int)(*floor_y);
	fd->tx = (int)(data->asset.tfloor.tex_w * (*floor_x - fd->cell_x));
	fd->ty = (int)(data->asset.tfloor.tex_h * (*floor_y - fd->cell_y));
	if (fd->tx < 0)
		fd->tx += data->asset.tfloor.tex_w;
	if (fd->ty < 0)
		fd->ty += data->asset.tfloor.tex_h;
	fd->tx %= data->asset.tfloor.tex_w;
	fd->ty %= data->asset.tfloor.tex_h;
}

static void	draw_floor_ceiling_pixel(t_data *data, int x, int y,
	t_fpoint *floor)
{
	t_floor_data	fd;

	init_floor_pixel(&fd, data, &floor->x, &floor->y);
	fd.floor_color = get_texture_pixel(&data->asset.tfloor, fd.tx, fd.ty);
	fd.ceil_color = get_texture_pixel(&data->asset.tceiling, fd.tx, fd.ty);
	ft_pixel_put(x, y, &data->img, fd.floor_color);
	ft_pixel_put(x, SCREENHEIGHT - y - 1, &data->img, fd.ceil_color);
}

static void	draw_floor_ceiling_line(t_data *data, int y, t_raydir dir)
{
	int				x;
	int				p;
	float			pos_z;
	float			row_dist;
	t_floor_data	fd;

	p = y - SCREENHEIGHT / 2;
	pos_z = 0.5f * SCREENHEIGHT - 10.0f;
	row_dist = pos_z / (float)p;
	fd.floor_step_x = row_dist * (dir.x1 - dir.x0) / (float)SCREENWIDTH;
	fd.floor_step_y = row_dist * (dir.y1 - dir.y0) / (float)SCREENWIDTH;
	fd.floor.x = data->player.x + row_dist * dir.x0;
	fd.floor.y = data->player.y + row_dist * dir.y0;
	x = 0;
	while (x < SCREENWIDTH)
	{
		draw_floor_ceiling_pixel(data, x, y, &fd.floor);
		fd.floor.x += fd.floor_step_x;
		fd.floor.y += fd.floor_step_y;
		x++;
	}
}

void	draw_floor_ceiling(t_data *data)
{
	int			y;
	t_raydir	dir;

	y = SCREENHEIGHT / 2 + 1;
	dir.x0 = data->player.dir_x - data->player.plane_x;
	dir.y0 = data->player.dir_y - data->player.plane_y;
	dir.x1 = data->player.dir_x + data->player.plane_x;
	dir.y1 = data->player.dir_y + data->player.plane_y;
	while (y < SCREENHEIGHT)
	{
		draw_floor_ceiling_line(data, y, dir);
		y++;
	}
}
