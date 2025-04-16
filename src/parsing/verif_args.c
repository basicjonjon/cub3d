/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:04:39 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/16 16:09:29 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_args(int argc)
{
	if (argc < 2)
	{
		ft_fprintf(2, "%sERROR: %i:not enougth param%s\n", BRED, argc - 1, NC);
		return (1);
	}
	if (argc > 2)
	{
		ft_fprintf(2, "%sERROR: %i:too much param%s\n", BRED, argc - 1, NC);
		return (1);
	}
	return (0);
}

int	verif_extention_file(char *s, char *ext)
{
	int	ext_size;
	int	s_size;
	int	i;

	i = 0;
	if (!s || !ext)
		return (1);
	ext_size = ft_strlen(ext) - 1;
	s_size = ft_strlen(s) - 1;
	while (i < ext_size)
	{
		if (s[s_size - i] != ext[ext_size - i])
		{
			ft_fprintf(2, "%sERROR: need .cub extention file%s\n", BRED, NC);
			return (1);
		}
		i++;
	}
	return (0);
}

int	verif_args(int argc, char **argv)
{
	int fd;
	if (count_args(argc))
		return (1);
	if (verif_extention_file(argv[1], ".cub"))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_fprintf(2, "%sERROR: %s: invalide file%s\n", BRED, argv[1], NC);
	return (0);
}