/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanson <jmanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:34:58 by jmanson           #+#    #+#             */
/*   Updated: 2023/07/19 17:44:04 by jmanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 96

# include "GNL/get_next_line.h"
# include "LIBFT/libft.h"
# include "mlx/mlx.h"
# include "structs.h"
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//INIT
bool		start(t_game *g, int ac, char *av);
t_tile		**map_init(int ac, char *av, t_game *g);
char		**read_map(char *file);

//FILE CHECKS
int			valid_map(char **map);
int			valid_file(int argc, char *file);
bool		checks(char **map, t_mapcheck *data);
t_mapcheck	init_checkdata(char **map);
int			valid_border(char c, t_vector point, t_vector size);
int			valid_char(char *c, bool *p, bool *e);
int			valid_path(char **map, t_mapcheck *data);
void		flood_fill(char **copy, t_mapcheck *data, int y, int x);

//MAP
t_tile		**generate_tilemap(char **map, t_game *g);
void		set_gamevars(t_tile *tile, t_game *g);
void		setup_tile(t_tile **tilemap, int x, int y);
t_tile		**alloc_tilemap(char **map);
int			file_linecount(int fd);
char		**alloc_columns(int fd);

//GAME
void		game_init(t_game *g);
void		new_panel(t_game *g);
void		open_imgs(t_game *g);
void		open_door(t_game *g, int *x, int *y);
void		open_enemy(t_game *g, int *x, int *y);
void		open_collect(t_game *g, int *x, int *y);
int			draw_map(t_game *g);
void		draw_image(t_tile tile, t_game g);
int			enter(t_game *g);
int			input(int key, t_game *g);
bool		move_to(int key, t_game *g, t_tile *tile);

//EXIT
int			end_pgrm(t_game *g);
void		free_tilemap(t_game *g);
int			reset(t_game *g);
void		remove_player(t_game *g);

//ERRORS
void		print_warning(char *message);
void		*null_error(char *message);
int			error(char *message);

#endif
