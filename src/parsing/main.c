/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:30:10 by jle-doua          #+#    #+#             */
/*   Updated: 2025/06/02 14:10:15 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv, char **envp)
{
	t_data *data;

	if (!envp[0] || verif_args(argc, argv))
		return (1);
	data = init_data(argv[1]);
	if (data == NULL)
		return (1);
	print_asset_path(data->asset);
	print_player_info(data);
	print_map_info(data);
	print_map(data->param.map);
	// mlx_loop(data->mlx);
	free_all(data);
	return (0);
}