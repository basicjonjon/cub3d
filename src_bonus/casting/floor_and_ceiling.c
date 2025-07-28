/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:22:43 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/28 17:20:36 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_floor_ceiling_pixel(t_data *data, int x, int y,
		float *floorX, float *floorY)
{
	int		cellX;
	int		cellY;
	int		tx;
	int		ty;
	int		floorColor;
	int		ceilColor;

	cellX = (int)(*floorX);
	cellY = (int)(*floorY);

	tx = (int)(data->asset.south.tex_w * (*floorX - cellX));
	ty = (int)(data->asset.south.tex_h * (*floorY - cellY));

	if (tx < 0)
		tx += data->asset.south.tex_w;
	if (ty < 0)
		ty += data->asset.south.tex_h;

	tx %= data->asset.south.tex_w;
	ty %= data->asset.south.tex_h;

	floorColor = get_texture_pixel(&data->asset.south, tx, ty);
	ceilColor = get_texture_pixel(&data->asset.south, tx, ty);

	ft_pixel_put(x, y, &data->img, floorColor);
	ft_pixel_put(x, screenHeight - y, &data->img, ceilColor);
}

void	draw_floor_ceiling_line(t_data *data, int y,
		float rayDirX0, float rayDirY0, float rayDirX1, float rayDirY1)
{
	int		x;
	int		p;
	float	posZ;
	float	rowDistance;
	float	floorStepX;
	float	floorStepY;
	float	floorX;
	float	floorY;

	p = y - screenHeight / 2;
	posZ = 0.5f * screenHeight - 10.0f;

	rowDistance = posZ / (float)p;

	floorStepX = rowDistance * (rayDirX1 - rayDirX0) / (float)screenWidth;
	floorStepY = rowDistance * (rayDirY1 - rayDirY0) / (float)screenWidth;

	floorX = data->player.x + rowDistance * rayDirX0;
	floorY = data->player.y + rowDistance * rayDirY0;

	x = 0;
	while (x < screenWidth)
	{
		draw_floor_ceiling_pixel(data, x, y, &floorX, &floorY);
		floorX += floorStepX;
		floorY += floorStepY;
		x++;
	}
}

void	draw_floor_ceiling(t_data *data)
{
	int		y;
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;

	y = screenHeight / 2 + 1;
	rayDirX0 = data->player.dirX - data->player.planeX;
	rayDirY0 = data->player.dirY - data->player.planeY;
	rayDirX1 = data->player.dirX + data->player.planeX;
	rayDirY1 = data->player.dirY + data->player.planeY;

	while (y < screenHeight)
	{
		draw_floor_ceiling_line(data, y, rayDirX0, rayDirY0, rayDirX1, rayDirY1);
		y++;
	}
}
