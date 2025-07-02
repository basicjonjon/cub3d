/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:46:09 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/02 15:36:28 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_hud(t_data *data)
{
	int	h;

	if (create_img(data, &data->hud.batterie, BATERRIE5, &h))
	{
		return (1);
	}
	return (0);
}

void	draw_hud(t_data *data)
{
	// ft_pixel_put(100, 100, data);
}