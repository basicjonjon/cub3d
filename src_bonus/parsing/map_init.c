/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:36:56 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/08 17:22:15 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int		y;
	// int		i;
	char	**map;

	// x = get_map_size_x(maps_file);
	y = get_map_size_y(maps_file);
	// i = 0;
	map = malloc(sizeof(char *) * (y + 1));
	if (map == NULL)
		return (NULL);
	map = init_map_null(map, y + 1);
	return (map);
}

int	get_map(t_data *data, char *maps_file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	data->param.mapY = get_map_size_y(maps_file);
	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	data->param.map = malloc_map(maps_file);
	data->param.mapX = get_map_size_x(maps_file);
	data->param.mapY = get_map_size_y(maps_file);
	while (line != NULL)
	{
		if (is_map(line))
		{
			data->param.map[i] = dup_map_line(line, get_map_size_x(maps_file));
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), 0);
}
