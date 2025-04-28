/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:36:56 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/28 13:24:23 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map(char *line)
{
	if ((line[0] == ' ' || line[0] == '0' || line[0] == '1' || line[0] == 1
			|| line[0] == 9))
	{
		return (1);
	}
	return (0);
}

int	get_map_size_x(char *maps_file)
{
	int		i;
	int		y;
	int		fd;
	int		max_value;
	char	*line;

	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	max_value = 0;
	while (line != NULL)
	{
		i = 0;
		if (is_map(line))
		{
			y = 0;
			while (line[y] != '\n' && line[y] != '\0')
			{
				if (line[y] == 9)
					i += 4;
				else
					i++;
				y++;
			}
			if (i > max_value)
				max_value = i;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), max_value);
}

int	get_map_size_y(char *maps_file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map(line))
			i++;
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), i);
}

char	**init_map_null(char **map, int y)
{
	int	i;

	i = 0;
	while (i != y)
	{
		map[i] = NULL;
		i++;
	}
	return (map);
}

char	**malloc_map(char *maps_file)
{
	int		x;
	int		y;
	int		i;
	char	**map;

	x = get_map_size_x(maps_file);
	y = get_map_size_y(maps_file);
	i = 0;
	map = malloc(sizeof(char *) * (y + 1));
	if (map == NULL)
		return (NULL);
	map = init_map_null(map, y + 1);
	return (map);
}

char	**get_map(char *maps_file)
{
	int		i;
	int		fd;
	int		size;
	char	*line;
	char	**map;

	i = 0;
	size = get_map_size_y(maps_file);
	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	map = malloc_map(maps_file);
	while (line != NULL)
	{
		if (is_map(line))
		{
			map[i] = dup_map_line(line, get_map_size_x(maps_file));
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), map);
}
