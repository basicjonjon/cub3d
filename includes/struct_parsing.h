/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:31:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/17 16:28:06 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PARSING_H
# define STRUCT_PARSING_H

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_texture
{
	void	*no_wall;
	char	*no_path;
	void	*so_wall;
	char	*so_path;
	void	*we_wall;
	char	*we_path;
	void	*ea_wall;
	char	*ea_path;
	t_color	*ceiling;
	t_color	*floor;
}			t_texture;

#endif