/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:27 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/08 19:26:42 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	if (x < 0 || y < 0 || x >= texture->tex_w || y >= texture->tex_w)
		return (0);
	pixel = texture->img.addr + (y * texture->img.line_lenght) + (x * texture->img.bit_per_pixels);
	color = *(unsigned int *)pixel;
	return (color);
}

int verif_move(t_player *player)
{
	if (player->keyDown || player->keyLeft
		|| player->keyRight || player->keyUp
		|| player->rotLeft || player->rotRight)
		return (1);
	else
		return (0);
}

int	check_colision(float x, float y, t_map *m)
{
	int		i;
	int		j;
	char	**map;

	// return (1);
	i = (int)x;
	j = (int)y;
	map = m->map;
	if (x < 0 || x >= m->mapX || y < 0 || y >= m->mapY)
		return (0);
	if (map[j][i] && map[j][i] == '1')
		return (0);
	return (1);
}

// int	rgb_to_int(t_color rgb)
// {
// 	return ((rgb.r << 16) | (rgb.g << 8) | (rgb.b));
// }
