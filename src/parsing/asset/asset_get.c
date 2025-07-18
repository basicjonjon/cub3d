/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:47:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/18 16:18:30 by jle-doua         ###   ########.fr       */
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
	if (split_size(cut_line) != 3)
		return (ft_fprintf(2, "%sERROR :wrong color format2%s\n", BRED, NC),
			free_tab(cut_line), -1);
	if (cut_line[0][0] == '\n' || cut_line[1][0] == '\n'
		|| cut_line[2][0] == '\n')
		return (ft_fprintf(2, "%sERROR :wrong color format%s\n", BRED, NC),
			free_tab(cut_line), -1);
	r = ft_atol(cut_line[0]) % 255;
	g = ft_atol(cut_line[1]) % 255;
	b = ft_atol(cut_line[2]) % 255;
	free_tab(cut_line);
	return ((r << 16) | (g << 8) | (b));
}

void	save_asset(t_asset *asset, char *key, char *value)
{
	if (!strncmp(key, "NO", 2) && asset->north.path == NULL)
	{
		asset->north.path = ft_strdup(value);
		asset->north.path[ft_strlen(asset->north.path) - 1] = '\0';
	}
	if (!strncmp(key, "SO", 2) && asset->south.path == NULL)
	{
		asset->south.path = ft_strdup(value);
		asset->south.path[ft_strlen(asset->south.path) - 1] = '\0';
	}
	if (!strncmp(key, "WE", 2) && asset->west.path == NULL)
	{
		asset->west.path = ft_strdup(value);
		asset->west.path[ft_strlen(asset->west.path) - 1] = '\0';
	}
	if (!strncmp(key, "EA", 2) && asset->east.path == NULL)
	{
		asset->east.path = ft_strdup(value);
		asset->east.path[ft_strlen(asset->east.path) - 1] = '\0';
	}
}
void	save_color(t_asset *asset, char *key, char *value)
{
	if (!strncmp(key, "F", 1) && asset->floor != 0)
		asset->floor = -1;
	else if (!strncmp(key, "F", 1) && asset->floor == 0)
		asset->floor = get_color(value);
	if (!strncmp(key, "C", 1) && asset->ceiling != 0)
		asset->ceiling = -1;
	else if (!strncmp(key, "C", 1) && asset->ceiling == 0)
		asset->ceiling = get_color(value);
}

int	get_asset_path(t_asset *asset, char *line)
{
	char **res;

	res = ft_split(line, ' ');
	if (split_size(res) != 2)
		return (ft_fprintf(2, BRED "ERROR : texture format\n" NC), 1); //
	save_asset(asset, res[0], res[1]);
	save_color(asset, res[0], res[1]);

	free_tab(res);

	return (0);
}