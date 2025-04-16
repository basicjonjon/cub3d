/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:17:10 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/16 16:43:08 by jle-doua         ###   ########.fr       */
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
void	get_texture(char *maps_file)
{
	int fd;
	int nb_texture;
	char *line;

	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd, 0);
	nb_texture = 6;
	while (line != NULL )
	{
		if (is_texture(line))
		{
			nb_texture--;
			printf("%stexture %s", BGREEN, NC);
		}
		if (line[0] == ' ' || line[0] == '1' || line[0] == 1 || line[0] == 9)
		{
			printf("%sMap %s", BGREEN, NC);
		}
		
		printf("%s", line);

		free(line);
		line = get_next_line(fd, 0);
	}
}