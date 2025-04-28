/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:25:36 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/28 13:17:28 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read(fd, buff);
	if (!buff || *buff == '\0')
		return (NULL);
	line = ft_cut_line(buff);
	buff = ft_start_next_line(buff);
	return (line);
}

char	*ft_read(int fd, char *res)
{
	int		byte_c;
	char	*buff;

	byte_c = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_gnl_strchr(res, '\n') && byte_c != 0)
	{
		byte_c = read(fd, buff, BUFFER_SIZE);
		if (byte_c == -1)
			return (free(buff), free(res), NULL);
		if (byte_c == 0)
			return (free(buff), res);
		buff[byte_c] = '\0';
		res = ft_gnl_strjoin(res, buff);
		if (!res)
			return (free(buff), NULL);
	}
	return (free(buff), res);
}

char	*ft_cut_line(char *res)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!res)
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		line = malloc((i + 2) * sizeof(char));
	else
		line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (res[i] != '\n' && res[i])
		line[j++] = res[i++];
	if (res[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_start_next_line(char *res)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!res && res[i] == '\0')
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\0')
		return (free(res), NULL);
	i++;
	str = malloc((ft_gnl_strlen(res) - i + 1) * sizeof(char));
	if (!str)
		return (free(res), NULL);
	while (res[i])
		str[j++] = res[i++];
	str[j] = '\0';
	free(res);
	if (str[0] == '\0')
		return (free(str), NULL);
	return (str);
}
