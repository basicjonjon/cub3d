/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:00:23 by mmarps            #+#    #+#             */
/*   Updated: 2025/08/19 23:11:40 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	blend_color(int c1, int c2, float t)
{
	int	r;
	int	g;
	int	b;

	if (t < 0)
		t = 0;
	if (t > 1)
		t = 1;
	r = ((c1 >> 16) & 0xFF) * (1 - t) + ((c2 >> 16) & 0xFF) * t;
	g = ((c1 >> 8) & 0xFF) * (1 - t) + ((c2 >> 8) & 0xFF) * t;
	b = (c1 & 0xFF) * (1 - t) + ((c2 & 0xFF) * t);
	return ((r << 16) | (g << 8) | b);
}

int	apply_fog(int color, float dist, float density, int fog_color)
{
	float	factor;
	float	t;

	factor = expf(-dist * density);
	t = 1.0f - factor;
	return (blend_color(color, fog_color, t));
}

void	draw_wall_pixel(t_data *data, t_texture *tex, int sx, int y)
{
	int		color;
	int		fog_color;
	float	dist;
	float	density;

	color = get_texture_pixel(tex, data->hit.tex_x, data->hit.tex_y);
	dist = data->hit.perpwalldist;
	density = 0.05f;
	fog_color = 0x444444;
	color = apply_fog(color, dist, density, fog_color);
	ft_pixel_put(sx, y, &data->img, color);
}
