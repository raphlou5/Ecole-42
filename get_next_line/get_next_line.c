/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:12 by elevast           #+#    #+#             */
/*   Updated: 2023/11/16 13:28:23 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buff_join(char *buffer, char *buffer2)
{
	char	*temp;

	temp = ft_strjoin(buffer, buffer2);
	free(buffer);
	return (temp);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
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
	line[i + 1] = '\0';
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!res)
		return (NULL);
	i++;
	while (buffer[i])
	{
		res[j++] = buffer[i++];
	}
	res[j] = '\0';
	free (buffer);
	return (res);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read < BUFFER_SIZE)
			buffer[bytes_read] = '\0';
		res = ft_buff_join(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	static_buffer = ft_read_file(fd, static_buffer);
	if (!static_buffer || *static_buffer == '\0')
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	line = ft_line(static_buffer);
	static_buffer = ft_next(static_buffer);
	return (line);
}
