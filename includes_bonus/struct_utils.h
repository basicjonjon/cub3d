/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:23:15 by mmarps            #+#    #+#             */
/*   Updated: 2025/08/21 00:34:02 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_UTILS_H
# define STRUCT_UTILS_H

# include <stdbool.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_fpoint
{
	float	x;
	float	y;
}			t_fpoint;

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	CLOSE_DOOR
}	t_dir;

typedef struct s_draw
{
	int		i;
	int		start;
	int		end;
	float	height;
}			t_draw;

typedef struct s_floor_data
{
	int			cell_x;
	int			cell_y;
	int			tx;
	int			ty;
	int			floor_color;
	int			ceil_color;
	t_fpoint	floor;
	float		floor_step_x;
	float		floor_step_y;
}	t_floor_data;

typedef struct s_raydir
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
}	t_raydir;

typedef struct s_ray
{
	float	pos_x;
	float	pos_y;
	int		map_x;
	int		map_y;
	float	raydir_x;
	float	raydir_y;
	float	deltadist_x;
	float	deltadist_y;
	int		step_x;
	int		step_y;
	float	sidedist_x;
	float	sidedist_y;
}				t_ray;

typedef struct s_hit_info
{
	t_dir		wall_dir;
	float		wall_hit_x;
	float		perpwalldist;
	int			tex_x;
	int			tex_y;
	bool		door_flg;
}				t_hit;

#endif