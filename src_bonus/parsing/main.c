/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:30:10 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/22 14:31:31 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (!envp[0] || verif_args(argc, argv))
		return (1);
	if (init_data(&data, argv[1]) != 0)
		return (1);
	print_asset_path(data.asset);
	print_player_info(&data);
	print_map_info(&data);
	print_map(data.param.map);
	hooks(&data);
	mlx_loop_hook(data.mlx, raycasting, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
