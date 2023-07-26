/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:17:55 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 17:50:03 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_linecount(int fd)
{
	int		lines;
	int		chars;
	char	c;

	lines = 1;
	while (1)
	{
		chars = read(fd, &c, 1);
		if (!chars)
			break ;
		if (chars < 0)
			return (-1);
		if (c == '\n')
			lines++;
	}
	return (lines);
}

char	**alloc_columns(int fd)
{
	char	**map;
	int		lines;

	lines = file_linecount(fd);
	if (lines <= 0)
		return (null_error("open or read error, file may not exist"));
	map = malloc(sizeof(char *) * lines + 1);
	if (!map)
		return (null_error("malloc error on alloc_map()"));
	return (map);
}

/*This function reads the .ber file and copies the data into the map variable. It first uses alloc_columns, to count the number of lines in the file and allocate memory accordingly. Then it calls get next line for each row, which uses the read function to copy the data from the .ber file into the array. */

char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		return (null_error("fd error"));
	map = alloc_columns(fd);
	if (!map)
		return (NULL);
	i = 0;
	fd = open(file, O_RDONLY);
	while (map[i])
	{
		map[i] = get_next_line(fd, map[i]);
		map[i] = ft_strtrim(map[i], "\n");
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
