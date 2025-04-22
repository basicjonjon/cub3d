/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:17:10 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/22 16:02:06 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_texture(char *line)
{
	if (!strncmp(line, "NO ", 3) || !strncmp(line, "SO ", 3) || !strncmp(line,
			"WE ", 3) || !strncmp(line, "EA ", 3) || !strncmp(line, "F ", 2)
		|| !strncmp(line, "C ", 2))
	{
		return (1);
	}
	return (0);
}
int	verif_texture(t_texture *texture)
{
	if (texture->so_path == NULL || texture->no_path == NULL
		|| texture->we_path == NULL || texture->ea_path == NULL
		|| texture->floor == NULL || texture->ceiling == NULL)
	{
		return (1);
	}
	return (0);
}
t_texture	*get_texture(char *maps_file)
{
	int			fd;
	int			nb_texture;
	char		*line;
	t_texture	*texture;

	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd, 0);
	nb_texture = 6;
	texture = init_texture_null();
	while (line != NULL)
	{
		if (is_texture(line))
		{
			texture = get_texture_path(texture, line);
			if (texture == NULL)
				return (close(fd), free(line), NULL);
			nb_texture--;
		}
		if (is_map(line) && nb_texture != 0)
		{
			ft_fprintf(2, "%sERROR :not enought texture%s\n", BRED, NC);
			return (free(line), NULL);
		}
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
	if (verif_texture(texture))
		return (NULL);
	return (texture);
}
