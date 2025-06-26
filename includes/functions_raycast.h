/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_raycast.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:26:03 by jle-doua          #+#    #+#             */
/*   Updated: 2025/06/26 17:40:55 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_RAYCAST_H
# define FUNCTIONS_RAYCAST_H

////////////////////////////////////////////////////////////
// DEBUG
////////////////////////////////////////////////////////////
int		debug(t_data *data);

////////////////////////////////////////////////////////////
// HOOKS
////////////////////////////////////////////////////////////
void	hooks(t_data *data);

////////////////////////////////////////////////////////////
// MOVEMENT
////////////////////////////////////////////////////////////
int		move_player(t_data *data, t_player *player, t_config *c);

////////////////////////////////////////////////////////////
// UTILS
////////////////////////////////////////////////////////////
void	ft_pixel_put(int x, int y, t_img *img, int color);
int		get_texture_pixel(t_img *texture, int x, int y);
int 	verif_move(t_player *player);
int		check_colision(float x, float y, t_map *m);
int		rgb_to_int(t_color rgb);

////////////////////////////////////////////////////////////
// MAP CASTING
////////////////////////////////////////////////////////////
void	draw_wall_map(int x, int y, int size, t_data *data);
void	draw_player(int x, int y, int size, int color, t_data *data);
void	draw_map(t_data *data);
// void	clear_map(t_data *data);
void	clear_image(t_img *img, int width, int height);

////////////////////////////////////////////////////////////
// RAYCASTING
////////////////////////////////////////////////////////////
int		raycasting(t_data *data);

////////////////////////////////////////////////////////////
// RAYCATING UTILS
////////////////////////////////////////////////////////////
t_ray	init_ray_struct(t_player *player, float ray_angle);
void	calc_hit(t_data *data, t_ray *ray, char **map, int *side);
float	calc_wall_hit_x(t_ray *ray, int side, float dist);

#endif