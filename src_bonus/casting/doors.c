/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:31:21 by mmarps            #+#    #+#             */
/*   Updated: 2025/08/18 19:51:53 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void toggle_door(t_data *data, int mapX, int mapY)
{
    if (data->param.map[mapY][mapX] == 'P')
    {
        if (data->door_progress[mapY][mapX] == 0.0f)
            data->door_progress[mapY][mapX] = 0.01f; // commencer ouverture
        else if (data->door_progress[mapY][mapX] == 1.0f)
            data->door_progress[mapY][mapX] = 0.99f; // commencer fermeture
    }
}

void update_doors(t_data *data, float delta_time)
{
    int x, y;

    y = 0;
    while (y < data->param.mapY)
    {
        x = 0;
        while (x < data->param.mapX)
        {
            if (data->param.map[y][x] == 'P')
            {
                float *p = &data->door_progress[y][x];

                // ouverture
                if (*p > 0.0f && *p < 1.0f)
                    *p += delta_time; 

                // clamp
                if (*p < 0.0f) *p = 0.0f;
                if (*p > 1.0f) *p = 1.0f;
            }
            x++;
        }
        y++;
    }
}

void draw_door(t_data *data, t_config *c, int i, float wall_height, float progress)
{
    int x, y, screen_x, start, end, color, tex_x;
    t_texture *texture;
    float offset;

    texture = &data->asset.door;

    start = (screenHeight / 2) - (wall_height / 2);
    if (start < 0) start = 0;
    end = (screenHeight / 2) + (wall_height / 2);
    if (end >= screenHeight) end = screenHeight - 1;

    // Décalage des battants
    offset = progress * 0.5f;

    if (data->hit.wall_hit_x < 0.5f)
        tex_x = (int)((data->hit.wall_hit_x + offset) * texture->tex_w);
    else
        tex_x = (int)((data->hit.wall_hit_x - offset) * texture->tex_w);

    if (tex_x < 0) tex_x = 0;
    if (tex_x >= texture->tex_w) tex_x = texture->tex_w - 1;

    x = 0;
    while (x < c->column_width)
    {
        screen_x = i * c->column_width + x;
        if (screen_x >= 0 && screen_x < screenWidth)
        {
            y = start;
            while (y++ < end)
            {
                int d = y * 256 - screenHeight * 128 + wall_height * 128;
                int tex_y = ((d * texture->tex_h) / (int)wall_height) / 256;
                color = get_texture_pixel(texture, tex_x, tex_y);
                ft_pixel_put(screen_x, y, &data->img, color);
            }
        }
        x++;
    }
}
