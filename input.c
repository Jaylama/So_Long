/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:54:31 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 16:47:01 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_player(t_game *g)
{
	g->player.tile->type = '0';
	g->player.tile = NULL;
}

/* This function is called if the player has moved to the enemy or exit. If the game is over, the screen for winning the game or dying is displayed using mlx_put_image_to_window. Then remove player is called. Mlx_loop is called to continue the display until a hook occurs. If the player has landed on the exit but hasn't collected all the bugs then a message is printed to the window saying they need to collect more*/

bool	move_end(t_game *g, t_tile *tile)
{
	int y;
	int	x;
	int	z;

	z = (g->wndw_size.y - 600) / 2;
	x = IMG_SIZE * 5;
	y = g->wndw_size.y - 56;
	if ((tile->type == 'E' && g->collects <= 0) || tile->type == 'H')
	{
		mlx_clear_window(g->mlx, g->window);
		if (tile->type == 'E')
			mlx_put_image_to_window(g->mlx, g->window, g->bg_imgs.img2, 0, z);
		else
			mlx_put_image_to_window(g->mlx, g->window, g->bg_imgs.img4, 0, z);
		remove_player(g);
		mlx_loop(g->mlx);
	}
	else if (tile->type == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->window, g->text_imgs.img2, x, y);
		mlx_loop(g->mlx);
	}
	return (false);
}

/* This function takes the player tile as input and changes it's value to the up, down, left or right variables depending on the keypress. If the tile type is C it sets the type to empty and decrements the number of collects. If it is E or H (exit or enemy), it calls the move end function. It sets the tile type to 'P' (player), and sets the previous player tile to empty.*/

bool	move_to(int key, t_game *g, t_tile *tile)
{
	if (key == KEY_W)
		tile = tile->up;
	if (key == KEY_S)
		tile = tile->down;
	if (key == KEY_A)
		tile = tile->left;
	if (key == KEY_D)
		tile = tile->right;
	if (tile->type != '1')
	{
		if (tile->type == 'C')
		{
			tile->type = '0';
			g->collects--;
		}
		if (tile->type == 'E' || tile->type == 'H')
			move_end(g, tile);
		tile->type = 'P';
		g->player.tile->type = '0';
		g->player.tile = tile;
	}
	return (true);
}

/* This function checks if the key A or D has been pressed, and if so the player image is destroyed and replaced with an image of the bird facing the other direction.*/

void	player_direction(int key, t_game *g)
{
	int	i;
	int	*p;

	i = 96;
	p = &i;
	if (key == KEY_A || key == KEY_D)
	{
		mlx_destroy_image(g->mlx, g->player_imgs.img1);
		mlx_destroy_image(g->mlx, g->player_imgs.img2);
	}
	if (key == KEY_A)
	{
		g->player_imgs.img1 = mlx_xpm_file_to_image(g->mlx, "imgs/bLd.xpm", p, p);
		g->player_imgs.img2 = mlx_xpm_file_to_image(g->mlx, "imgs/bLu.xpm", p, p);
	}
	if (key == KEY_D)
	{	
		g->player_imgs.img1 = mlx_xpm_file_to_image(g->mlx, "imgs/bRd.xpm", p, p);
		g->player_imgs.img2 = mlx_xpm_file_to_image(g->mlx, "imgs/bRu.xpm", p, p);
	}
}

/* This function processes the input from the keyboard. First it increments the movement counter to zero (it starts at -1 when the game is at the intro screen), and calls draw_map to render the map. Then if one of the keys WASD are pressed the move_to function is called and returns a bool value to record whether the player moved. Then player_direction is called to change the direction the sprite is facing. Finally it renders the map again.*/

int	input(int key, t_game *g)
{
	bool	moved;

	if (key == KEY_ESC)
		end_pgrm(g);
	else if (key == KEY_R)
		return (reset(g));
	if (g->player.tile == NULL)
		return (0);
	if (g->moves == -1)
	{
		g->moves++;
		draw_map(g);
		return (0);
	}
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
	{
		moved = move_to(key, g, g->player.tile);
		player_direction(key, g);
	}
	else
		return (0);
	if (moved == true)
		g->moves++;
	draw_map(g);
	return (1);
}
