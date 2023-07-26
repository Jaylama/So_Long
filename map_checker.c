/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:57:39 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 16:59:57 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This function checks if the value is one of the valid chars for the map. It returns -1 if the player or exit character comes up more than once, indicating an error*/

int	valid_char(char *c, bool *p, bool *e)
{
	if ((*c == 'P' && *p == true) || (*c == 'E' && *e == true))
		return (-1);
	if (*c == '1' || *c == '0' || *c == 'C' || *c == 'E')
		return (1);
	if (*c == 'P' || *c == 'H')
		return (1);
	return (0);
}

int	valid_border(char c, t_vector point, t_vector size)
{
	if (c != '1')
	{
		if (point.y == 0 || point.x == 0)
			return (false);
		if (point.y == size.y - 1 || point.x == size.x - 1)
			return (false);
	}
	return (true);
}

t_mapcheck	init_checkdata(char **map)
{
	t_mapcheck	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = false;
	data.b_exit = false;
	data.b_collect = false;
	data.point.y = 0;
	data.point.x = 0;
	data.cpy_count = 0;
	return (data);
}

/*First this function calls the function valid_char to check if the point is a valid character. Then it sets the b_player, b_exit or b_collect values to true if it finds one of the representative characters. Finally it calls valid_border to check that all the points around the edge of the map are equal to '1'.*/

bool	checks(char **map, t_mapcheck *data)
{
	int	x;
	int	y;
	int	valid;

	x = data->point.x;
	y = data->point.y;
	valid = valid_char(&map[y][x], &data->b_player, &data->b_exit);
	if (!valid)
		return (error("invalid map character"));
	if (valid == -1)
		return (error("must be only one player 'P' and one exit 'E'"));
	if (map[y][x] == 'P')
		data->b_player = true;
	if (map[y][x] == 'E')
		data->b_exit = true;
	if (map[y][x] == 'C')
		data->b_collect = true;
	if (!valid_border(map[y][x], data->point, data->size))
		return (error("map must be surrounded by walls '1'"));
	return (true);
}

/*This function is used to check if the map is valid. The input is the map string. It first uses init_checkdata to set initial values in a struct containing the data needed for the checks. It iterates through the map array checking that the length of each row (using strlen) is equal to the length of the first row (data.size.x). If not then the map is not rectangular. For each point it calls the function checks(). It returns an error if a player, exit or collect point were not found. Then it calls valid_path and returns an error if it did not find a valid path.*/

int	valid_map(char **map)
{
	static t_mapcheck	data;
	bool				valid;

	data = init_checkdata(map);
	valid = true;
	while (map[data.point.y])
	{
		if (ft_strlen(map[data.point.y]) != data.size.x)
			valid = error("map must be rectangular");
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) != true)
				valid = false;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
		valid = error("there must be one 'P' and 'E', and at least one 'C'");
	if (valid == true && !valid_path(map, &data))
		valid = error("There is no valid path. Map cannot be solved\n");
	return (valid);
}
