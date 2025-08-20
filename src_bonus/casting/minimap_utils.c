/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:08:50 by mmarps            #+#    #+#             */
/*   Updated: 2025/08/20 20:46:00 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	advance_x(int *x, int bx, int *err, int dy)
{
	if (2 * (*err) >= dy)
	{
		*err += dy;
		if (*x < bx)
			(*x)++;
		else
			(*x)--;
	}
}

static void	advance_y(int *y, int by, int *err, int dx)
{
	if (2 * (*err) <= dx)
	{
		*err += dx;
		if (*y < by)
			(*y)++;
		else
			(*y)--;
	}
}

void	draw_line(t_img *img, t_point *a, t_point *b, int color)
{
	int	dx;
	int	dy;
	int	err;
	int	x;
	int	y;

	dx = abs(b->x - a->x);
	dy = -abs(b->y - a->y);
	x = a->x;
	y = a->y;
	err = dx + dy;
	while (1)
	{
		ft_pixel_put(x, y, img, color);
		if (x == b->x && y == b->y)
			break ;
		advance_x(&x, b->x, &err, dy);
		advance_y(&y, b->y, &err, dx);
	}
}

void	draw_square(t_img *img, t_point *a, int size, int color)
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
			ft_pixel_put(a->x + i, a->y + j, img, color);
			j++;
		}
		i++;
	}
}

int	get_minimap_scale(t_data *data)
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
