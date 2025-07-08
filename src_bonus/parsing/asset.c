/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:17:10 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/08 17:22:15 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_asset(char *line)
{
	if (!strncmp(line, "NO ", 3) || !strncmp(line, "SO ", 3) || !strncmp(line,
			"WE ", 3) || !strncmp(line, "EA ", 3) || !strncmp(line, "F ", 2)
		|| !strncmp(line, "C ", 2))
	{
		return (1);
	}
	return (0);
}

int	verif_asset(t_asset *asset)
{
	if (asset->so_path == NULL || asset->no_path == NULL
		|| asset->we_path == NULL || asset->ea_path == NULL
		|| asset->floor == NULL || asset->ceiling == NULL)
	{
		return (1);
	}
	return (0);
}

int	get_asset(char *maps_file, t_data *data)
{
	int		fd;
	int		nb_asset;
	char	*line;

	fd = open(maps_file, O_RDONLY);
	nb_asset = 6;
	init_asset_null(&data->asset);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_asset(line))
		{
			if (get_asset_path(&data->asset, line))
				return (close(fd), free(line), free_asset(data), 1);
			nb_asset--;
		}
		if (is_map(line) && nb_asset != 0)
		{
			ft_fprintf(2, "%sERROR :not enought asset%s\n", BRED, NC);
			return (close(fd), free(line), free_asset(data), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (verif_asset(&data->asset))
		return (free(line), free_asset(data), 1);
	return (0);
}
