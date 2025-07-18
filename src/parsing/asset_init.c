/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:47:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/08 19:20:43 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(char *value)
{
	char	**cut_line;
	int		i;
	int		r;
	int		g;
	int		b;

	cut_line = ft_split(value, ',');
	i = 0;
	while (cut_line[i] != NULL)
	{
		i++;
	}
	if (i != 3)
	{
		ft_fprintf(2, "%sERROR :wrong color format%s\n", BRED, NC);
		return (free_tab(cut_line), -1);
	}
	r = ft_atol(cut_line[0]) % 255;
	g = ft_atol(cut_line[1]) % 255;
	b = ft_atol(cut_line[2]) % 255;
	free_tab(cut_line);
	return ((r << 16) | (g << 8) | (b));
}

void	save_path(t_asset *asset, char *key, char *value)
{
	if (!strncmp(key, "SO", 2))
	{
		asset->south.path = ft_strdup(value);
		asset->south.path[ft_strlen(asset->south.path) - 1] = '\0';
	}
	if (!strncmp(key, "NO", 2))
	{
		asset->north.path = ft_strdup(value);
		asset->north.path[ft_strlen(asset->north.path) - 1] = '\0';
	}
	if (!strncmp(key, "WE", 2))
	{
		asset->west.path = ft_strdup(value);
		asset->west.path[ft_strlen(asset->west.path) - 1] = '\0';
	}
	if (!strncmp(key, "EA", 2))
	{
		asset->east.path = ft_strdup(value);
		asset->east.path[ft_strlen(asset->east.path) - 1] = '\0';
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
