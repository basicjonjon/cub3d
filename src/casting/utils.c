/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:27 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/29 12:14:55 by mmarpaul         ###   ########.fr       */
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
	pixel = texture->img.addr + (y * texture->img.line_lenght) \
		+ (x * texture->img.bit_per_pixels);
	color = *(unsigned int *)pixel;
	return (color);
}

void	cast_floor(t_img *img, int color)
{
	int	x;
	int	y;

	y = screenHeight / 2;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			ft_pixel_put(x, y, img, color);
			x++;
		}
		y++;
	}
}

void	cast_ceiling(t_img *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < screenWidth)
	{
		y = 0;
		while (y < screenHeight / 2)
		{
			ft_pixel_put(x, y, img, color);
			y++;
		}
		x++;
	}
}
