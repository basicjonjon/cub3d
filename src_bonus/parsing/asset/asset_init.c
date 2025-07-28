/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:17:10 by jle-doua          #+#    #+#             */
<<<<<<< HEAD:src/parsing/asset.c
/*   Updated: 2025/07/03 15:42:13 by jle-doua         ###   ########.fr       */
=======
/*   Updated: 2025/07/22 14:28:52 by jle-doua         ###   ########.fr       */
>>>>>>> dev:src_bonus/parsing/asset/asset_init.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"


int	get_path(char *line, t_data *data, int *nb_asset)
{
	if (is_asset(line))
	{
		if (get_asset_path(&data->asset, line))
			return (ft_fprintf(2, "%sERROR : invalide assets%s\n", BRED, NC),
				1);
		*nb_asset -= 1;
	}
	return (0);
}

int	get_asset(char *maps_file, t_data *data)
{
	int		fd;
	int		nb_asset;
	char	*line;

	fd = open(maps_file, O_RDONLY);
	if (fd == -1)
		return (ft_fprintf(2, "%sERROR : file inexistant%s\n", RED, NC));
	nb_asset = 6;
<<<<<<< HEAD:src/parsing/asset.c
	init_asset_null(data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_asset(line))
		{
			if (get_asset_path(&data->asset, line))
				return (close(fd), free(line), 1);
			nb_asset--;
		}
		if (is_map(line) && nb_asset != 0)
		{
			ft_fprintf(2, "%sERROR :not enought asset%s\n", BRED, NC);
			return (close(fd), free(line), 1);
		}
=======
	ft_memset(&data->asset, 0, sizeof(t_asset));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (get_path(line, data, &nb_asset))
			return (free(line), 1);
		if (is_map(line) && nb_asset != 0)
			return (free(line), ft_fprintf(2, "%sERROR : invalide assets\n%s",
					BRED, NC), 1);
>>>>>>> dev:src_bonus/parsing/asset/asset_init.c
		free(line);
		line = get_next_line(fd);
	}
	if (verif_asset(&data->asset))
<<<<<<< HEAD:src/parsing/asset.c
		return (free(line), 1);
=======
		return (ft_fprintf(2, "%sERROR : invalide assets%s\n", BRED, NC), 1);
>>>>>>> dev:src_bonus/parsing/asset/asset_init.c
	return (0);
}
