/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_raycast.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:26:03 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/29 13:29:35 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_RAYCAST_H
# define FUNCTIONS_RAYCAST_H

////////////////////////////////////////////////////////////
// DEBUG
////////////////////////////////////////////////////////////
int			debug(t_data *data);

////////////////////////////////////////////////////////////
// HOOKS
////////////////////////////////////////////////////////////
void		hooks(t_data *data);

////////////////////////////////////////////////////////////
// MOVEMENT
////////////////////////////////////////////////////////////
int			move_player(t_player *player, t_config *c);

////////////////////////////////////////////////////////////
// UTILS
////////////////////////////////////////////////////////////
void		ft_pixel_put(int x, int y, t_img *img, int color);
int			get_texture_pixel(t_texture *texture, int x, int y);
t_dir		find_dir(t_ray *ray, int side);
void		cast_floor(t_img *img, int color);
void		cast_ceiling(t_img *img, int color);

////////////////////////////////////////////////////////////
// UTILS
////////////////////////////////////////////////////////////
t_dir		find_dir(t_ray *ray, int side);
void		clear_image(t_img *img, int width, int height);
t_texture	*find_texture(t_data *data);

////////////////////////////////////////////////////////////
// RAYCASTING
////////////////////////////////////////////////////////////
int			raycasting(t_data *data);

////////////////////////////////////////////////////////////
// RAYCATING UTILS
////////////////////////////////////////////////////////////
t_ray		init_ray_struct(t_player *player, float ray_angle);
void		calc_hit(t_data *data, t_ray *ray, char **map, int *side);
float		calc_wall_hit_x(t_ray *ray, int side, float dist);

////////////////////////////////////////////////////////////
// DRAW WALL
////////////////////////////////////////////////////////////
void		draw_wall(t_data *data, t_config *c, int i, float wall_height);

#endif