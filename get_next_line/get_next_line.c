/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:12 by elevast           #+#    #+#             */
/*   Updated: 2023/11/28 15:31:30 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buff_join(char *global_buffer, char *local_buffer)
{
	size_t	len_global;
	size_t	len_local;
	char	*appended;
	size_t	i;
	size_t	j;

	if (!global_buffer || !local_buffer)
		return (NULL);
	len_global = ft_strlen(global_buffer);
	len_local = ft_strlen(local_buffer);
	appended = malloc((len_global + len_local + 1) * sizeof(char));
	if (!appended)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len_global)
		appended[i++] = global_buffer[j++];
	j = 0;
	while (j < len_local)
		appended[i++] = local_buffer[j++];
	appended[i] = '\0';
	free(global_buffer);
	return (appended);
}

char	*ft_line(char *global_buffer)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = 0;
	i = 0;
	if (!global_buffer[i])
		return (NULL);
	while (global_buffer[len] && global_buffer[len] != '\n')
		len++;
	line = malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = global_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next(char	*global_buffer)
{
	size_t	i;
	char	*new;
	size_t	j;

	i = 0;
	while (global_buffer[i] && global_buffer[i] != '\n')
		i++;
	if (!global_buffer[i])
	{
		free(global_buffer);
		return (NULL);
	}
	new = malloc(((ft_strlen(global_buffer) - i) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (global_buffer[i])
		new[j++] = global_buffer[i++];
	new[j] = '\0';
	free(global_buffer);
	return (new);
}

char	*ft_read_file(int fd, char *global_buffer)
{
	char	*buffer;
	int		bytes_rd;

	if (global_buffer == NULL)
		global_buffer = ft_calloc(1, sizeof(char));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_rd = 1;
	while (bytes_rd > 0)
	{
		bytes_rd = read(fd, buffer, BUFFER_SIZE);
		if (bytes_rd == -1 || (bytes_rd == 0 && global_buffer == NULL))
		{
			free(global_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_rd] = '\0';
		global_buffer = ft_buff_join(global_buffer, buffer);
		if (ft_strchr(global_buffer, '\n') == '\n')
			break ;
	}
	free(buffer);
	return (global_buffer);
}

char	*get_next_line(int fd)
{
	static char	*global_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	global_buffer = ft_read_file(fd, global_buffer);
	if (!global_buffer)
		return (NULL);
	line = ft_line(global_buffer);
	global_buffer = ft_next(global_buffer);
	return (line);
}

/*int main() {
    int fd;
    char *line;

    // Ouvre un fichier pour la lecture
    fd = open("exemple.txt", O_RDONLY);
    if (fd < 0) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    // Lecture et affichage des lignes
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    // Fermeture du fichier
    close(fd);

    return 0;
}*/