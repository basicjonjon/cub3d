/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:14:23 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/22 16:02:37 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_hud_test(t_data *data, int x_start, int y_start, int size)
{
	int save_x;
	int color;
	t_texture batterie;

	batterie.path = "assets/xpm/hud/batterie/bat5.xpm";
	create_img(data, &batterie);

	save_x = x_start - 1;
	while (y_start < size)
	{
		x_start = save_x;
		while (++x_start < size)
		{
			color = get_texture_pixel(&batterie, x_start, y_start);
			if (color > 0)
			{
				ft_pixel_put(x_start, y_start, &data->img, color);
			}
		}

		y_start++;
	}
}