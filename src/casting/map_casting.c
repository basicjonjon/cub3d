/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:06:53 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/06/09 19:21:36 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void clear_image(t_img *img, int width, int height)
{
    int x, y;

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            char *dst = img->addr + y * img->line_lenght + x * img->bit_per_pixels;
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

void	draw_wall(int x, int y, int size, t_data *data)
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

void	draw_player(int x, int y, int size, int color, t_data *data)
{
	int	i;
	int	j;
	
	i = -1;
	while (i++ < size)
	{
		j = -1;
		while (j++ < size)
		{
			ft_pixel_put(x + j - playerSize / 2, y - playerSize / 2, &data->img, color);
		}
		y += 1;
	}
}

void	draw_map(t_data *data)
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
				draw_wall(j * BLOCK, i * BLOCK, BLOCK, data);
			}
			j++;
		}
		i++;
	}
}
