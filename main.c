/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:45:23 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 16:58:26 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	g;
	char	*name;
	int	y;

	name = "So long and thank for all the bugs";
	if (!start(&g, argc, argv[1]))
		return (0);
	y = (g.wndw_size.y - 600) / 2;	
	g.mlx = mlx_init();
	g.window = mlx_new_window(g.mlx, g.wndw_size.x, g.wndw_size.y, name);
	open_imgs(&g);
	mlx_hook(g.window, 17, 0, end_pgrm, &g);
	mlx_hook(g.window, 2, 1L << 0, input, &g);
	mlx_put_image_to_window(g.mlx, g.window, g.bg_imgs.img3, 0, y);
	mlx_loop(g.mlx);
	mlx_destroy_image(g.mlx, g.bg_imgs.img3);
	draw_map(&g);
	mlx_loop(g.mlx);
	ft_free_chartable(g.map);
	mlx_destroy_window(g.mlx, g.window);
	free(g.mlx);
	return (0);
}
