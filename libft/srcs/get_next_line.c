/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:01:34 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/12/10 18:55:23 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*ft_join_and_free(char *buffer, char *tmp_buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, tmp_buf);
	if (!tmp)
		return (NULL);
	free(buffer);
	return (tmp);
}

static char	*ft_next_buf(char *buffer)
{
	char	*next_buf;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	next_buf = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!next_buf)
		return (NULL);
	j = 0;
	i++;
	if (!buffer[i] || buffer[i] == '\0')
		return (free(buffer), free(next_buf), NULL);
	while (buffer[i + j])
	{
		next_buf[j] = buffer[i + j];
		j++;
	}
	free(buffer);
	return (next_buf);
}

static char	*ft_put_in_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*tmp_buf;
	int		bytes_read;

	if (!buffer)
	{
		buffer = (char *)ft_calloc(1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	tmp_buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(tmp_buf), NULL);
		tmp_buf[bytes_read] = '\0';
		buffer = ft_join_and_free(buffer, tmp_buf);
		if (!buffer)
			break ;
	}
	free(tmp_buf);
	return (buffer);
}

char	*get_next_line(int fd, bool tofree)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (tofree)
		return (free(buffer[fd]), NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_put_in_line(buffer[fd]);
	if (!line || line[0] == '\0')
	{
		free(buffer[fd]);
		free(line);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_next_buf(buffer[fd]);
	return (line);
}
