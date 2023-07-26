/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:07:19 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 17:40:01 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_bg(t_game *g, int *x, int *y)
{
	int	wx;
	int	wy;

	wx = g->wndw_size.x;
	wy = g->wndw_size.y;
	g->bg_imgs.img1 = mlx_xpm_file_to_image(g->mlx, "imgs/tree.xpm", x, y);
	g->bg_imgs.img2 = mlx_xpm_file_to_image(g->mlx, "imgs/fin.xpm", &wx, &wy);
	g->bg_imgs.img3 = mlx_xpm_file_to_image(g->mlx, "imgs/bg.xpm", &wx, &wy); 
	g->bg_imgs.img4 = mlx_xpm_file_to_image(g->mlx, "imgs/fail.xpm", &wx, &wy);
}

void	open_text(t_game *g, int *x, int *y)
{
	g->text_imgs.img1 = mlx_xpm_file_to_image(g->mlx, "imgs/tracker.xpm", x, y);
	g->text_imgs.img2 = mlx_xpm_file_to_image(g->mlx, "imgs/more.xpm", x, y);
	g->text_imgs.imgs[0] = mlx_xpm_file_to_image(g->mlx, "imgs/0.xpm", x, y);
	g->text_imgs.imgs[1] = mlx_xpm_file_to_image(g->mlx, "imgs/1.xpm", x, y);
	g->text_imgs.imgs[2] = mlx_xpm_file_to_image(g->mlx, "imgs/2.xpm", x, y);
	g->text_imgs.imgs[3] = mlx_xpm_file_to_image(g->mlx, "imgs/3.xpm", x, y);
	g->text_imgs.imgs[4] = mlx_xpm_file_to_image(g->mlx, "imgs/4.xpm", x, y);
	g->text_imgs.imgs[5] = mlx_xpm_file_to_image(g->mlx, "imgs/5.xpm", x, y);
	g->text_imgs.imgs[6] = mlx_xpm_file_to_image(g->mlx, "imgs/6.xpm", x, y);
	g->text_imgs.imgs[7] = mlx_xpm_file_to_image(g->mlx, "imgs/7.xpm", x, y);
	g->text_imgs.imgs[8] = mlx_xpm_file_to_image(g->mlx, "imgs/8.xpm", x, y);
	g->text_imgs.imgs[9] = mlx_xpm_file_to_image(g->mlx, "imgs/9.xpm", x, y);
}

void	open_collect(t_game *g, int *x, int *y)
{
	g->collect_imgs.img1 = mlx_xpm_file_to_image(g->mlx, "imgs/legs.xpm", x, y);
	g->collect_imgs.img2 = mlx_xpm_file_to_image(g->mlx, "imgs/lady.xpm", x, y);
	g->collect_imgs.img3 = mlx_xpm_file_to_image(g->mlx, "imgs/worm.xpm", x, y);
}

void	open_enemy(t_game *g, int *x, int *y)
{
	g->enemy_imgs.img1 = mlx_xpm_file_to_image(g->mlx, "imgs/snake1.xpm", x, y);
	g->enemy_imgs.img2 = mlx_xpm_file_to_image(g->mlx, "imgs/snake2.xpm", x, y);
}

/*This function calls mlx_xpm_file_to_image to open the images from xpm files. The function requires the height and width of the image to be given as a pointer. Note that if the image is not the same size as the values in the pointer then those values will be changed to match the image.*/

void	open_imgs(t_game *g)
{
	int	x;
	int	y;

	x = g->img_size.x;
	y = g->img_size.y;
	g->player_imgs.img1 = mlx_xpm_file_to_image(g->mlx, "imgs/bRd.xpm", &x, &y);
	g->player_imgs.img2 = mlx_xpm_file_to_image(g->mlx, "imgs/bRu.xpm", &x, &y);
	g->door_imgs.img1 = mlx_xpm_file_to_image(g->mlx, "imgs/nest.xpm", &x, &y);
	open_bg(g, &x, &y);
	open_collect(g, &x, &y);
	open_enemy(g, &x, &y);
	open_text(g, &x, &y);
}
