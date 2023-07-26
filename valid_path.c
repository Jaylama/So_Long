/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:06:06 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 18:01:52 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function fills the map with zeros starting with the y and x coordinates (the player position), and using recursion to increment along the y and x axis. As it goes it counts the number of collects and exit points (as these are places the player should be able to move). If at the end the number of 'C' and 'E's found is not equal to the number in the entire map, then it means there are some parts of the map that are inaccessible.*/

void	flood_fill(char	**copy, t_mapcheck *data, int y, int x)
{
	if (copy[y][x] == '1' || copy[y][x] == 'H' || copy[y][x] == 'P')
		return ;
	if (copy[y][x] == 'C' || copy[y][x] == 'E')
	{
		data->cpy_count++;
		copy[y][x] = '0';
	}
	if (copy[y][x] == '0')
	{
		copy[y][x] = 'P';
		flood_fill(copy, data, (y + 1), x);
		flood_fill(copy, data, (y - 1), x);
		flood_fill(copy, data, y, (x + 1));
		flood_fill(copy, data, y, (x - 1));
		return ;
	}
}

int	fill_copy(char **map, char **copy, t_mapcheck *data)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			copy[y][x] = map[y][x];
			if (map[y][x] == 'C' || map[y][x] == 'E')
				count++;
			if (map[y][x] == 'P')
			{
				data->point.x = x;
				data->point.y = y;
				copy[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (count);
}

/*First this function creates an array of strings to copy the map variable into and assigns the required memory. Then it calls fill_copy to copy each point individually. The variable p stores the player position o n the map which is the start point for flood_fill. */

int	valid_path(char **map, t_mapcheck *data)
{
	char		**copy;
	int			y;
	int			count;
	t_vector	p;

	count = 0;
	y = 0;
	copy = malloc(sizeof(char *) * ft_chartable_linecount(map));
	while (y < ft_chartable_linecount(map))
		copy[y++] = malloc(sizeof(char) * ft_strlen(map[0]) + 1);
	count = fill_copy(map, copy, data);
	p = data->point;
	flood_fill(copy, data, p.y, p.x);
	ft_free_chartable(copy);
	if (count != data->cpy_count)
		return (0);
	else
		return (1);
}
