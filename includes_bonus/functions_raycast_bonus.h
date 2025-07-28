/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_raycast_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:26:03 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/28 15:25:32 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_RAYCAST_BONUS_H
# define FUNCTIONS_RAYCAST_BONUS_H

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
int		get_texture_pixel(t_texture *texture, int x, int y);
int 	verif_move(t_player *player);
int		check_colision(float x, float y, t_map *m);
// int		rgb_to_int(t_color rgb);

////////////////////////////////////////////////////////////
// MAP CASTING
////////////////////////////////////////////////////////////
void	draw_wall_map(int x, int y, int size, t_data *data);
void	draw_player(t_data *data, t_player *p, t_config *c);
void	draw_map(t_data *data, t_config *c);
// void	clear_map(t_data *data);
void	clear_image(t_img *img, int width, int height);
// void	draw_rays(t_data *d, t_config *c, t_player *p, int hit_x, int hit_y);
void	put_line(t_data *d, t_config *c, t_player *p, int x1, int y1);

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

////////////////////////////////////////////////////////////
// DRAW FLOOR AND CEILING
////////////////////////////////////////////////////////////
void	draw_floor_ceiling(t_data *data);

#endif