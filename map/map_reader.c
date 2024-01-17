/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:25:48 by elevast           #+#    #+#             */
/*   Updated: 2024/01/17 15:13:43 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "map.h"

static int file_linecount(char *file)
{
    int linecount;
    int fd;
    int readcount;
    char c;    

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return -1;
    
    linecount = 1;
    while (TRUE)
    {
        readcount = read(fd, &c, 1);
        if (readcount == 0)
            break;
        if (readcount < 0)
        {
            close(fd);
            return -1;
        }
        if (c == '\n')
            linecount++;
    }

    close(fd);
    return linecount;
}



static char	**alloc_columns(char *file)
{
	char	**map;
	int		line_count;

	line_count = file_linecount(file);
	if (line_count <= 0) {
		printf("open or reading error, the file may not exist\n");
		return (NULL);
	}

	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL) {
		printf("malloc error on alloc_map()\n");
		return (NULL);
	}

	return (map);
}


char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_columns(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while ((map[i] = get_next_line(fd)) != NULL)
        i++;
	map[i] = NULL;
	close(fd);
	return (map);
}

int main()
{
    char *file = "map_0.ber";
    char **map = read_map(file);
    int j = 0;
    while (map[j] != NULL)
    {
        free(map[j]);
        j++;
    }
    free(map);

    return 0;
}