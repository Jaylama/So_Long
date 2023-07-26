/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tilemap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:41:41 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 16:16:35 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	**alloc_tilemap(char **map)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * ft_chartable_linecount(map) + 1);
	if (!tilemap)
		return (NULL);
	i = 0;
	while (map[i])
	{
		tilemap[i] = malloc(sizeof(t_tile) * ft_strlen(*map) + 1);
		if (!tilemap)
		{
			while (i)
				free(tilemap[--i]);
			return (NULL);
		}
		i++;
	}
	return (tilemap);
}

void	setup_tile(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].og_type = tilemap[y][x].type;
	tilemap[y][x].x = x;
	tilemap[y][x].y = y;
	if (y)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1])
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

void	set_gamevars(t_tile *tile, t_game *g)
{
	if (tile->type == 'P')
		g->player.tile = tile;
	else if (tile->type == 'C')
		g->collects++;
}

/* This function creates the tilemap array. First it calls alloc_tilemap to allocate memory, then it assigns the type variable using the value in the map array. Then it calls the setup tile function which assigns values to the variables in the t_tile struct. Then it calls set_gamevars to assign the player tile and number of collects to the game struct.*/

t_tile	**generate_tilemap(char **map, t_game *g)
{
	t_tile		**tilemap;
	int			x;
	int			y;

	tilemap = alloc_tilemap(map);
	if (!tilemap)
		return (null_error("malloc error on alloc_tilemap()"));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			tilemap[y][x].type = map[y][x];
			setup_tile(tilemap, x, y);
			set_gamevars(&tilemap[y][x], g);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] = NULL;
	g->wndw_size.x = x * IMG_SIZE;
	g->wndw_size.y = y * IMG_SIZE + 48;
	return (tilemap);
}
