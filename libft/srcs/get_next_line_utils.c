/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:26:34 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/28 13:18:12 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_gnl_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = -1;
	j = 0;
	if (!s2)
	{
		s2 = malloc(1);
		if (!s2)
			return (NULL);
		s2[0] = '\0';
	}
	if (!s1)
		return (ft_gnl_strdup(s2));
	res = malloc(sizeof(char) * ((ft_gnl_strlen(s1) + ft_gnl_strlen(s2)) + 1));
	if (res == NULL)
		return (free(s1), NULL);
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (free(s1), res);
}

char	*ft_gnl_strdup(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (ft_gnl_strlen(str) + 1));
	if (!res)
		return (0);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
