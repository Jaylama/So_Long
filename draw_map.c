/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:49:23 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 16:27:06 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks the tile type and displays a corresponding image. For collects a simple formula is used to display different images of bugs depending on the position on the map (whether the x or the y coordinate is even). For the player, an image of the bird with wings up or down is displayed depending on whether the move counter is odd or even.*/
void	draw_image(t_tile tile, t_game g)
{
	int	x;
	int	y;

	x = tile.x * IMG_SIZE;
	y = tile.y * IMG_SIZE;
	if (tile.type == '1')
		mlx_put_image_to_window(g.mlx, g.window, g.bg_imgs.img1, x, y);
	else if (tile.type == 'C' && tile.x % 2 == 0)
		mlx_put_image_to_window(g.mlx, g.window, g.collect_imgs.img1, x, y);
	else if (tile.type == 'C' && tile.y % 2 == 0)
		mlx_put_image_to_window(g.mlx, g.window, g.collect_imgs.img2, x, y);
	else if (tile.type == 'C')
		mlx_put_image_to_window(g.mlx, g.window, g.collect_imgs.img3, x, y);
	if (tile.type == 'P' && g.moves % 2 == 0)
		mlx_put_image_to_window(g.mlx, g.window, g.player_imgs.img1, x, y);
	else if (tile.type == 'P')
		mlx_put_image_to_window(g.mlx, g.window, g.player_imgs.img2, x, y);
	if (tile.type == 'E')
		mlx_put_image_to_window(g.mlx, g.window, g.door_imgs.img1, x, y);
	if (tile.type == 'H' && g.player.tile == NULL)
		mlx_put_image_to_window(g.mlx, g.window, g.enemy_imgs.img2, x, y);
	else if (tile.type == 'H')
		mlx_put_image_to_window(g.mlx, g.window, g.enemy_imgs.img1, x, y);
}

/*This function prints the counter. First it prints the heading of the counters. Then it prints the number of collects using an array of images for each number. Then it prints the number of moves, with the position varying depending on the number of digits. The function is limited to printing less than 100 moves and less than 10 collects.*/

int	draw_counter(t_game *g)
{
	int		i;
	int		x;
	int		y;
	t_image	txt;

	x = IMG_SIZE;
	y = g->wndw_size.y - 24;
	i = g->collects;
	txt = g->text_imgs;
	mlx_put_image_to_window(g->mlx, g->window, txt.img1, 1, y - 24);
	mlx_put_image_to_window(g->mlx, g->window, txt.imgs[i], x, y);
	i = g->moves;
	if (i < 0)
		i = 0;
	if (i < 10)
		mlx_put_image_to_window(g->mlx, g->window, txt.imgs[i], x * 3.5, y);
	if (i >= 10 && i < 100)
	{
		i = g->moves / 10;
		mlx_put_image_to_window(g->mlx, g->window, txt.imgs[i], x * 3.5, y);
		i = g->moves % 10;
		mlx_put_image_to_window(g->mlx, g->window, txt.imgs[i], x * 3.7, y);
	}
	return (0);
}

/*This function renders the map. First the previous window is cleared. Then for each tile, the draw_image function is called. Lastly draw_counter is called to display the number of moves and collects.*/

int	draw_map(t_game *g)
{
	int		y;
	int		x;
	t_tile	tile;

	mlx_clear_window(g->mlx, g->window);
	y = 0;
	while (g->tilemap[y])
	{
		x = 0;
		while (g->tilemap[y][x].type)
		{
			tile = g->tilemap[y][x];
			draw_image(tile, *g);
			x++;
		}
		y++;
	}
	draw_counter(g);
	return (0);
}
