/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:14:23 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/22 14:50:38 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_hud_test(t_data *data, int x_start, int y_start, int size)
{
	int save_x;

	save_x = x_start -1;
	while (y_start < size)
	{
		x_start = save_x;
		while (++x_start < size)
			ft_pixel_put(x_start, y_start, &data->img, 255);
		y_start++;
	}
}