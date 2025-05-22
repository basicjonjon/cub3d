/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:36:56 by jle-doua          #+#    #+#             */
/*   Updated: 2025/05/22 16:58:39 by jle-doua         ###   ########.fr       */
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
	int		x;
	char	*line;

	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	x = 0;
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
			if (i > x)
				x = i;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), x);
}

int	get_map_size_y(char *maps_file)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map(line))
			y++;
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), y);
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

t_map	*get_map(char *maps_file)
{
	int		i;
	int		fd;
	char	*line;
	t_map	*map;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->mapY = get_map_size_y(maps_file);
	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	map->map = malloc_map(maps_file);
	while (line != NULL)
	{
		if (is_map(line))
		{
			map->map[i] = dup_map_line(line, get_map_size_x(maps_file));
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), map);
}
