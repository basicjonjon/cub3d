/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:05:07 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/29 13:28:04 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_y(int y, float wall_height, t_texture *t)
{
	int	d;

	d = y * 256 - SCREENHEIGHT * 128 + wall_height * 128;
	return (((d * t->tex_h) / (int)wall_height) / 256);
}

static void	draw_column(t_data *data, t_texture *t, t_config *c,
						t_draw draw)
{
	int	screen_x;
	int	tex_y;
	int	color;
	int	y;
	int	x;

	x = 0;
	while (x < c->column_width)
	{
		screen_x = draw.i * c->column_width + x;
		if (screen_x >= 0 && screen_x < SCREENWIDTH)
		{
			y = draw.start;
			while (++y < draw.end)
			{
				tex_y = get_tex_y(y, draw.height, t);
				color = get_texture_pixel(t, data->hit.tex_x, tex_y);
				ft_pixel_put(screen_x, y, &data->img, color);
			}
		}
		x++;
	}
}

void	draw_wall(t_data *data, t_config *c, int i, float wall_height)
{
	t_texture	*t;
	t_draw		draw;

	t = find_texture(data);
	draw.i = i;
	draw.height = wall_height;
	draw.start = (SCREENHEIGHT / 2) - (wall_height / 2);
	draw.end = (SCREENHEIGHT / 2) + (wall_height / 2);
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= SCREENHEIGHT)
		draw.end = SCREENHEIGHT - 1;
	data->hit.tex_x = (int)(data->hit.wall_hit_x * t->tex_w);
	if (data->hit.tex_x < 0)
		data->hit.tex_x = 0;
	if (data->hit.tex_x >= t->tex_w)
		data->hit.tex_x = t->tex_w - 1;
	draw_column(data, t, c, draw);
}
