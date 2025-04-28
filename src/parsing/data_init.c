/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:49:28 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/28 13:30:18 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data_null(t_data *data)
{
	data->map = NULL;
	data->mlx = NULL;
	data->texture = NULL;
	data->win = NULL;
}

t_data	*init_data(char *map_file)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_data_null(data);
	data->asset = get_asset(map_file);
	if (!data->asset)
		return (free_all(data), NULL);
	data->map = get_map(map_file);
	if (!data->map)
		return (free_all(data), NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_all(data), NULL);
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Cub3d");
	if (!data->win)
		return (free_all(data), NULL);
	return (data);
}
