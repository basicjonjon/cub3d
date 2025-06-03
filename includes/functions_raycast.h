/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_raycast.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:26:03 by jle-doua          #+#    #+#             */
/*   Updated: 2025/06/03 18:24:28 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_RAYCAST_H
# define FUNCTIONS_RAYCAST_H

////////////////////////////////////////////////////////////
// HOOKS
////////////////////////////////////////////////////////////
void	hooks(t_data *data);

////////////////////////////////////////////////////////////
// MOVEMENT
////////////////////////////////////////////////////////////
int		move_loop(t_data *data);

////////////////////////////////////////////////////////////
// UTILS
////////////////////////////////////////////////////////////
void	ft_pixel_put(int x, int y, t_img *img, int color);
int 	verif_move(t_player *player);
int		check_colision(double x, double y, char **map);

////////////////////////////////////////////////////////////
// MAP CASTING
////////////////////////////////////////////////////////////
void	draw_wall(int x, int y, int size, t_data *data);
void	draw_player(int x, int y, int size, int color, t_data *data);
void	draw_map(t_data *data);


#endif