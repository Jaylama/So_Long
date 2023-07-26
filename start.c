/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:07 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/05 15:20:19 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("no args"));
	if (!ft_strend_cmp(file, ".ber"))
		return (error("map should be a .ber file"));
	return (1);
}

/* This function first calls valid_file (above) to check that the map is a .ber file. Then it defines the map variable as the result of the read_map function. It then checks that the map is valid, and generates the tilemap, which is a string of t_tile variables. */

t_tile	**map_init(int ac, char *av, t_game *g)
{
	char	**map;
	t_tile	**tilemap;

	if (!valid_file(ac, av))
		return (NULL);
	map = read_map(av);
	if (!*map || !map)
		return (NULL);
	if (valid_map(map) == false)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, g);
	g->map = map;
	if (!tilemap)
		return (NULL);
	printf("tilemap valid\n\n");
	return (tilemap);
}

/* This function takes in the parameters of the game struct, number of args and the arg string. It then sets some variables to initial values and calls the map_init function (above).*/

bool	start(t_game *g, int ac, char *av)
{
	g->collects = 0;
	g->moves = -1;
	printf("initialising map\n");
	g->tilemap = map_init(ac, av, g);
	if (!g->tilemap)
		return (false);
	g->og_collects = g->collects;
	return (true);
}
