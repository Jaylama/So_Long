/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_pgrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:38:17 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/05 14:38:35 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tilemap(t_game *g)
{
	t_tile	**tilemap;

	tilemap = g->tilemap;
	while (*tilemap)
	{
		free(*tilemap);
		tilemap++;
	}
	free(g->tilemap);
	g->tilemap = NULL;
}

/* This function resets the game by setting each square in the tilemap to it's original value, which was stored in the tilemap struct. Then it sets the number of moves to zero and calls draw_map.*/

int	reset(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->tilemap[y])
	{
		x = 0;
		while (g->tilemap[y][x].type)
		{
			g->tilemap[y][x].type = g->tilemap[y][x].og_type;
			if (g->tilemap[y][x].type == 'P')
				g->player.tile = &g->tilemap[y][x];
			x++;
		}
		y++;
	}
	g->collects = g->og_collects;
	g->moves = 0;
	draw_map(g);
	return (0);
}

int	end_pgrm(t_game *g)
{
	free_tilemap(g);
	printf("Artist Credits:\nj4p4n & Jordan Irwin (AntumDeluge)\nMaster484 - https://opengameart.org/users/master484\nAdmurin - https://admurin.itch.io\nBlarumyrran, Bart, and Surt\nThe Ness, various and Ivan Voirol on OpenGameArt\n");
	exit(0);
}
