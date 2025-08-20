/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_raycast_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:26:03 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/20 22:29:38 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_RAYCAST_BONUS_H
# define FUNCTIONS_RAYCAST_BONUS_H

////////////////////////////////////////////////////////////
// HOOKS
////////////////////////////////////////////////////////////
void	hooks(t_data *data);

////////////////////////////////////////////////////////////
// MOVEMENT
////////////////////////////////////////////////////////////
int		move_player(t_data *data, t_player *player, t_config *c);

////////////////////////////////////////////////////////////
// MOVEMENT UTILS
////////////////////////////////////////////////////////////
void	move_forward_backward(t_data *d, t_player *p, float speed);
void	move_strafe(t_data *d, t_player *p, float speed);
void	rotate_player(t_player *p, t_config *c);
void	rotate_with_mouse(t_data *d, t_player *p);

////////////////////////////////////////////////////////////
// UTILS
////////////////////////////////////////////////////////////
void	ft_pixel_put(int x, int y, t_img *img, int color);
int		get_texture_pixel(t_texture *texture, int x, int y);
int		check_colision(float x, float y, t_map *m);
void	clear_image(t_img *img, int width, int height);

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
t_ray	init_ray_dir(t_player *player, float rayDirX, float rayDirY);

////////////////////////////////////////////////////////////
// DRAW FLOOR AND CEILING
////////////////////////////////////////////////////////////
void	draw_floor_ceiling(t_data *data);
void	cast_floor(t_img *img, int color);
void	cast_ceiling(t_img *img, int color);

////////////////////////////////////////////////////////////
// MINIMAP
////////////////////////////////////////////////////////////
void	draw_minimap(t_data *data);

////////////////////////////////////////////////////////////
// MINIMAP
////////////////////////////////////////////////////////////
int	blend_color(int c1, int c2, float t);
int	apply_fog(int color, float dist, float density, int fog_color);

////////////////////////////////////////////////////////////
// MINIMAP UTILS
////////////////////////////////////////////////////////////
void	draw_line(t_img *img, t_point *a, t_point *b, int color);
void	draw_square(t_img *img, t_point *a, int size, int color);
int	get_minimap_scale(t_data *data);



#endif