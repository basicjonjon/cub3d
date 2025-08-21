/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:27 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/08/21 00:18:55 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_texture	*find_texture(t_data *data)
{
	if (data->hit.door_flg == true)
		return (&data->asset.door);
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

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x > SCREENWIDTH || y > SCREENHEIGHT || x < 0 || y < 0)
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
	int		map_x;
	int		map_y;
	float	radius;

	map = m->map;
	map_x = m->map_x;
	map_y = m->map_y;
	radius = 0.1f;
	if (x - radius < 0 || x + radius >= map_x
		|| y - radius < 0 || y + radius >= map_y)
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
	int		x;
	int		y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			dst = img->addr + y * img->line_lenght + x * img->bit_per_pixels;
			*(unsigned int *)dst = 0x000000;
			x++;
		}
		y++;
	}
}
