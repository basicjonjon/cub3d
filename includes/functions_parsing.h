/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:26:05 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/17 15:57:37 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_PARSING_H
# define FUNCTIONS_PARSING_H

////////////////////////////////////////////////////////////
// verif_args
////////////////////////////////////////////////////////////

int			verif_args(int argc, char **argv);

////////////////////////////////////////////////////////////
// Texture
////////////////////////////////////////////////////////////

t_texture	*get_texture(char *maps_file);

////////////////////////////////////////////////////////////
// Texture_Init
////////////////////////////////////////////////////////////

t_texture	*init_texture_null(void);
t_texture	*get_texture_path(t_texture *texture, char *line);

void		print_texture_path(t_texture *texture);

#endif