/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:47:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/17 16:33:44 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_texture	*init_texture_null(void)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	texture->no_wall = NULL;
	texture->no_path = NULL;
	texture->so_wall = NULL;
	texture->so_path = NULL;
	texture->we_wall = NULL;
	texture->we_path = NULL;
	texture->ea_wall = NULL;
	texture->ea_path = NULL;
	texture->ceiling = NULL;
	texture->floor = NULL;
	return (texture);
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
		ft_fprintf(2, "%sERROR: wrong color format%s\n", BRED, NC);
		return (NULL);
	}
	color = malloc(sizeof(t_color));
	color->r = ft_atol(cut_line[0]) % 255;
	color->g = ft_atol(cut_line[1]) % 255;
	color->b = ft_atol(cut_line[2]) % 255;
	return (color);
}

void	save_path(t_texture *texture, char *key, char *value)
{
	if (!strncmp(key, "SO", 2))
	{
		texture->so_path = value;
	}
	if (!strncmp(key, "NO", 2))
	{
		texture->no_path = value;
	}
	if (!strncmp(key, "WE", 2))
	{
		texture->we_path = value;
	}
	if (!strncmp(key, "EA", 2))
	{
		texture->ea_path = value;
	}
	if (!strncmp(key, "F", 1))
	{
		texture->floor = get_color(value);
	}
	if (!strncmp(key, "C", 1))
	{
		texture->ceiling = get_color(value);
	}
}

t_texture	*get_texture_path(t_texture *texture, char *line)
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
		return (NULL);
	}
	save_path(texture, cut_line[0], cut_line[1]);
	return (texture);
}
