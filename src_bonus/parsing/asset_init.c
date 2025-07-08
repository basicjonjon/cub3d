/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:47:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/08 17:22:15 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_asset_null(t_asset *asset)
{
	asset->no_path = NULL;
	asset->so_path = NULL;
	asset->we_path = NULL;
	asset->ea_path = NULL;
	asset->ceiling = NULL;
	asset->floor = NULL;
}

t_color	*get_color(char *value)
{
	char	**cut_line;
	t_color	*color;
	int		i;

	cut_line = ft_split(value, ',');
	i = 0;
	while (cut_line[i] != NULL)
	{
		i++;
	}
	if (i != 3)
	{
		ft_fprintf(2, "%sERROR :wrong color format%s\n", BRED, NC);
		return (free_tab(cut_line), NULL);
	}
	color = malloc(sizeof(t_color));
	color->r = ft_atol(cut_line[0]) % 255;
	color->g = ft_atol(cut_line[1]) % 255;
	color->b = ft_atol(cut_line[2]) % 255;
	return (free_tab(cut_line), color);
}

void	save_path(t_asset *asset, char *key, char *value)
{
	if (!strncmp(key, "SO", 2))
	{
		asset->so_path = ft_strdup(value);
		asset->so_path[ft_strlen(asset->so_path) - 1] = '\0';
	}
	if (!strncmp(key, "NO", 2))
	{
		asset->no_path = ft_strdup(value);
		asset->no_path[ft_strlen(asset->no_path) - 1] = '\0';
	}
	if (!strncmp(key, "WE", 2))
	{
		asset->we_path = ft_strdup(value);
		asset->we_path[ft_strlen(asset->we_path) - 1] = '\0';
	}
	if (!strncmp(key, "EA", 2))
	{
		asset->ea_path = ft_strdup(value);
		asset->ea_path[ft_strlen(asset->ea_path) - 1] = '\0';
	}
	if (!strncmp(key, "F", 1))
		asset->floor = get_color(value);
	if (!strncmp(key, "C", 1))
		asset->ceiling = get_color(value);
}

int	get_asset_path(t_asset *asset, char *line)
{
	char	**cut_line;
	int		i;

	cut_line = ft_split(line, ' ');
	i = 0;
	while (cut_line[i] != NULL)
		i++;
	if (i != 2 || (cut_line[1] != NULL && (cut_line[1][0] == '\0'
				|| cut_line[1][0] == '\n')))
	{
		ft_fprintf(2, "%sERROR: wrong texture format%s\n", BRED, NC);
		return (1);
	}
	save_path(asset, cut_line[0], cut_line[1]);
	free_tab(cut_line);
	return (0);
}
