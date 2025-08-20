/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:29:01 by mmarps            #+#    #+#             */
/*   Updated: 2025/08/20 20:46:40 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_block_color(const char c)
{
	if (c == '1')
		return (0xAAAAAA);
	else if (c == 'P')
		return (0x00AAFF);
	else if (c == 'O')
		return (HGREEN);
	else
		return (-1);
}

static void	draw_minimap_map(t_data *data, t_point off, int scale)
{
	int		x;
	int		y;
	int		color;
	t_point	pos;

	y = 0;
	while (y < data->param.mapY)
	{
		x = 0;
		while (x < data->param.mapX)
		{
			color = get_block_color(data->param.map[y][x]);
			pos.x = off.x + x * scale;
			pos.y = off.y + y * scale;
			draw_square(&data->img, &pos, scale, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int		scale;
	t_point	off;
	t_point	p;
	t_point	d;

	scale = get_minimap_scale(data);
	off.x = (screenWidth - data->param.mapX * scale) / 2;
	off.y = 0;
	draw_minimap_map(data, off, scale);
	p.x = off.x + (int)(data->player.x * scale);
	p.y = off.y + (int)(data->player.y * scale);
	draw_square(&data->img, &p, 4, 0xFF0000);
	d.x = (int)(p.x + data->player.dirX * 10);
	d.y = (int)(p.y + data->player.dirY * 10);
	draw_line(&data->img, &p, &d, 0xFF0000);
}
