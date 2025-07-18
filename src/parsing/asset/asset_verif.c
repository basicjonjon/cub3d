/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:06 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/18 15:43:12 by jle-doua         ###   ########.fr       */
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
	if (!asset->north.path || !asset->south.path || !asset->east.path
		|| !asset->west.path)
		return (1);
	if (asset->north.path[0] == '\0' || asset->south.path[0] == '\0'
		|| asset->east.path[0] == '\0' || asset->west.path[0] == '\0')
		return (1);
	if (asset->ceiling == -1 || asset->floor == -1)
		return (1);
	return (0);
}

int	split_size(char **res)
{
	int i;

	i = 0;
	while (res[i])
		i++;
	return (i);
}