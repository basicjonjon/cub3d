/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:49:07 by jle-doua          #+#    #+#             */
/*   Updated: 2025/05/14 13:41:24 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_texture_null(t_texture *texture)
{
	texture->no_wall = NULL;
	texture->so_wall = NULL;
	texture->we_wall = NULL;
	texture->ea_wall = NULL;
}

int	verif_texture(t_data *data)
{
	if (data->texture->no_wall == NULL)
		ft_fprintf(2, "%sERROR: %s is invalide%s\n", BRED, data->asset->no_path,
			NC);
	if (data->texture->so_wall == NULL)
		ft_fprintf(2, "%sERROR: %s is invalide%s\n", BRED, data->asset->so_path,
			NC);
	if (data->texture->ea_wall == NULL)
		ft_fprintf(2, "%sERROR: %s is invalide%s\n", BRED, data->asset->ea_path,
			NC);
	if (data->texture->we_wall == NULL)
		ft_fprintf(2, "%sERROR: %s is invalide%s\n", BRED, data->asset->we_path,
			NC);
	if (!data->texture->no_wall || !data->texture->so_wall
		|| !data->texture->ea_wall || !data->texture->we_wall)
	{
		return (1);
	}
	return (0);
}
t_texture	*init_texture(t_data *data)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture) * 1);
	if (texture == NULL)
		return (NULL);
	init_texture_null(texture);
	texture->size = 100;
	texture->no_wall = mlx_xpm_file_to_image(data->mlx, data->asset->no_path,
			&texture->size, &texture->size);
	texture->so_wall = mlx_xpm_file_to_image(data->mlx, data->asset->so_path,
			&texture->size, &texture->size);
	texture->we_wall = mlx_xpm_file_to_image(data->mlx, data->asset->we_path,
			&texture->size, &texture->size);
	texture->ea_wall = mlx_xpm_file_to_image(data->mlx, data->asset->ea_path,
			&texture->size, &texture->size);
	return (texture);
}
