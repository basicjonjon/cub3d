/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:17:10 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/17 16:20:46 by jle-doua         ###   ########.fr       */
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

int	is_map(char *line, int nb_texture)
{
	if ((line[0] == ' ' || line[0] == '1' || line[0] == 1 || line[0] == 9)
		&& nb_texture != 0)
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
				return (free(line), NULL);
			nb_texture--;
		}
		if (is_map(line, nb_texture))
		{
			ft_fprintf(2, "%sERROR :not enought texture%s\n", BRED, NC);
			return (free(line), NULL);
		}
		free(line);
		line = get_next_line(fd, 0);
	}
	print_texture_path(texture);
	return (texture);
}
