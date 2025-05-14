/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:22 by jle-doua          #+#    #+#             */
/*   Updated: 2025/05/13 14:37:28 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_asset(t_asset *asset)
{
	if (asset->no_path)
		free(asset->no_path);
	if (asset->so_path)
		free(asset->so_path);
	if (asset->ea_path)
		free(asset->ea_path);
	if (asset->we_path)
		free(asset->we_path);
	if (asset->floor)
		free(asset->floor);
	if (asset->ceiling)
		free(asset->ceiling);
	free(asset);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	destroy_texture(t_data *data)
{
	if (data->texture->no_wall)
		mlx_destroy_image(data->mlx, data->texture->no_wall);
	if (data->texture->so_wall)
		mlx_destroy_image(data->mlx, data->texture->so_wall);
	if (data->texture->ea_wall)
		mlx_destroy_image(data->mlx, data->texture->ea_wall);
	if (data->texture->we_wall)
		mlx_destroy_image(data->mlx, data->texture->we_wall);
	if (data->texture)
		free(data->texture);
}

void	free_all(t_data *data)
{
	if (data)
	{
		if (data->asset)
			free_asset(data->asset);
		if (data->map)
			free_map(data);
		if (data->texture)
			destroy_texture(data);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		free(data);
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}