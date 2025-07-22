/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:06:53 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/22 14:36:06 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	clear_image(t_img *img, int width, int height)
{
	char	*dst;

	int x, y;
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			dst = img->addr + y * img->line_lenght + x * img->bit_per_pixels;
			*(unsigned int *)dst = 0x000000;
		}
	}
}

// void	clear_map(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i++ < screenHeight)
// 	{
// 		j = 0;
// 		while (j++ < screenWidth)
// 		{
// 			ft_pixel_put(i, j, &data->img, HBLACK);
// 		}
// 	}
// }

void	draw_wall_map(int x, int y, int size, t_data *data)
{
	int	i;

	i = -1;
	while (i++ < size)
	{
		ft_pixel_put(x + i, y, &data->img, HWHITE);
		ft_pixel_put(x, y + i, &data->img, HWHITE);
		ft_pixel_put(x + size, y + i, &data->img, HWHITE);
		ft_pixel_put(x + i, y + size, &data->img, HWHITE);
	}
}

void	draw_player(t_data *data, t_player *p, t_config *c)
{
	int	i;
	int	j;
	int	posX;
	int	posY;

	posX = p->x * c->block;
	posY = p->y * c->block;
	i = -1;
	while (i++ < c->player_size)
	{
		j = -1;
		while (j++ < c->player_size)
		{
			ft_pixel_put(posX + j - data->conf.player_size / 2, posY
				- data->conf.player_size / 2, &data->img, HRED);
		}
		posY += 1;
	}
}

void	draw_map(t_data *data, t_config *c)
{
	int		i;
	int		j;
	char	**map;

	map = data->param.map;
	i = 0;
	while (i < data->param.mapY)
	{
		j = 0;
		while (j < data->param.mapX)
		{
			if (map[i][j] == '1')
			{
				draw_wall_map(j * c->block, i * c->block, c->block, data);
			}
			j++;
		}
		i++;
	}
}

void	put_line(t_data *d, t_config *c, t_player *p, int x1, int y1)
{
	int	posX;
	int	posY;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	posX = p->x * c->block;
	posY = p->y * c->block;
	dx = abs(x1 - posX);
	dy = abs(y1 - posY);
	sx = (posX < x1) ? 1 : -1;
	sy = (posY < y1) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		ft_pixel_put(posX, posY, &d->img, HGREEN);
		if (posX == x1 && posY == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			posX += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			posY += sy;
		}
	}
}

// void	draw_rays(t_data *d, t_config *c, t_player *p, int hit_x, int hit_y)
// {
// 	int i;

// 	i = 0;
// 	while (i < c->nbr_rays)
// 	{
// 		float ray_angle = p->angle - (c->fov / 2.0) + (c->fov * i
				// / c->nbr_rays);
// 		int hitX, hitY;
// 		cast_ray(d, ray_angle, &hitX, &hitY);
// 		put_line(d, c, p, hit_x, hit_y);
// 		i++;
// 	}
// }
