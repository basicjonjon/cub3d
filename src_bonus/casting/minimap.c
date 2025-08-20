/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:29:01 by mmarps            #+#    #+#             */
/*   Updated: 2025/08/19 22:45:45 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#define MINIMAP_SCALE 5

static void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	sx = (x0 < x1);
	if (!sx)
		sx = -1;
	dy = -abs(y1 - y0);
	sy = (y0 < y1);
	if (!sy)
		sy = -1;
	err = dx + dy;
	while (1)
	{
		ft_pixel_put(x0, y0, img, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

static void	draw_square(t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	if (color == -1)
		return ;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_pixel_put(x + i, y + j, img, color);
			j++;
		}
		i++;
	}
}

static int	get_minimap_scale(t_data *data)
{
	int	scale_x;
	int	scale_y;
	int	scale;
	int	max_w;
	int	max_h;

	max_w = screenWidth * 6 / 10;
	max_h = screenHeight / 4;
	scale_x = max_w / data->param.mapX;
	scale_y = max_h / data->param.mapY;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	if (scale < 2)
		scale = 2;
	return (scale);
}

static void	draw_minimap_map(t_data *data, int off_x, int off_y, int scale)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < data->param.mapY)
	{
		x = 0;
		while (x < data->param.mapX)
		{
			if (data->param.map[y][x] == '1')
				color = 0xAAAAAA;
			else if (data->param.map[y][x] == 'P')
				color = 0x00AAFF;
			else
				color = -1; //color = 0x222222;
			draw_square(&data->img,
				off_x + x * scale,
				off_y + y * scale,
				scale, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int	scale;
	int	off_x;
	int	off_y;
	int	px;
	int	py;
	int	dx;
	int	dy;

	scale = get_minimap_scale(data);
	off_x = (screenWidth - data->param.mapX * scale) / 2;
	off_y = 0;
	draw_minimap_map(data, off_x, off_y, scale);
	px = off_x + (int)(data->player.x * scale);
	py = off_y + (int)(data->player.y * scale);
	draw_square(&data->img, px - 2, py - 2, 4, 0xFF0000);
	dx = (int)(px + data->player.dirX * 10);
	dy = (int)(py + data->player.dirY * 10);
	draw_line(&data->img, px, py, dx, dy, 0xFF0000);
}

// static void	draw_square(t_img *img, int x, int y, int size, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			ft_pixel_put(x + i, y + j, img, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
// {
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;

// 	dx = abs(x1 - x0);
// 	sx = (x0 < x1);
// 	if (!sx)
// 		sx = -1;
// 	dy = -abs(y1 - y0);
// 	sy = (y0 < y1);
// 	if (!sy)
// 		sy = -1;
// 	err = dx + dy;
// 	while (1)
// 	{
// 		ft_pixel_put(x0, y0, img, color);
// 		if (x0 == x1 && y0 == y1)
// 			break ;
// 		e2 = 2 * err;
// 		if (e2 >= dy)
// 		{
// 			err += dy;
// 			x0 += sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }

// static void	draw_minimap_map(t_data *data, int offset_x, int offset_y)
// {
// 	int	x;
// 	int	y;
// 	int	color;

// 	y = 0;
// 	while (y < data->param.mapY)
// 	{
// 		x = 0;
// 		while (x < data->param.mapX)
// 		{
// 			if (data->param.map[y][x] == '1')
// 				color = 0xAAAAAA;
// 			else if (data->param.map[y][x] == 'P')
// 				color = 0x00AAFF;
// 			else
// 				color = 0x222222;
// 			draw_square(&data->img,
// 				offset_x + x * MINIMAP_SCALE,
// 				offset_y + y * MINIMAP_SCALE,
// 				MINIMAP_SCALE, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_minimap(t_data *data)
// {
// 	int	offset_x;
// 	int	offset_y;
// 	int	px;
// 	int	py;
// 	int	dx;
// 	int	dy;

// 	offset_x = (screenWidth - data->param.mapX * MINIMAP_SCALE) / 2;
// 	offset_y = 30;
// 	draw_minimap_map(data, offset_x, offset_y);
// 	px = offset_x + (int)(data->player.x * MINIMAP_SCALE);
// 	py = offset_y + (int)(data->player.y * MINIMAP_SCALE);
// 	draw_square(&data->img, px - 2, py - 2, 4, 0xFF0000);
// 	dx = (int)(px + data->player.dirX * 10);
// 	dy = (int)(py + data->player.dirY * 10);
// 	draw_line(&data->img, px, py, dx, dy, 0x00FF00);
// }

// #define MINIMAP_SCALE 5

// void	draw_square(t_img *img, int x, int y, int size, int color)
// {
// 	int	i, j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			ft_pixel_put(x + i, y + j, img, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
// {
// 	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
// 	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
// 	int err = dx + dy, e2;

// 	while (1)
// 	{
// 		ft_pixel_put(x0, y0, img, color);
// 		if (x0 == x1 && y0 == y1) break;
// 		e2 = 2 * err;
// 		if (e2 >= dy) { err += dy; x0 += sx; }
// 		if (e2 <= dx) { err += dx; y0 += sy; }
// 	}
// }

// void	draw_minimap(t_data *data)
// {
// 	int	x, y;
// 	int	color;

// 	y = 0;
// 	while (y < data->param.mapY)
// 	{
// 		x = 0;
// 		while (x < data->param.mapX)
// 		{
// 			if (data->param.map[y][x] == '1')
// 				color = 0xAAAAAA; // gris pour les murs
// 			else if (data->param.map[y][x] == 'P')
// 				color = 0x00AAFF; // bleu clair pour les portes
// 			else
// 				color = 0x222222; // sol (foncé)
// 			draw_square(&data->img,
// 				x * MINIMAP_SCALE,
// 				y * MINIMAP_SCALE,
// 				MINIMAP_SCALE, color);
// 			x++;
// 		}
// 		y++;
// 	}

// 	// joueur
// 	int px = (int)(data->player.x * MINIMAP_SCALE);
// 	int py = (int)(data->player.y * MINIMAP_SCALE);
// 	draw_square(&data->img, px - 2, py - 2, 4, 0xFF0000);

// 	// direction du joueur
// 	int dx = (int)(px + data->player.dirX * 10);
// 	int dy = (int)(py + data->player.dirY * 10);
// 	draw_line(&data->img, px, py, dx, dy, 0x00FF00);
// }
