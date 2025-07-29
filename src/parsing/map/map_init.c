/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:36:56 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/29 13:33:57 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	char	**map;

	y = get_map_size_y(maps_file);
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
	fd = open(maps_file, O_RDONLY);
	data->param.map = malloc_map(maps_file);
	data->param.map_x = get_map_size_x(maps_file);
	data->param.map_y = get_map_size_y(maps_file);
	line = skip_line(fd);
	while (line != NULL && i < data->param.map_y)
	{
		if (is_map(line) || line[0] == '\n')
		{
			data->param.map[i] = dup_map_line(line, get_map_size_x(maps_file));
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), 0);
}
