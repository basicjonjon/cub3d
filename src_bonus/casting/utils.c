/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:27 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/08/20 22:29:46 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x > screenWidth || y > screenHeight || x < 0 || y < 0)
		return ;
	offset = (y * img->line_lenght) + (x * (img->bit_per_pixels));
	*(unsigned int *)(img->addr + offset) = color;
}

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || y < 0 || x >= texture->tex_w || y >= texture->tex_h)
		return (0);
	pixel = texture->img.addr + (y * texture->img.line_lenght)
			+ (x * texture->img.bit_per_pixels);
	color = *(unsigned int *)pixel;
	return (color);
}

int	check_colision(float x, float y, t_map *m)
{
	char	**map;
	int		mapX;
	int		mapY;
	float	radius;

	map = m->map;
	mapX = m->mapX;
	mapY = m->mapY;
	radius = 0.1f;
	if (x - radius < 0 || x + radius >= mapX || y - radius < 0 || y + radius >= mapY)
		return (0);
	if (map[(int)(y - radius)][(int)(x - radius)] == '1' ||
		map[(int)(y - radius)][(int)(x + radius)] == '1' ||
		map[(int)(y + radius)][(int)(x - radius)] == '1' ||
		map[(int)(y + radius)][(int)(x + radius)] == '1')
		return (0);
	else if (map[(int)(y - radius)][(int)(x - radius)] == 'P' ||
		map[(int)(y - radius)][(int)(x + radius)] == 'P' ||
		map[(int)(y + radius)][(int)(x - radius)] == 'P' ||
		map[(int)(y + radius)][(int)(x + radius)] == 'P')
		return (0);
	return (1);
}

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
