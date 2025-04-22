/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:49:28 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/22 15:56:40 by jle-doua         ###   ########.fr       */
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
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_data_null(data);
	data->texture = get_texture(map_file);
	if (data->texture == NULL)
		return (free(data), NULL);
	data->map = get_map(map_file);
	if (data->map == NULL)
		return (free(data), free(data->texture), NULL);
	return (data);
}